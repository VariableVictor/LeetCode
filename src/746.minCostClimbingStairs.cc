#include "headers.h"

class Solution
{
  public:
    int minCostClimbingStairs(vector<int>& cost)
    {
      int sm1 = 0, sm2 = 0, step;
      for(int i = 2; i <= cost.size(); ++i)
      {
        step = min(sm1 + cost[i-1],sm2 + cost[i-2]);
        sm2 = sm1;
        sm1 = step;
      }
      return sm1;
    }
};

TEST(minCostClimbingStairs, minCostClimbingStairs_1)
{
    Solution s;
    vector<int> in = {10, 15, 20};
    int ans = 15;
    EXPECT_EQ(s.minCostClimbingStairs(in), ans);
}

TEST(minCostClimbingStairs, minCostClimbingStairs_2)
{
    Solution s;
    vector<int> in = {1,100,1,1,1,100,1,1,100,1};
    int ans = 6;
    EXPECT_EQ(s.minCostClimbingStairs(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
