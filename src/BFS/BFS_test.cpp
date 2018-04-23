#include <iostream>
#include "BFS/BFS.h"

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
    BFS c;
    std::vector<std::pair<int, int> > path = c.search(world_state, a, b);

    for(const auto& p : path)
        std::cout << p.first << ' ' << p.second << '\n';

    return 0;
}

