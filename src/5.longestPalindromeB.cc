#include "headers.h"

class Solution
{
public:
  string longestPalindrome(string s)
  {
    for(int iS = s.size(); iS > 0; --iS)
    {
      for(int i = 0; i < s.size()-iS+1; ++i)
      {
        int iSS = iS, iI = i;
        while(s[iI] == s[iI + iSS -1])
        {
          if(iSS < 2)
            return s.substr(i, iS);
          iSS -= 2;
          ++iI;
        }
      }
    }
    return s.substr(0, 1);
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
