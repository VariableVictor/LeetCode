#include "headers.h"

class Solution
{
  public:
    string longestPalindrome(string s)
    {
      int n = s.length();
      if (n < 2)
      {
        return s;
      }
      queue<pair<int,int>> dp;
      
      for (int i = 0; i < n; ++i)
      {
        dp.push({i,1});
      }
      for (int i = 0; i < n-1; ++i)
      {
        if (s[i] == s[i+1])
        {
          dp.push({i,2});
        }
      }
      auto maxsize = dp.back();
      while(!dp.empty())
      {
        int head = dp.front().first;
        int size = dp.front().second;
        dp.pop();
        if (head > 0 && head + size < n )
        {
          --head;
          size += 2;
          if(s[head] == s[head + size -1])
          {
            dp.push({head,size});
            if (size> maxsize.second)
            {
              maxsize = dp.back();
            }
          }
        }
      }
      return s.substr(maxsize.first, maxsize.second);
    }
};

TEST(longestPalindrome, longestPalindrome_1)
{
    Solution s;
    string in = "babad";
    string ans = "bab";
    EXPECT_EQ(s.longestPalindrome(in), ans);
}

TEST(longestPalindrome, longestPalindrome_2)
{
    Solution s;
    string in = "cbbd";
    string ans = "bb";
    EXPECT_EQ(s.longestPalindrome(in), ans);
}

TEST(longestPalindrome, longestPalindrome_3)
{
    Solution s;
    string in = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
    string ans = "qosoq";
    EXPECT_EQ(s.longestPalindrome(in), ans);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
