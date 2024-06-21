#include "headers.h"

class Solution
{
  public:
    int countBeautifulPairs(vector<int>& nums)
    {
      int iSize = nums.size();
      unordered_set<int> notcoprime[10] = {
        {},//0
        {},//1
        {2, 4, 6, 8},//2
        {3, 6, 9},//3
        {2, 4, 6, 8},//4

        {5},//5
        {2, 3, 4, 6, 8, 9},//6
        {7},//7
        {2, 4, 6, 8},//8
        {3, 6, 9}};//9

      int ans = 0;
      for (int i = 0; i < iSize - 1; ++i)
      {
        int base;
        for (base = nums[i]; base / 10 > 0; base /= 10);
        for (int j = i + 1; j < iSize; ++j)
        {
          if (!notcoprime[base].contains(nums[j] % 10))
          {
            ++ans;
          }
        }
      }
      return ans;
    }
};

TEST(countBeautifulPairs, countBeautifulPairs_1)
{
  Solution s;
  vector<int> in = {2,5,1,4};
  int ans = 5;
  EXPECT_EQ(s.countBeautifulPairs(in), ans);
}

TEST(countBeautifulPairs, countBeautifulPairs_2)
{
  Solution s;
  vector<int> in = {11, 21, 12};
  int ans = 2;
  EXPECT_EQ(s.countBeautifulPairs(in), ans);
}

TEST(countBeautifulPairs, countBeautifulPairs_3)
{
  Solution s;
  vector<int> in = {51,65,87,6,17,32,14,42,46};
  int ans = 19;
  EXPECT_EQ(s.countBeautifulPairs(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
