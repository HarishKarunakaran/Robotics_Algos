#include<limits>
#include<queue>
#include<algorithm>
#include "ARA*/arastar.h"

ARAstar::ARAstar()
{

}

std::map<ARAstar::position, std::vector<ARAstar::position> > ARAstar::compute_map(std::vector<std::vector<int> >& world_state)
{
    std::map<ARAstar::position, std::vector<ARAstar::position> > m;

    for(int i = 0; i < int(world_state.size()); ++i){
        for(int j = 0; j < int(world_state.at(0).size()); ++j){

            std::vector<ARAstar::position> adj;

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

std::vector<ARAstar::position> ARAstar::search(std::vector<std::vector<int> >& env, ARAstar::position& start, ARAstar::position& goal)
{
    std::map<ARAstar::position, std::vector<ARAstar::position > > map = compute_map(env);
    std::map<ARAstar::position, ARAstar::position > came_from;
    std::map<ARAstar::position, double> cost_so_far;

    PriorityQueue<ARAstar::position, double> frontier;
    frontier.push(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        ARAstar::position current = frontier.get();

        if (current == goal)
        {
          break;
        }

        auto search = map.find(current);

        for (ARAstar::position next : search->second)
        {
            double new_cost = cost_so_far[current] + 1;
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) // cannot find next or new_cost less than cost_so_far
            {
                cost_so_far[next] = new_cost;
                double priority = new_cost + heuristic(next, goal);
                frontier.push(next, priority);
                came_from[next] = current;
            }
        }
    }

    std::vector<ARAstar::position > path;
    ARAstar::position current = goal;
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

double ARAstar::heuristic(ARAstar::position state1, ARAstar::position state2)
{
    double dist = std::sqrt(std::pow((state1.first - state2.first), 2) + std::pow((state1.second - state2.second), 2));
    return dist;
}

ARAstar::~ARAstar()
{

}


