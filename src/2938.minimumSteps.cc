#include "headers.h"

class Solution
{
  public:
    long long minimumSteps(string s)
    {
      long long count=0,sum=0;
      for(char c : s)
      {
        if('1' == c)
        {
          ++count;
        }
        else
        {
          sum += count;
        }
      }
      return sum;
    }
};

TEST(minimumSteps, minimumSteps_1)
{
    Solution s;
    string in = "101";
    int ans = 1;
    EXPECT_EQ(s.minimumSteps(in), ans);
}

TEST(minimumSteps, minimumSteps_2)
{
    Solution s;
    string in = "100";
    int ans = 2;
    EXPECT_EQ(s.minimumSteps(in), ans);
}

TEST(minimumSteps, minimumSteps_3)
{
    Solution s;
    string in = "0111";
    int ans = 0;
    EXPECT_EQ(s.minimumSteps(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
