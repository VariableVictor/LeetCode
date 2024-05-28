#include "headers.h"

class Solution
{
public:
    int tribonacci(int n)
    {
      long t0 = 0, t1 = 1, t2 = 1;
      long tep;
      for(int i = 0; i < n; ++i)
      {
        tep = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = tep;
      }
      return t0;
    }
};

TEST(tribonacci, tribonacci_1)
{
    Solution s;
    int in = 4;
    int ans = 4;
    EXPECT_EQ(s.tribonacci(in), ans);
}

TEST(tribonacci, tribonacci_2)
{
    Solution s;
    int in = 25;
    int ans = 1389537;
    EXPECT_EQ(s.tribonacci(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
