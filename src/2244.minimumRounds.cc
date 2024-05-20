#include "headers.h"

class Solution
{
  public:
    int minimumRounds(vector<int>& tasks)
    {
      unordered_map<int,int> mCnt;
      for( int iN: tasks)
      {
        ++mCnt[iN];
      }
      int iSum = 0;
      
      for(auto [_, iC] : mCnt)
      {
        if(1 == iC) 
        {
          return -1;
        }
        iSum += (iC + 2) / 3;
      }
      return iSum;
    }
};

TEST(minimumRounds, minimumRounds_1)
{
  Solution s;
  vector<int> in = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};
  int ans = 4;
  EXPECT_EQ(s.minimumRounds(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
