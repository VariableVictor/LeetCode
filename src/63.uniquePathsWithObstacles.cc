#include "headers.h"

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
      int m = obstacleGrid.size(), n = obstacleGrid[0].size();
      if ((1 == obstacleGrid[0][0]) || (1 == obstacleGrid[m-1][n-1]))
      {
        return 0;
      }
      obstacleGrid[0][0] = 1;
      for (int j = 1; j < n; j++)
      {
        obstacleGrid[0][j] = (1 == obstacleGrid[0][j]) ? 0 :obstacleGrid[0][j - 1];
      }
      for (int i = 1; i < m; i++)
      {
        obstacleGrid[i][0] = (1 == obstacleGrid[i][0]) ? 0 : obstacleGrid[i - 1][0];
        for (int j = 1; j < n; j++)
        {
          obstacleGrid[i][j] = (1 == obstacleGrid[i][j]) ? 0 : \
                               obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        }
      }
      return obstacleGrid[m - 1][n - 1];
    }
};

TEST(uniquePathsWithObstacles, uniquePathsWithObstacles_1)
{
  Solution s;
  vector<vector<int>> in = {{0,0,0},{0,1,0},{0,0,0}};
  int ans = 2;
  EXPECT_EQ(s.uniquePathsWithObstacles(in), ans);
}

TEST(uniquePathsWithObstacles, uniquePathsWithObstacles_2)
{
  Solution s;
  vector<vector<int>> in = {{0,1},{0,0}};
  int ans = 1;
  EXPECT_EQ(s.uniquePathsWithObstacles(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
