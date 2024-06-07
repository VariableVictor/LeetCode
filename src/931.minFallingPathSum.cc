#include "headers.h"

class Solution
{
  public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
      int n = matrix.size();
      if(1 == n)
        return matrix[0][0];
      for (int i = 1; i < n; ++i)
      {
        matrix[i][0] += min(matrix[i-1][0], matrix[i-1][1]);
        matrix[i][n-1] += min(matrix[i-1][n-1], matrix[i-1][n-2]);

        for (int j = 1; j < n - 1; ++j)
        {
          matrix[i][j] += min(
              min(matrix[i-1][j-1],matrix[i-1][j]),
              matrix[i-1][j+1]);
        }
      }
        return ranges::min(matrix[n-1]);
    }
};

TEST(minFallingPathSum, minFallingPathSum_1)
{
  Solution s;
  vector<vector<int>> in = {{2,1,3},{6,5,4},{7,8,9}};
  int ans = 13;
  EXPECT_EQ(s.minFallingPathSum(in), ans);
}

TEST(minFallingPathSum, minFallingPathSum_2)
{
  Solution s;
  vector<vector<int>> in = {{-19,57},{-40,-5}};
  int ans = -59;
  EXPECT_EQ(s.minFallingPathSum(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
