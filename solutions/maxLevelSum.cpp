#include <unordered_map>
#include <utility>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        // Maintains a pair representing the level and value of each node
        unordered_map<int, int> level_values;

        level_values[1] = root->val;
        if (root->left != nullptr)
        {
            populateValuations(level_values, 2, root->left);
        }
        if (root->right != nullptr)
        {
            populateValuations(level_values, 2, root->right);
        }

        int largest_level = 1;

        for (pair<int, int> level : level_values)
        {
            largest_level = level.second > level_values[largest_level] ? level.first : largest_level;
        }

        return largest_level;
    }

    void populateValuations(unordered_map<int, int> &level_values,
                            int level,
                            TreeNode *current_node)
    {
        level_values[level] += current_node->val;

        if (current_node->left != nullptr)
        {
            populateValuations(level_values, level + 1, current_node->left);
        }
        if (current_node->right != nullptr)
        {
            populateValuations(level_values, level + 1, current_node->right);
        }
    }
};