#include "headers.h"

class Solution
{
public:
    int uniquePaths_dp(int m, int n)
    {
      int iTP = m + n - 2;//TotalStep
      unordered_map<pair<int,int>,int> map_last,map_curr;
      map_curr[pair(0,0)] = 1;
      for(int is = 0; is < iTP; ++is)
      {
        map_last = map_curr;
        map_curr.clear();
        for(auto iter = map_last.begin(); iter != map_last.end(); ++iter)
        {
          int value = iter->second;
          int y = iter->first->first;
          int x = iter->first->second;
          if(y + 1 < m)
            if(!map_curr.contains(pair(y+1,x)))
              map_curr[pair(y+1,x)] = value;
            else
              map_curr[pair(y+1,x)] += value;
          if(x + 1 < n)
            if(!map_curr.contains(pair(y,x + 1)))
              map_curr[pair(y,x+1)] = value;
            else
              map_curr[pair(y,x+1)] += value;
        }
      }
      return map_curr.begin()->second;
    }
};

TEST(uniquePaths_dp, uniquePaths_dp_1)
{
    Solution s;
    int inM = 3;
    int inN = 7;
    int ans = 28;
    EXPECT_EQ(s.uniquePaths_dp(inM, inN), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
