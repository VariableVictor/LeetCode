#include "headers.h"

class Solution
{
  public:
    int countBattleships(vector<vector<char>>& board)
    {
      int m = board.size();
      int n = board[0].size();
      int count = 0;
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if ('X' == board[i][j])
          {
            if (0 != i && 'X' == board[i-1][j])
            {continue;}
            if (0 != j && 'X' == board[i][j-1])
            {continue;}
            ++count;
          }
        }
      }
      return count;
    }
};

TEST(countBattleships, countBattleships_1)
{
  Solution s;
  vector<vector<char>> in = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
  int ans = 2;
  EXPECT_EQ(s.countBattleships(in), ans);
}

TEST(countBattleships, countBattleships_2)
{
  Solution s;
  vector<vector<char>> in = {{'.'}};
  int ans = 0;
  EXPECT_EQ(s.countBattleships(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
