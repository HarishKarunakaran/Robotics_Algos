#include <limits>
#include <queue>
#include <algorithm>
#include "DFS/DFS.h"

DFS::DFS()
{

}

std::map<DFS::position, std::vector<DFS::position> > DFS::compute_map(std::vector<std::vector<int> >& world_state)
{
    std::map<DFS::position, std::vector<DFS::position> > m;

    for(int i = 0; i < int(world_state.size()); ++i){
        for(int j = 0; j < int(world_state.at(0).size()); ++j){

            std::vector<DFS::position> adj;

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

std::vector<DFS::position> DFS::search(std::vector<std::vector<int> >& env, DFS::position& start, DFS::position& goal)
{
    std::map<DFS::position, std::vector<DFS::position > > map = compute_map(env);
    std::map<DFS::position, DFS::position> came_from;

    std::stack<DFS::position> frontier;
    frontier.push(start);

    came_from[start] = start;

    while (!frontier.empty())
    {
        DFS::position current = frontier.top();
        frontier.pop();

        if (current == goal)
        {
          break;
        }

        auto search = map.find(current);

        for (DFS::position next : search->second)
        {
            if (came_from.find(next) == came_from.end()) // cannot find next
            {
                frontier.push(next);
                came_from[next] = current;
            }
        }
    }

    std::vector<DFS::position> path;
    DFS::position current = goal;
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

double DFS::heuristic(DFS::position state1, DFS::position state2)
{
    double dist = std::sqrt(std::pow((state1.first - state2.first), 2) + std::pow((state1.second - state2.second), 2));
    return dist;
}

DFS::~DFS()
{

}


