#include "headers.h"

class Solution
{
  public:
    int minPathSum(vector<vector<int>>& grid)
    {
      int m = grid.size(), n = grid[0].size();
      //vector<vector<int>> gridmin = grid;

      for(int i = 1; i < m; ++i)
      {
        grid[i][0] += grid[i-1][0];
      }
      for(int j = 1; j < n; ++j)
      {
        grid[0][j] += grid[0][j-1];
      }
      for(int i = 1; i < m; ++i)
      {
        for(int j = 1; j < n; ++j)
        {
          grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
      }
      return grid[m-1][n-1];
    }
};

TEST(minPathSum, minPathSum_1)
{
  Solution s;
  vector<vector<int>> in = {{1,3,1},{1,5,1},{4,2,1}};
  int ans = 7;
  EXPECT_EQ(s.minPathSum(in), ans);
}

TEST(minPathSum, minPathSum_2)
{
  Solution s;
  vector<vector<int>> in = {{1,2,3},{4,5,6}};
  int ans = 12;
  EXPECT_EQ(s.minPathSum(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
