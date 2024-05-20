#include "headers.h"

class Solution
{
public:
    int recvclimb(int n, int t1, int t2)
    {
      if( n <= 2)
        return n * t1 + (n - 1) * t2;
      return recvclimb(n - 1, t1 + t2, t1);
    }
    int climbStairs(int n)
    {
      return recvclimb(n,1,0);
    }
};

TEST(climbStairs, climbStairs_1)
{
    Solution s;
    int in = 2;
    int ans = 2;
    EXPECT_EQ(s.climbStairs(in), ans);
}

TEST(climbStairs, climbStairs_2)
{
    Solution s;
    int in = 3;
    int ans = 3;
    EXPECT_EQ(s.climbStairs(in), ans);
}

TEST(climbStairs, climbStairs_3)
{
    Solution s;
    int in = 15;
    int ans = 987;
    EXPECT_EQ(s.climbStairs(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
