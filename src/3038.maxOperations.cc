#include "headers.h"

class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
      int score = nums[0]+nums[1];
      int times = 1;
      for (int i = 2; i + 1 < nums.size(); i += 2)
      {
        if(score != nums[i] + nums[i + 1])
          break;
        ++times;
      }
      return times;
    }
};

TEST(maxOperations, maxOperations_1)
{
    Solution s;
    vector<int> in = {3,2,1,4,5};
    int ans = 2;
    EXPECT_EQ(s.maxOperations(in), ans);
}

TEST(maxOperations, maxOperations_2)
{
    Solution s;
    vector<int> in = {3,2,6,1,4};
    int ans = 1;
    EXPECT_EQ(s.maxOperations(in), ans);
}

TEST(maxOperations, maxOperations_3)
{
    Solution s;
    vector<int> in = {2,2,3,2,4,2,3,3,1,3};
    int ans = 1;
    EXPECT_EQ(s.maxOperations(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
