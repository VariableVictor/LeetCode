#include "headers.h"

class Solution
{
public:
    int countTestedDevices(vector<int>& batteryPercentages)
    {
      int iAt = 0, iCount = 0;
      int iEnd = batteryPercentages.size();
      while (iAt < iEnd)
      {
        if(batteryPercentages[iAt] > iCount)
        {
          ++iCount;
        }
        ++iAt;
      }
      return iCount;
    }
};

TEST(countTestedDevices, countTestedDevices_1)
{
    Solution s;
    vector<int> in = {1, 1, 2, 1, 3};
    int ans = 3;
    EXPECT_EQ(s.countTestedDevices(in), ans);
}

TEST(countTestedDevices, countTestedDevices_2)
{
    Solution s;
    vector<int> in = {0, 1, 2};
    int ans = 2;
    EXPECT_EQ(s.countTestedDevices(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
