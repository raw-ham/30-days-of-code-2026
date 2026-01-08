#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int> &nums)
{

    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] = 1;
    }
    int a = 0;

    //this will cause first element  of my consecutive list set to 1
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.count(nums[i] - 1) > 0)
        {
            m[nums[i]] = 0;
        }
    }

    int mxx = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m[nums[i]] == 1)
        {
            int j = 0;
            int l= 0;
            while (m.count(nums[i] + j) > 0)
            {
                j++;
                l++;
            }
            if (l > mxx)
            {
                mxx = l;
            }
        }
    }

    return mxx;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
    return 0;
}