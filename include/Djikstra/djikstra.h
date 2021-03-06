#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

class Djikstra{
    typedef std::pair<int, int> position;
public:
    Djikstra();
    std::map<position, std::vector<position> > compute_map(std::vector<std::vector<int> >&);
    double heuristic(position, position);
    std::vector<position > search(std::vector<std::vector<int> >&, position& , position&);
    ~Djikstra();
};

template<typename T, typename priority_t>
struct PriorityQueue {
  typedef std::pair<priority_t, T> PQElement;
  std::priority_queue<PQElement, std::vector<PQElement>,
                 std::greater<PQElement>> elements;

  inline bool empty() const {
     return elements.empty();
  }

  inline void push(T item, priority_t priority) {
    elements.emplace(priority, item);
  }

  T get() {
    T best_item = elements.top().second;
    elements.pop();
    return best_item;
  }
};
