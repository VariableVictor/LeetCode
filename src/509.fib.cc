#include "headers.h"

class Solution
{
public:
  int fib(int n)
  {
    int f = 1, fm1 = 0, fm2 = 0;
    if(2 > n)
      return n;
    for(int i = 2; i <= n; ++i)
    {
      fm2 = fm1;
      fm1 = f;
      f = fm1 + fm2;
      //cout << f << endl;
    }
    return f;
  }
};

TEST(fib, fib_1)
{
    Solution s;
    int in = 0;
    int ans = 0;
    EXPECT_EQ(s.fib(in), ans);
}

TEST(fib, fib_2)
{
    Solution s;
    int in = 1;
    int ans = 1;
    EXPECT_EQ(s.fib(in), ans);
}

TEST(fib, fib_3)
{
    Solution s;
    int in = 5;
    int ans = 5;
    EXPECT_EQ(s.fib(in), ans);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
