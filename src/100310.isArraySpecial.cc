#include "headers.h"

class Solution
{
public:
    bool isArraySpecial(vector<int>& nums)
    {
      if (0 == nums.size())
        return false;
      int rem = nums[0]+ 1;
      for(auto n : nums)
      {
        if(n % 2 == rem % 2)
          return false;
        else
          rem = n;
      }
        return true;
    }
};

TEST(isArraySpecial, isArraySpecial_1)
{
    Solution s;
    vector<int> in = {1};
    int ans = true;
    EXPECT_EQ(s.isArraySpecial(in), ans);
}

TEST(isArraySpecial, isArraySpecial_2)
{
    Solution s;
    vector<int> in = {2 ,1, 4};
    int ans = true;
    EXPECT_EQ(s.isArraySpecial(in), ans);
}


TEST(isArraySpecial, isArraySpecial_3)
{
    Solution s;
    vector<int> in = {4, 3, 1, 6};
    int ans = false;
    EXPECT_EQ(s.isArraySpecial(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
