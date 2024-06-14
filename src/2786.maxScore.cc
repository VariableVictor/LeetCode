#include "headers.h"

class Solution
{
  public:
    long long maxScore(vector<int>& nums, int x)
    {
      int n = nums.size();
      long long maxodd = nums[0], maxeven = nums[0];
      if(0 == nums[0] % 2)
        maxodd -= x;
      else
        maxeven -= x;

      
      for (int i = 1; i < n; i++)
      {
        if (0 == nums[i] % 2)
        {
          maxeven =max(maxeven, maxodd - x) + nums[i];
        }
        else
        {
          maxodd = max(maxodd, maxeven - x) + nums[i];
        }
      }

      return max(maxeven,maxodd);
    }
};

TEST(maxScore, maxScore_1)
{
  Solution s;
  vector<int> inn = {2,3,6,1,9,2};
  int inx = 5;
  int ans = 13;
  EXPECT_EQ(s.maxScore(inn, inx), ans);
}

TEST(maxScore, maxScore_2)
{
  Solution s;
  vector<int> inn = {2,4,6,8};
  int inx = 3;
  int ans = 20;
  EXPECT_EQ(s.maxScore(inn, inx), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
