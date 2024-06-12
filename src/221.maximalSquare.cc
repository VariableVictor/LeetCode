#include "headers.h"

class Solution
{
  public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
      int m = matrix.size();
      int n = matrix[0].size();
      vector<int> row1(n,0), row2(n,0);
      int maxSq = 0;
      for (int i = 0; i < m; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          row2[j] = matrix[i][j] - '0';
          if (i > 0 && j > 0 && row2[j] == 1)
          {
            row2[j] +=
              min(row2[j-1],min(row1[j-1],row1[j]));
          }
          if(row2[j] > maxSq)
            maxSq = row2[j];
        }
        row1 = row2;
      }
      return maxSq*maxSq;
    }
};

TEST(maximalSquare, maximalSquare_1)
{
  Solution s;
  vector<vector<char>> in = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
  int ans = 4;
  EXPECT_EQ(s.maximalSquare(in), ans);
}

TEST(maximalSquare, maximalSquare_2)
{
  Solution s;
  vector<vector<char>> in = {{'0', '1'}, {'1', '0'}};
  int ans = 1;
  EXPECT_EQ(s.maximalSquare(in), ans);
}

TEST(maximalSquare, maximalSquare_3)
{
  Solution s;
  vector<vector<char>> in = {{'0'}};
  int ans = 0;
  EXPECT_EQ(s.maximalSquare(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
