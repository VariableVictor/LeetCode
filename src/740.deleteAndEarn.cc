#include "headers.h"

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
      map<int,int> score;
      for(int n : nums)
      {
        if(!score.contains(n))
          score[n] = 1;
        else
          score[n]++;
      }
      int cash[3] = {0,0,0};
      for(auto iter = score.begin(); iter != score.end(); ++iter)
      {
        if(score.contains(iter->first - 1))
          cash[0] = max(cash[1], cash[2] + (iter->first * iter->second));
        else
          cash[0] = max(cash[1],cash[2]) + (iter->first * iter->second);
        cash[2] = cash[1];
        cash[1] = cash[0];
      }
        return cash[0];
    }
};

TEST(deleteAndEarn, deleteAndEarn_1)
{
    Solution s;
    vector<int> in = {3, 4, 2};
    int ans = 6;
    EXPECT_EQ(s.deleteAndEarn(in), ans);
}

TEST(deleteAndEarn, deleteAndEarn_2)
{
    Solution s;
    vector<int> in = {2, 2, 3, 3, 3, 4};
    int ans = 9;
    EXPECT_EQ(s.deleteAndEarn(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
