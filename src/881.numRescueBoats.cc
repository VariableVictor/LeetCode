#include "headers.h"

class Solution
{
  public:
    int numRescueBoats(vector<int>& people, int limit)
    {
      ranges::sort(people);
      int ans = 0;
      int light = 0,heavy = people.size() - 1;
      while(light <= heavy)
      {
        if(people[heavy] +people[light] > limit)
        {
          --heavy;
        }
        else
        {
          ++light;
          --heavy;
        }
        ++ans;
      }

      return ans;
    }
};

TEST(numRescueBoats, numRescueBoats_1)
{
  Solution s;
  vector<int> inp = {1, 2};
  int inl = 3;
  int ans = 1;
  EXPECT_EQ(s.numRescueBoats(inp, inl), ans);
}

TEST(numRescueBoats, numRescueBoats_2)
{
  Solution s;
  vector<int> inp = {3, 2, 2, 1};
  int inl = 3;
  int ans = 3;
  EXPECT_EQ(s.numRescueBoats(inp, inl), ans);
}

TEST(numRescueBoats, numRescueBoats_3)
{
  Solution s;
  vector<int> inp = {3, 5, 3, 4};
  int inl = 5;
  int ans = 4;
  EXPECT_EQ(s.numRescueBoats(inp, inl), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
