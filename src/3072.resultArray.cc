#include "headers.h"

class Solution
{
  public:
    vector<int> resultArray(vector<int>& nums)
    {
      vector<int> arr1,arro1,arr2,arro2;

      arr1.push_back(nums[0]);
      arro1.push_back(nums[0]);
      arr2.push_back(nums[1]);
      arro2.push_back(nums[1]);

      for(int i = 2; i < nums.size(); ++i)
      {
        auto it1 = lower_bound(arro1.begin(),arro1.end(), nums[i], greater<int>());
        auto it2 = lower_bound(arro2.begin(),arro2.end(), nums[i], greater<int>());
        int n1 = it1 - arro1.begin(), n2 = it2 - arro2.begin();
        auto *pA = &arr1, *pAo = &arro1;
        auto *pI = &it1;
        
        if(n1 < n2 || (n1 == n2 && arr1.size() > arr2.size()))
        {
          pA = &arr2;
          pAo = &arro2;
          pI = &it2;
        }
        pA->push_back(nums[i]);
        pAo->insert(*pI, nums[i]);
      }
      arr1.insert(arr1.end(), arr2.begin(), arr2.end());

      return arr1;
    }
};

TEST(resultArray, resultArray_1)
{
    Solution s;
    vector<int> in = {2, 1, 3, 3};
    vector<int> ans = {2, 3, 1, 3};
    EXPECT_EQ(s.resultArray(in), ans);
}

TEST(resultArray, resultArray_2)
{
    Solution s;
    vector<int> in = {5,14,3,1,2};
    vector<int> ans = {5,3,1,2,14};
    EXPECT_EQ(s.resultArray(in), ans);
}

TEST(resultArray, resultArray_3)
{
    Solution s;
    vector<int> in = {3,3,3,3};
    vector<int> ans = {3,3,3,3};
    EXPECT_EQ(s.resultArray(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
