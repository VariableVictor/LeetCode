#include "headers.h"

class Solution
{
  public:
    int maxCoins(vector<int> &nums)
    {
      int n = nums.size();
      vector<int> numsPlus(n + 2);
      vector<vector<int>> maxScore(n);//Score[size-1][start]

      numsPlus[0] = 1;
      numsPlus[n+1] = 1;

      for (int i = 1; i < n+1; i++)
      {
        numsPlus[i] = nums[i-1];
      }
      for (int size = 0; size < n; ++size)//size从0+1=1到n-1+1=n
      {
        for (int left = 0; left < n-size; ++left)//0号元素为1
        {
          int max = 0;
          for (int mid = 0; mid <= size; ++mid)
          {
            int Score = numsPlus[left]
                      * numsPlus[left + mid + 1] 
                      * numsPlus[left + size + 2];
            if(mid > 0)//mid以前有分数
              Score += maxScore[mid-1][left];
            if(size > mid)
              Score += maxScore[size - mid - 1][left + mid +1];
            if (Score > max)
            {
              max = Score;
            }
          }
          maxScore[size].push_back(max);
        }
      }
      return maxScore[n-1][0];
    }
};

TEST(maxCoins, maxCoins_1)
{
  Solution s;
  vector<int> in = {3, 1, 5, 8};
  int ans = 167;
  EXPECT_EQ(s.maxCoins(in), ans);
}

TEST(maxCoins, maxCoins_2)
{
  Solution s;
  vector<int> in = {1,5};
  int ans = 10;
  EXPECT_EQ(s.maxCoins(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
