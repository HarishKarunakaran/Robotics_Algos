#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>

class DFS{
    typedef std::pair<int, int> position;
public:
    DFS();
    std::map<position, std::vector<position> > compute_map(std::vector<std::vector<int> >&);
    double heuristic(position, position);
    std::vector<position > search(std::vector<std::vector<int> >&, position& , position&);
    ~DFS();
};

