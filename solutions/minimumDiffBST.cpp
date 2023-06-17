#include <cstdlib>

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
    TreeNode *getLargestSubNode(TreeNode *root)
    {
        TreeNode *largest;
        if (root->right != nullptr)
        {
            largest = getLargestSubNode(root->right);
        }
        else
        {
            largest = root;
        }
        return largest;
    }

    TreeNode *getSmallestSubNode(TreeNode *root)
    {
        TreeNode *smallest;
        if (root->left != nullptr)
        {
            smallest = getSmallestSubNode(root->left);
        }
        else
        {
            smallest = root;
        }
        return smallest;
    }

    int giveSmallerPositiveNumber(int val1, int val2)
    {
        int smaller = -1;
        if (!(val1 < 0) && !(val2 < 0))
        {
            smaller = (val1 < val2) ? val1 : val2;
        }
        else if (val1 < 0)
        {
            smaller = val2;
        }
        else
        {
            smaller = val1;
        }
        return smaller;
    }

    int getMinimumDifference(TreeNode *root)
    {
        int left_diff = -1;
        int right_diff = -1;
        int min_diff = -1;

        if (root->left != nullptr)
        {
            int left_subtree_min = getMinimumDifference(root->left);
            TreeNode *largest_smaller_value_node = getLargestSubNode(root->left);
            int left_immediate_min = largest_smaller_value_node != nullptr ? root->val - largest_smaller_value_node->val : -1;
            left_diff = giveSmallerPositiveNumber(left_subtree_min, left_immediate_min);
        }

        if (root->right != nullptr)
        {
            int right_subtree_min = getMinimumDifference(root->right);
            TreeNode *smallest_larger_value_node = getSmallestSubNode(root->right);
            int right_immediate_min = getSmallestSubNode(root->right)->val - root->val;
            right_diff = giveSmallerPositiveNumber(right_subtree_min, right_immediate_min);
        }

        min_diff = giveSmallerPositiveNumber(left_diff, right_diff);

        return min_diff;
    }
};