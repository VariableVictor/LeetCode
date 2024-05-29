#include "headers.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
      int cash[3] = {0,0,0};
      for(int loot : nums)
      {
        cash[0] = max(cash[1], cash[2] + loot);
        cash[2] = cash[1];
        cash[1] = cash[0];
      }
      return cash[0];
    }
};

TEST(rob, rob_1)
{
    Solution s;
    vector<int> in = {1, 2, 3, 1};
    int ans = 4;
    EXPECT_EQ(s.rob(in), ans);
}

TEST(rob, rob_2)
{
    Solution s;
    vector<int> in = {2, 7, 9, 3, 1};
    int ans = 12;
    EXPECT_EQ(s.rob(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
