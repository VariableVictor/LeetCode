#include "headers.h"

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
      int times = (int)(sqrt(candies * 2.0 + 0.25) - 0.5);
      int rounds = times / num_people;
      vector<int> ans(num_people);
      
      for(int i = 0; i < num_people; ++i)
      {
        ans[i] = (i+1) * rounds + (rounds - 1) * rounds * num_people / 2;
        if(times % num_people > i)
        {
          ans[i] += i + 1 + rounds * num_people;
        }
      }
      ans[times%num_people] += candies - (times + 1) * times / 2;
      return ans;
    }
};

TEST(distributeCandies, distributeCandies_1)
{
    Solution s;
    int inc = 7, inn = 4;
    vector<int> ans = {1,2,3,1};
    EXPECT_EQ(s.distributeCandies(inc, inn), ans);
}

TEST(distributeCandies, distributeCandies_2)
{
    Solution s;
    int inc = 10, inn = 3;
    vector<int> ans = {5,2,3};
    EXPECT_EQ(s.distributeCandies(inc, inn), ans);
}

TEST(distributeCandies, distributeCandies_3)
{
    Solution s;
    int inc = 60, inn = 4;
    vector<int> ans = {15,18,15,12};
    EXPECT_EQ(s.distributeCandies(inc, inn), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
