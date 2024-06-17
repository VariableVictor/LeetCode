#include "headers.h"

class Solution
{
  public:
    bool stringContain(const string & strL, const string & strS)
    {
      int iL = 0,iS = 0,iSkip = strL.size() - strS.size();;
      for (char ch : strS)
      {
        while (iL < strL.size() && strL[iL] != ch)
        {
          if (0 == iSkip)
          {
            return false;
          }
          --iSkip;
          ++iL;
        }
        if(iL == strL.size())
            return false;
        ++iL;
      }
      return true;
    }

    bool findMother(const map<int, unordered_map<string,int>, std::greater<int>> &mapStrs, const string &s, int size)
    {
      for (auto sizeB : mapStrs)
      {
        if (sizeB.first > size)
        {
          for (auto strB : sizeB.second)
          {
            if (stringContain(strB.first, s))
            {
              return true;
            }
          }
        }
        else
          return false;
      }
      return false;
    }

    int findLUSlength(vector<string>& strs)
    {
      map<int, unordered_map<string,int>, std::greater<int>> mystrs;
      for (auto st : strs)
      {
        int iSize = st.size();
        if (!mystrs.contains(iSize))
        {
          mystrs[iSize] = {{st,1}};
        }
        else if (!mystrs[iSize].contains(st))
        {
          mystrs[iSize][st] = 1;
        }
        else
        {
          mystrs[iSize][st] += 1;
        }
      }
      int ans = -1;
      for (auto strMap : mystrs)
      {
        int iSize = strMap.first;
        string strA;
        bool bDel = false;
        for (auto st : strMap.second)
        {
          if (bDel)
          {
            strMap.second.erase(strA);
            bDel = false;
          }
          if(findMother(mystrs, st.first, iSize))
          {
            bDel =true;
            strA = st.first;
          }
          else if (1 == st.second)
          {
            return iSize;
          }
        }
        if (bDel)
        {
          strMap.second.erase(strA);
          bDel = false;
        }
      }
      return ans;
    }
};

TEST(findLUSlength, findLUSlength_1)
{
  Solution s;
  vector<string> in = {"aba","cdc","eae"};
  int ans = 3;
  EXPECT_EQ(s.findLUSlength(in), ans);
}

TEST(findLUSlength, findLUSlength_2)
{
  Solution s;
  vector<string> in = {"aaa","aaa","aa"};
  int ans = -1;
  EXPECT_EQ(s.findLUSlength(in), ans);
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
