#include "headers.h"

class Solution
{
public:
    bool isValid(string s)
    {
      string strWaiting("");

      for(char c : s)
      {
        switch(c)
        {
          case '(':
            strWaiting.push_back(')');
            break;
          case '[':
            strWaiting.push_back(']');
            break;
          case '{':
            strWaiting.push_back('}');
            break;
          case ')':
          case ']':
          case '}':
            if(0 == strWaiting.size())
              return false;
            if(c == strWaiting[strWaiting.size()-1])
              strWaiting.pop_back();
            else
              return false;
            break;
          default:
            return false;
            break;
        }
      }
      if(0 == strWaiting.size())
        return true;
      else
        return false;
    }
};

TEST(isValid, isValid_1)
{
    Solution s;
    string in = "()";
    bool ans = true;
    EXPECT_EQ(s.isValid(in), ans);
}

TEST(isValid, isValid_2)
{
    Solution s;
    string in = "()[]{}";
    bool ans = true;
    EXPECT_EQ(s.isValid(in), ans);
}

TEST(isValid, isValid_3)
{
    Solution s;
    string in = "(]";
    bool ans = false;
    EXPECT_EQ(s.isValid(in), ans);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
