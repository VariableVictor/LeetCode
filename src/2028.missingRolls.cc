#include "headers.h"

class Solution
{
  public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
      int totaln = rolls.size() + n;
      int total = mean * totaln;
      if (0 != total % totaln)
        return {};
      int remn;
      for (remn = total; int ro : rolls)
      {
        remn -= ro;
      }
      if (remn < n)
        return {};
      if (remn > n * 6)
        return {};
      vector<int> ans(n, remn / n);
      for (int i = 0; i < remn % n; ++i)
        ans[i] += 1;
      return ans;
    }
};

TEST(missingRolls, missingRolls_1)
{
    Solution s;
    int sum = 0;
    vector<int> rolls = {3,2,4,3};
    int mean = 4;
    int n = 2;
    EXPECT_GT(s.missingRolls(rolls,mean,n).size(), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
