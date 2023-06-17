#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Merge into single vector
        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - m];
        }

        inPlaceQS(nums1, 0, nums1.size() - 1);
    }

    int partition(vector<int> &elements, int start, int end)
    {
        int pivot = elements[end];
        int index = start;

        for (int i = start; i < end; i++)
        {
            if (elements[i] <= pivot)
            {
                swap(elements, index, i);
                index++;
            }
        }
        swap(elements, index, end);
        return index;
    }

    void inPlaceQS(vector<int> &elements, int start, int end)
    {
        if (start < end)
        {
            int partition_point = partition(elements, start, end);
            inPlaceQS(elements, start, partition_point - 1);
            inPlaceQS(elements, partition_point + 1, end);
        }
    }

    void swap(vector<int> &elements, int loc1, int loc2)
    {
        int temp = elements[loc1];
        elements[loc1] = elements[loc2];
        elements[loc2] = temp;
    }
};