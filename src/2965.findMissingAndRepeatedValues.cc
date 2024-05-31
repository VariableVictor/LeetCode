#include "headers.h"

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
      int n = grid.size();
      vector<int> count(n*n +1);

      for(auto v1 : grid)
      {
        for(auto n2 : v1)
        {
          count[n2]++;
        }
      }
      vector<int> ans(2);
      for(int i = 1; i<= n*n; ++i )
      {
        switch(count[i])
        {
          case 2:
            ans[0] = i;
            break;
          case 0:
            ans[1] = i;
            break;
        }
      }

      return ans;
    }
};
TEST(findMissingAndRepeatedValues, findMissingAndRepeatedValues_1)
{
    Solution s;
    vector<vector<int>> in = {{1, 3}, {2, 2}};
    vector<int> ans = {2,4};
    EXPECT_EQ(s.findMissingAndRepeatedValues(in), ans);
}


TEST(findMissingAndRepeatedValues, findMissingAndRepeatedValues_2)
{
    Solution s;
    vector<vector<int>> in = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans = {9,5};
    EXPECT_EQ(s.findMissingAndRepeatedValues(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
