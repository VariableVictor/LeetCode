#include "headers.h"

class Solution
{
public:
    string convert(string s, int numRows)
    {
      string res = "";
      //int tl = s.size();
      int si = numRows == 1 ? 1 : numRows * 2 - 2;

      for(int i = 0; i < numRows; ++i)//means row nums
      {
        for(int j = 0; j*si + i < s.size(); ++j)//means times of loop for return row0
        {
          res.push_back(s[si * j + i]);
          if( i != 0 &&
              i != numRows -1 &&
              si *(j + 1) - i < s.size())
          {
            res.push_back(s[si *(j + 1) - i]);
          }
        }
      }
        return res;
    }
};

TEST(convert, convert_1)
{
    Solution s;
    string inS = "PAYPALISHIRING";
    int inR = 3;

    string ans = "PAHNAPLSIIGYIR";
    EXPECT_EQ(s.convert(inS,inR), ans);
}

TEST(convert, convert_2)
{
    Solution s;
    string inS = "PAYPALISHIRING";
    int inR = 4;

    string ans = "PINALSIGYAHRPI";
    EXPECT_EQ(s.convert(inS,inR), ans);
}

TEST(convert, convert_3)
{
    Solution s;
    string inS = "A";
    int inR = 1;

    string ans = "A";
    EXPECT_EQ(s.convert(inS,inR), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
