#include "headers.h"

class Solution
{
  public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
      map<int,int> losecount;
      vector<vector<int>> ans = {{},{}};
      for(auto m : matches)
      {
        if(!losecount.contains(m[0]))
        {
          losecount[m[0]] = 0;
        }
        ++losecount[m[1]];

        //if(!losecount.contains(m[1]))
        //{
        //  losecount[m[1]] = 1;
        //}
        //else
        //{
        //  ++losecount[m[1]];
        //}
      }

      for(auto p:losecount)
      {
        switch(p.second)
        {
          case 0:
          case 1:
            ans[p.second].push_back(p.first);
            break;
          default:
            break;
        }
      }
      return ans;
    }
};

TEST(findWinners, findWinners_1)
{
    Solution s;
    vector<vector<int>> in = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> ans = {{1,2,10},{4,5,7,8}};
    EXPECT_EQ(s.findWinners(in), ans);
}

TEST(findWinners, findWinners_2)
{
    Solution s;
    vector<vector<int>> in = {{2,3},{1,3},{5,4},{6,4}};
    vector<vector<int>> ans = {{1,2,5,6},{}};
    EXPECT_EQ(s.findWinners(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
