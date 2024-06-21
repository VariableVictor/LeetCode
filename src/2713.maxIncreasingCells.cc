#include "headers.h"

class Solution
{
  public:
    int maxIncreasingCells(vector<vector<int>>& mat)
    {
      int m = mat.size();
      int n = mat[0].size();
      map<int, vector<pair<int,int>>> mM;
      int ans = 0;
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          mM[mat[i][j]].push_back(pair<int,int>(i,j));
        }
      }

      vector<vector<int>> dp(m,vector<int>(n, 0));
      vector<int> rowMax(m,0), colMax(n, 0);
      
      for (auto vec : mM)
      {
        for (auto cell : vec.second)
        {
          int i = cell.first, j = cell.second;
          dp[i][j] = max(rowMax[i], colMax[j]) + 1;
        }
        for (auto cell : vec.second)
        {
          int i = cell.first, j = cell.second;
          rowMax[i] = max(rowMax[i], dp[i][j]);
          colMax[j] = max(colMax[j], dp[i][j]);
        }
      }

      for (int r : rowMax)
      {
        if (ans < r)
        {
          ans = r;
        }
      }
      return ans;
    }
};

TEST(maxIncreasingCells, maxIncreasingCells_1)
{
  Solution s;
  vector<vector<int>> in = {{3,1},{3,4}};
  int ans = 2;
  EXPECT_EQ(s.maxIncreasingCells(in), ans);
}

TEST(maxIncreasingCells, maxIncreasingCells_2)
{
  Solution s;
  vector<vector<int>> in = {{1,1},{1,1}};
  int ans = 1;
  EXPECT_EQ(s.maxIncreasingCells(in), ans);
}

TEST(maxIncreasingCells, maxIncreasingCells_3)
{
  Solution s;
  vector<vector<int>> in = {{3,1,6},{-9,5,7}};
  int ans = 4;
  EXPECT_EQ(s.maxIncreasingCells(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
