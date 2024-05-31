#include "headers.h"

class Solution
{
public:
  int gridS[26][3] = {0};
  int maxL = 0;
  char maxC ='\0';

  void pred(char c, int ic)
  {
    if(c < 'a' || c > 'z')
      return;
    auto &arr = gridS[c - 'a'];

    if(arr[0] < ic)
    {
      if(arr[0] == ic -1)
        arr[2] = arr[1];
      else
        arr[2] = 0;
      arr[1] = 1;
      arr[0] = ic;
    }
    else if(arr[0] == ic)
    {
      arr[1]++;
    }
    else if(arr[0] == ic + 1)
    {
      arr[2]++;
    }

    int iMax = arr[0] - 2;
    if (arr[1] > 2)
      iMax += 2;
    else if(arr[1] * 2 + arr[2] > 2)
      iMax += 1;

    if(iMax > maxL)
    {
      maxL = iMax;
      maxC = c;
    }
  }

  int maximumLength(string s)
  {
    char clast ='\0';
    int lcount = 0;
    for(auto iter = s.begin(); iter != s.end(); ++iter)
    {
      if(*iter == clast)
        ++lcount;
      else
      {
        pred(clast, lcount);
        clast = *iter;
        lcount = 1;
      }
    }
    pred(clast, lcount);

    if(maxC == '\0')
      return -1;
    return maxL;
  }
};

TEST(maximumLength, maximumLength_1)
{
    Solution s;
    string in = "aaaa";
    int ans = 2;
    EXPECT_EQ(s.maximumLength(in), ans);
}

TEST(maximumLength, maximumLength_2)
{
    Solution s;
    string in = "abcdef";
    int ans = -1;
    EXPECT_EQ(s.maximumLength(in), ans);
}

TEST(maximumLength, maximumLength_3)
{
    Solution s;
    string in = "abcaba";
    int ans = 1;
    EXPECT_EQ(s.maximumLength(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
