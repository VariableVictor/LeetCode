#include "headers.h"

class Solution
{
  public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB)
    {
      int iSize = temperatureA.size();
      int iCount = 0, iMax = 0;
      for (int i = 1; i < iSize; ++i)
      {
        if (iMax < iCount)
        {
          iMax = iCount;
        }
        if( temperatureA[i] > temperatureA[i-1] &&
            temperatureB[i] > temperatureB[i-1])
        {
          ++iCount;
          continue;
        }

        if( temperatureA[i] == temperatureA[i-1] &&
            temperatureB[i] == temperatureB[i-1])
        {
          ++iCount;
          continue;
        }

        if( temperatureA[i] < temperatureA[i-1] &&
            temperatureB[i] < temperatureB[i-1])
        {
          ++iCount;
          continue;
        }
        iCount = 0;

      }
      if (iMax < iCount)
      {
        iMax = iCount;
      }
      return iMax;
    }
};

TEST(temperatureTrend, temperatureTrend_1)
{
  Solution s;
  vector<int> inA = {21,18,18,18,31};
  vector<int> inB = {34,32,16,16,17};
  int ans = 2;
  EXPECT_EQ(s.temperatureTrend(inA, inB), ans);
}

TEST(temperatureTrend, temperatureTrend_2)
{
  Solution s;
  vector<int> inA = {5, 10,16,-6,15,11,3};
  vector<int> inB = {16,22,23,23,25,3 ,-16};
  int ans = 3;
  EXPECT_EQ(s.temperatureTrend(inA, inB), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
