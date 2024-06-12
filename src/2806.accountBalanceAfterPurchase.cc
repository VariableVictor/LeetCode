#include "headers.h"

class Solution
{
public:
  int accountBalanceAfterPurchase(int purchaseAmount)
  {
    return 100 - 10*round(purchaseAmount / 10.0);
  }
};

TEST(accountBalanceAfterPurchase, accountBalanceAfterPurchase_1)
{
    Solution s;
    int in = 9;
    int ans = 90;
    EXPECT_EQ(s.accountBalanceAfterPurchase(in), ans);
}

TEST(accountBalanceAfterPurchase, accountBalanceAfterPurchase_2)
{
    Solution s;
    int in = 15;
    int ans = 80;
    EXPECT_EQ(s.accountBalanceAfterPurchase(in), ans);
}

TEST(accountBalanceAfterPurchase, accountBalanceAfterPurchase_3)
{
    Solution s;
    int in = 13;
    int ans = 90;
    EXPECT_EQ(s.accountBalanceAfterPurchase(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
