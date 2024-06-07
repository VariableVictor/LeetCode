#include "headers.h"

class Solution
{
  public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
      int i;
      for (i = 1; i < triangle.size(); i++)
      {
        triangle[i][0] += triangle[i-1][0];
        triangle[i][i] += triangle[i-1][i-1];
        
        for (int j = 1; j < triangle[i].size() - 1; j++)
        {
          triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
        }
      }
      return ranges::min(triangle[i-1]);
    }
};

TEST(minimumTotal, minimumTotal_1)
{
  Solution s;
  vector<vector<int>> in = {{2},{3,4},{6,5,7},{4,1,8,3}};
  int ans = 11;
  EXPECT_EQ(s.minimumTotal(in), ans);
}

TEST(minimumTotal, minimumTotal_2)
{
  Solution s;
  vector<vector<int>> in = {{-10}};
  int ans = -10;
  EXPECT_EQ(s.minimumTotal(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
