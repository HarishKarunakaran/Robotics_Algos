#include <iostream>
#include "astar.h"
#include "random.h"

int main()
{
    std::vector<std::vector<int> > world_state = {{0, 0, 1, 0, 0, 0},
                                                  {0, 0, 1, 0, 0, 0},
                                                  {0, 0, 0, 0, 1, 0},
                                                  {0, 0, 1, 1, 1, 0},
                                                  {0, 0, 1, 0, 1, 0},
                                                  {0, 0, 0, 0, 0, 0}};
    std::pair<int, int> a = {2, 0};
    std::pair<int, int> b = {5, 5};
//    Astar c;
//    std::vector<std::pair<int, int> > path = c.search(world_state, a, b);

//    for(const auto& p : path)
//        std::cout << p.first << ' ' << p.second << '\n';

    std::vector<std::pair<int, int> > path;
    Random d(1000);
    path = d.search(world_state, a, b);

    for(const auto& p : path)
            std::cout << p.first << ' ' << p.second << '\n';

    return 0;
}

