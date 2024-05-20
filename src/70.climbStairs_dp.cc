#include "headers.h"

class Solution
{
public:
    int climbStairs_dp(int n)
    {
      int f=1,fm1=0,fm2=0;
      for(int i = 1; i <= n; ++i)
      {
        fm2 = fm1;
        fm1 = f;
        f = fm1+fm2;
      }
      return f;
    }
};


TEST(climbStairs_dp, climbStairs_dp_1)
{
    Solution s;
    int in = 2;
    int ans = 2;
    EXPECT_EQ(s.climbStairs_dp(in), ans);
}

TEST(climbStairs_dp, climbStairs_dp_2)
{
    Solution s;
    int in = 3;
    int ans = 3;
    EXPECT_EQ(s.climbStairs_dp(in), ans);
}

TEST(climbStairs_dp, climbStairs_dp_3)
{
    Solution s;
    int in = 15;
    int ans = 987;
    EXPECT_EQ(s.climbStairs_dp(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
