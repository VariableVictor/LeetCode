#include "headers.h"

class Solution
{
  public:
    long long findMaximumElegance(vector<vector<int>>& items, int k)
    {
      ranges::sort(items,[](auto &a, auto &b)->bool {
          return a[0] > b[0];
          });
      int n = items.size();
      long long pf_sum = 0,ans = 0;
      unordered_set<int> cates;
      stack<int> selects;
      for (int i = 0; i < k; i++)
      {
        int pf = items[i][0];
        int ca = items[i][1];
        pf_sum += pf;
        if (cates.contains(ca))
        {
          selects.push(pf);
        }
        else
        {
          cates.insert(ca);
        }
      }
      ans = pf_sum + cates.size() * cates.size();
      for (int i = k; i < n; i++)
      {
        int pf = items[i][0];
        int ca = items[i][1];

        if (cates.contains(ca))
        {
          continue;
        }
        if (0 == selects.size())
          break;
        int inc = cates.size() * 2 + 1;
        pf_sum += pf - selects.top();
        selects.pop();
        cates.insert(ca);
        ans = max(ans, (long long)(pf_sum + cates.size() * cates.size()));
      }
      return ans;
    }
};

TEST(findMaximumElegance, findMaximumElegance_1)
{
  Solution s;
  vector<vector<int>> in = {{3,2},{5,1},{10,1}};
  int ink = 2;
  long long ans = 17;
  EXPECT_EQ(s.findMaximumElegance(in, ink), ans);
}

TEST(findMaximumElegance, findMaximumElegance_2)
{
  Solution s;
  vector<vector<int>> in = {{3,1},{3,1},{2,2},{5,3}};
  int ink = 3;
  long long ans = 19;
  EXPECT_EQ(s.findMaximumElegance(in, ink), ans);
}

TEST(findMaximumElegance, findMaximumElegance_3)
{
  Solution s;
  vector<vector<int>> in = {{1,1},{2,1},{3,1}};
  int ink = 3;
  long long ans = 7;
  EXPECT_EQ(s.findMaximumElegance(in, ink), ans);
}

TEST(findMaximumElegance, findMaximumElegance_4)
{
  Solution s;
  vector<vector<int>> in = {{1,2},{10,1}};
  int ink = 1;
  long long ans = 11;
  EXPECT_EQ(s.findMaximumElegance(in, ink), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
