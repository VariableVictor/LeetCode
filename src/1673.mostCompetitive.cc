#include "headers.h"

class Solution
{
public:
  vector<int> mostCompetitive(vector<int>& nums, int k)    
  {
    int ans[k];
    int as = 0;
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
      while(0 < as && n - i > k - as && ans[as - 1] > nums[i])
      {
        --as;
      }
      if(as < k)
        ans[as++] = nums[i];
    }
    vector<int>res(ans, ans+k);
    return res;
  }
};

TEST(mostCompetitive, mostCompetitive_1)
{
    Solution s;
    vector<int> in1 = {3, 5, 2, 6};
    int in2 = 2;
    vector<int> ans = {2, 6};
    EXPECT_EQ(s.mostCompetitive(in1, in2), ans);
}

TEST(mostCompetitive, mostCompetitive_2)
{
    Solution s;
    vector<int> in1 = {2, 4, 3, 3, 5, 4, 9, 6};
    int in2 = 4;
    vector<int> ans = {2, 3, 3, 4};
    EXPECT_EQ(s.mostCompetitive(in1, in2), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
