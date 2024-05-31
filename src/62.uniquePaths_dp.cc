#include "headers.h"

class Solution
{
  public:
    inline unsigned Cood2UI(unsigned i, unsigned j)
    {
      return (i << 8) + j;
    }
    inline void UI2Cood(unsigned uUI, unsigned &i, unsigned &j)
    {
      i = uUI >> 8;
      j = uUI & 0xFF;
    }

    int uniquePaths_dp(int m, int n)
    {

      int iTP = m + n - 2;//TotalStep
      unordered_map<unsigned, int> moG[2];
      moG[0][0] = 1;
      for(int i = 0; i < iTP; ++i)
      {
        auto &m1 = moG[i % 2], &m2 = moG[(i + 1) % 2];
        for(auto nd : m1)
        {
          int value = nd.second;
          unsigned j,k;
          UI2Cood(nd.first, j, k);

          if(j < m - 1)
            if(m2.contains(Cood2UI(j+1,k)))
              m2[Cood2UI(j+1,k)] += value;
            else
              m2[Cood2UI(j+1,k)] = value;

          if(k < n - 1)
            if(m2.contains(Cood2UI(j,k+1)))
              m2[Cood2UI(j,k+1)] += value;
            else
              m2[Cood2UI(j,k+1)] = value;
        }
        m1.clear();
      }
      return moG[iTP % 2].begin()->second;
    }
};

TEST(uniquePaths_dp, uniquePaths_dp_1)
{
    Solution s;
    int inM = 3;
    int inN = 7;
    int ans = 28;
    EXPECT_EQ(s.uniquePaths_dp(inM, inN), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
