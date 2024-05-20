#include "headers.h"

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
      if(0 == strs.size())
        return "";
      if(1 == strs.size())
        return strs[0];
      string strR("");
      for(int i = 0; i < strs[0].size(); ++i)
      {
        auto itStr = strs.begin();
        for(++itStr; itStr != strs.end(); ++itStr)
        {
          if((*itStr)[i] != strs[0][i])
          {
            return strR;
          }
        }
        strR += strs[0][i];
      }
      return strR;
    }
};

TEST(longestCommonPrefix, longestCommonPrefix_1)
{
    Solution s;
    vector<string> in = {"flower","flow","flight"};
    string ans = "fl";
    EXPECT_EQ(s.longestCommonPrefix(in), ans);
}

TEST(longestCommonPrefix, longestCommonPrefix_2)
{
    Solution s;
    vector<string> in = {"dog","racecar","car"};
    string ans = "";
    EXPECT_EQ(s.longestCommonPrefix(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
