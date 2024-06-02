#include "headers.h"

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
      int half = candyType.size() / 2;
      unordered_set<int> cSet; 
      int count = 0;
      for(auto can : candyType)
      {
        if(!cSet.contains(can))
        {
          cSet.insert(can);
          ++count;
        }
        if(count > half)
          return half;
      }
        return count;
    }
};

TEST(distributeCandies, distributeCandies_1)
{
    Solution s;
    vector<int> in = {1,1,2,2,3,3};
    int ans = 3;
    EXPECT_EQ(s.distributeCandies(in), ans);
}

TEST(distributeCandies, distributeCandies_2)
{
    Solution s;
    vector<int> in = {1,1,2,3};
    int ans = 2;
    EXPECT_EQ(s.distributeCandies(in), ans);
}

TEST(distributeCandies, distributeCandies_3)
{
    Solution s;
    vector<int> in = {6,6,6,6};
    int ans = 1;
    EXPECT_EQ(s.distributeCandies(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
