#include "headers.h"

class Solution
{
public:
    long long numberOfWeeks(vector<int>& milestones)
    {
      long long Sum(0), Max(0);
      for(int ms :milestones)
      {
        Sum += ms;
        if (ms > Max)
          Max = ms;
      }
      if(Max > Sum - Max)
      {
        return (Sum - Max) * 2 + 1;
      }
        return Sum;
    }
};

TEST(numberOfWeeks, numberOfWeeks_1)
{
    Solution s;
    vector<int> in = {1, 2, 3};
    int ans = 6;
    EXPECT_EQ(s.numberOfWeeks(in), ans);
}

TEST(numberOfWeeks, numberOfWeeks_2)
{
    Solution s;
    vector<int> in = {5, 2, 1};
    int ans = 7;
    EXPECT_EQ(s.numberOfWeeks(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
