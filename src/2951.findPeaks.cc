#include "headers.h"

class Solution
{
  public:
    vector<int> findPeaks(vector<int>& mountain)
    {
      vector<int> ans;
      for (int i = 1; i < mountain.size() - 1; ++i)
      {
        if (mountain[i - 1] < mountain[i] &&
            mountain[i] > mountain[i + 1])
        {
          ans.push_back(i);
          ++i;
        }
        else if (mountain[i] >= mountain[i + 1])
        {
          ++i;
        }
      }
      return ans;
    }
};

TEST(findPeaks, findPeaks_1)
{
    Solution s;
    vector<int> in = {2, 4, 4};
    vector<int> ans = {};
    EXPECT_EQ(s.findPeaks(in), ans);
}

TEST(findPeaks, findPeaks_2)
{
    Solution s;
    vector<int> in = {1, 4, 3, 8, 5};
    vector<int> ans = {1, 3};
    EXPECT_EQ(s.findPeaks(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
