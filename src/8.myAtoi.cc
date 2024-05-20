#include "headers.h"

class Solution
{
public:
    int myAtoi(string s)
    {
      bool neg = false;
      long res = 0;
      auto ic = s.begin();

      for(; ' ' == *ic; ++ic);

      switch(*ic)
      {
        case '-':
          neg = true;
        case '+':
          ++ic;
          break;
      }

      for(; '0' == *ic; ++ic);

      for(; '0' <= *ic && '9' >= *ic; ++ic)
      {
        res *= 10;
        res += *ic - '0';
        if(res > 0x7fffffff) 
          return neg ? - 0x80000000 : 0x7fffffff;
      }

      return neg ? - res:res;
    }
};

TEST(myAtoi, myAtoi_1)
{
    Solution s;
    string in = "42";
    int ans = 42;
    EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(myAtoi, myAtoi_2)
{
    Solution s;
    string in = " -042";
    int ans = -42;
    EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(myAtoi, myAtoi_3)
{
    Solution s;
    string in = "1337c0d3";
    int ans = 1337;
    EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(myAtoi, myAtoi_4)
{
    Solution s;
    string in = "0-1";
    int ans = 0;
    EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(myAtoi, myAtoi_5)
{
    Solution s;
    string in = "words and 987";
    int ans = 0;
    EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(myAtoi, myAtoi_6)
{
    Solution s;
    string in = "-91283472332";
    int ans = -2147483648;
    EXPECT_EQ(s.myAtoi(in), ans);
}

TEST(myAtoi, myAtoi_7)
{
    Solution s;
    string in ="20000000000000000000";
    int ans = 0x7fffffff;
    EXPECT_EQ(s.myAtoi(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
