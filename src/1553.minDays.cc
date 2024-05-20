#include "headers.h"

class Solution
{
public:
    int minDays(int n)
    {
      if(n <= 1)
        return 1;
      if(0 == n % 3)
        return 1 + minDays(n / 3);
      if(0 == n % 2)
        return 1 + minDays(n / 2);
      return 1 + minDays(n - 1);
    }
};

TEST(minDays, minDays_1)
{
    Solution s;
    int in = 10;
    int ans = 4;
    EXPECT_EQ(s.minDays(in), ans);
}

//TEST(minDays, minDays_2)
//{
//    Solution s;
//    int in = 6;
//    int ans = 3;
//    EXPECT_EQ(s.minDays(in), ans);
//}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
