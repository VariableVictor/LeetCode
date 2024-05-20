#include "headers.h"

class Solution
{
public:
    //int maxProfitAssignment(vector<int> &nums)
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
  {
    vector<vector<int>> jobs({{difficulty[0], profit[0]}});
    int sum(0);
                             
    if(profit.size()==0)
      return 0;

    for(int i = 1; i < difficulty.size();++i)//fill jobs sort by profit in descending order
    {
      auto low_job = lower_bound(jobs.begin(), jobs.end(), profit[i], [&](vector<int>& i, int x) -> bool
          {return i[1] > x;});
      if(jobs.end() == low_job || profit[i] > low_job[0][1])
      {
        jobs.insert(low_job,{difficulty[i], profit[i]});
      }
      else if(difficulty[i] < low_job[0][0])
      {
        low_job[0][0] = difficulty[i];
      }
    }
    for(auto j =jobs.begin(); j+1 != jobs.end(); ++j)
    {
      if(j[1][0] > j[0][0])
      {
        jobs.erase(j+1);
        --j;
      }
    }

    for(auto w : worker)
    {
      auto wi = lower_bound(jobs.begin(), jobs.end(), w, [&](vector<int>& i, int x) -> bool
          {return i[0] > x;} );
      if(wi != jobs.end())
          sum += wi[0][1];
    }
    return sum;
  }
};

TEST(maxProfitAssignment, maxProfitAssignment_1)
{
    Solution s;
    vector<int> ind = {2, 4, 6, 8, 10};
    vector<int> inp = {10, 20, 30, 40, 50};
    vector<int> inw = {4, 5, 6, 7};
    int ans = 100;
    EXPECT_EQ(s.maxProfitAssignment(ind, inp, inw), ans);
}

TEST(maxProfitAssignment, maxProfitAssignment_2)
{
    Solution s;
    vector<int> ind = {85, 47, 57};
    vector<int> inp = {24,66,99};
    vector<int> inw = {40,25,25};
    int ans = 0;
    EXPECT_EQ(s.maxProfitAssignment(ind, inp, inw), ans);
}

TEST(maxProfitAssignment, maxProfitAssignment_3)
{
    Solution s;
    vector<int> ind = {5,50,92,21,24,70,17,63,30,53};
    vector<int> inp = {68,100,3,99,56,43,26,93,55,25};
    vector<int> inw = {96,3,55,30,11,58,68,36,26,1};
    int ans = 765;
    EXPECT_EQ(s.maxProfitAssignment(ind, inp, inw), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
