#include <vector>
#include <set>
#include <deque>
#include <utility>

using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int distance = -1;
        set<pair<int, int>> visited_nodes;
        deque<pair<int, int>> search_queue;

        pair<int, int> destination = make_pair(grid.size() - 1, grid.size() - 1);
        pair<int, int> current_node;
        int path_len = 0;
        vector<pair<int, int>> directions = {{-1, -1},
                                             {-1, 0},
                                             {-1, 1},
                                             {0, -1},
                                             {0, 1},
                                             {1, -1},
                                             {1, 0},
                                             {1, 1}};
        auto make_new_neighbors = [&](const pair<int, int> &node)
        {
            vector<pair<int, int>> neighbors;
            for (auto &dir : directions)
            {
                pair<size_t, size_t> neighbor = make_pair(dir.first + node.first, dir.second + node.second);
                bool is_inbound = neighbor.first >= 0 &&
                                  neighbor.second >= 0 &&
                                  neighbor.first < grid.size() &&
                                  neighbor.second < grid.size();
                if (is_inbound &&
                    visited_nodes.find(neighbor) == visited_nodes.end() &&
                    grid[neighbor.first][neighbor.second] == 0)
                {
                    neighbors.push_back(neighbor);
                    visited_nodes.insert(neighbor);
                }
            }
            return neighbors;
        };

        search_queue.push_front(make_pair(0, 0));
        visited_nodes.insert(make_pair(0, 0));
        while (grid[0][0] != 1 && search_queue.size() > 0 && distance == -1)
        {
            vector<pair<int, int>> neighbors;
            while (search_queue.size() > 0)
            {
                current_node = search_queue.front();
                search_queue.pop_front();
                auto new_neighbors = make_new_neighbors(current_node);
                for (auto &neighbor : new_neighbors)
                {
                    if (neighbor == destination)
                    {
                        distance = path_len + 2;
                    }
                    neighbors.push_back(neighbor);
                }
            }
            search_queue.insert(search_queue.end(), neighbors.begin(), neighbors.end());
            path_len++;
        }
        return distance;
    }
};