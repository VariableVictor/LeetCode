#include "headers.h"

class Solution
{
public:
    int findMinimumTime(vector<vector<int>>& tasks)
    {
      sort( tasks.begin(), 
            tasks.end(),
            [&](vector<int>&a, vector<int>&b) -> bool 
          { return a[1] < b[1];} );
      
      vector<vector<int>> st;
      st.push_back({-1, -1, 0});

      for(auto &task : tasks)
      {
        auto low = lower_bound(st.begin(), st.end(), task[0],
            [&](vector<int>& run, int x) -> bool{
            return run[0] < x;
            });

        --low;

        task[2] -= st.back()[2] - low[0][2];

        if(task[0] <= low[0][1])
        {
          task[2] -= low[0][1] - task[0] + 1;
        }

        if(task[2] <= 0)
        {
          continue;
        }

        while(task[1] - st.back()[1] <= task[2])
        {
          task[2] += st.back()[1] - st.back()[0] + 1;
          st.pop_back();
        }

        st.push_back({task[1] - task[2] + 1, task[1], st.back()[2] + task[2]});

      }
        return st.back()[2];
    }
};

TEST(findMinimumTime, findMinimumTime_1)
{
    Solution s;
    vector<vector<int>> in = {{2, 3, 1},
                      {4, 5, 1},
                      {1, 5, 2}};
    int ans = 2;
    EXPECT_EQ(s.findMinimumTime(in), ans);
}

TEST(findMinimumTime, findMinimumTime_2)
{
    Solution s;
    vector<vector<int>> in = {{1, 18, 5},
                      {3, 15, 1}};
    int ans = 5;
    EXPECT_EQ(s.findMinimumTime(in), ans);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
