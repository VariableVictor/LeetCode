#include "headers.h"

class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
      unordered_map<int,vector<int>> mm;
      for(int i = 0; i < nums.size(); ++i)
      {
        int n = nums[i];
        if(!mm.contains(n))
          mm[n] = {i,1,1};//first index, count, max
        else
        {
          ++mm[n][1];
          if(i - mm[n][0] + 1 - mm[n][1] > k)
          {
            int *j = &(mm[n][0]);
            for(; n == nums[*j]; ++*j)
            {
              --mm[n][1];
            }
            for(; n != nums[*j]; ++*j);
          }
          if(mm[n][1] > mm[n][2])
            mm[n][2] = mm[n][1];
        }
      }
      //return ranges::max(mm.begin(), mm.end(), {}, [&](auto p)->int {return (p->second)[2];});
      int max = 0;
      for(auto n : mm)
      {
        if(max < n.second[2])
          max = n.second[2];
      }
      return max;
    }
};

TEST(longestEqualSubarray, longestEqualSubarray_1)
{
    Solution s;
    vector<int> inn = {1,3,2,3,1,3};
    int ink = 3;
    int ans = 3;
    EXPECT_EQ(s.longestEqualSubarray(inn, ink), ans);
}

TEST(longestEqualSubarray, longestEqualSubarray_2)
{
    Solution s;
    vector<int> inn = {1,1,2,2,1,1};
    int ink = 2;
    int ans = 4;
    EXPECT_EQ(s.longestEqualSubarray(inn, ink), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
