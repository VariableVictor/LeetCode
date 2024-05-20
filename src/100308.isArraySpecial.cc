#include "headers.h"

class Solution
{
  public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries)
    {
      //vector<int> falsePair = {};
      vector<bool> ans = {};
      for (auto ra : queries)
      {
        bool an = true;
        if(ra[0] < 0 || nums.size() <= ra[1])
          an = false;
        int rem = nums[ra[0]] + 1;
        for(int i = ra[0]; i <= ra[1]; ++i)
        {
          if(nums[i] % 2 == rem % 2)
          {
            an = false;
            break;
          }
          else rem = nums[i];
        }
        ans.push_back(an);

      }
      return ans;
    }
};

TEST(isArraySpecial, isArraySpecial_1)
{
    Solution s;
    vector<int> inn = {3, 4, 1, 2, 6};
    vector<vector<int>> ins = {{0,4}};
    vector<bool> ans = {false};
    EXPECT_EQ(s.isArraySpecial(inn, ins), ans);
}

TEST(isArraySpecial, isArraySpecial_2)
{
    Solution s;
    vector<int> inn = {4,3,1,6};
    vector<vector<int>> ins = {{0,2},{2,3}};
    vector<bool> ans = {false,true};
    EXPECT_EQ(s.isArraySpecial(inn, ins), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
