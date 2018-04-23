#include <limits>
#include <queue>
#include <algorithm>
#include "BFS/BFS.h"

BFS::BFS()
{

}

std::map<BFS::position, std::vector<BFS::position> > BFS::compute_map(std::vector<std::vector<int> >& world_state)
{
    std::map<BFS::position, std::vector<BFS::position> > m;

    for(int i = 0; i < int(world_state.size()); ++i){
        for(int j = 0; j < int(world_state.at(0).size()); ++j){

            std::vector<BFS::position> adj;

            if((j - 1) >= 0 && world_state.at(i).at(j-1) == 0){
                adj.push_back(std::make_pair(i, j - 1));
            }

            if((i + 1) < int(world_state.size()) && world_state.at(i + 1).at(j) == 0){
                adj.push_back(std::make_pair(i + 1, j));
            }

            if((j + 1) < int(world_state.at(i).size()) && world_state.at(i).at(j + 1) == 0){
                adj.push_back(std::make_pair(i, j + 1));
            }

            if((i - 1) >= 0 && world_state.at(i - 1).at(j) == 0)
                adj.push_back(std::make_pair(i - 1, j));

            if(world_state.at(i).at(j) == 1)
                adj.clear();

            m.emplace(std::make_pair(i, j), adj);
            adj.clear();
        }
    }
    for (const auto &p : m)
    {
        std::cout << "Node : " << p.first.first << ',' << p.first.second << '\t';
        for(int j = 0; j < int((p.second).size()); ++j)
            std::cout << (p.second)[j].first << ',' << (p.second)[j].second << "  ";
        std::cout << '\n';
    }

    return m;
}

std::vector<BFS::position> BFS::search(std::vector<std::vector<int> >& env, BFS::position& start, BFS::position& goal)
{
    std::map<BFS::position, std::vector<BFS::position > > map = compute_map(env);
    std::map<BFS::position, BFS::position> came_from;

    std::queue<BFS::position> frontier;
    frontier.push(start);

    came_from[start] = start;

    while (!frontier.empty())
    {
        BFS::position current = frontier.front();
        frontier.pop();

        if (current == goal)
        {
          break;
        }

        auto search = map.find(current);

        for (BFS::position next : search->second)
        {
            if (came_from.find(next) == came_from.end()) // cannot find next
            {
                frontier.push(next);
                came_from[next] = current;
            }
        }
    }

    std::vector<BFS::position> path;
    BFS::position current = goal;
    while (current != start)
    {
        path.push_back(current);
        current = came_from[current];
    }

    path.push_back(start);

    if((std::abs(path.at(0).first - path.at(1).first) > 1) || (std::abs(path.at(0).second - path.at(1).second) > 1))
    {
        path.clear();
        std::cout << "No path found to goal node \n";
        return path;
    }
    std::reverse(path.begin(), path.end());
    return path;
}

double BFS::heuristic(BFS::position state1, BFS::position state2)
{
    double dist = std::sqrt(std::pow((state1.first - state2.first), 2) + std::pow((state1.second - state2.second), 2));
    return dist;
}

BFS::~BFS()
{

}


