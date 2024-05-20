#include "headers.h"

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
      vector<int> newnums = {};
      if(0 == nums.size())
      {
        return 0;
      }

      int iEnd = nums[0];
      newnums.push_back(iEnd);
      for(int iE : nums)
      {
        if(iE == iEnd)
          continue;
        else
        {
          iEnd = iE;
          newnums.push_back(iE);
        }
      }
      nums = newnums;
      return nums.size();
    }
};

TEST(removeDuplicates, removeDuplicates_1)
{
    Solution s;
    vector<int> in = {1, 1, 2};
    int ans = 2;
    EXPECT_EQ(s.removeDuplicates(in), ans);
}

TEST(removeDuplicates, removeDuplicates_2)
{
    Solution s;
    vector<int> in = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = 5;
    EXPECT_EQ(s.removeDuplicates(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
