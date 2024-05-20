#include "headers.h"

class Solution
{
public:

  int recvOddPalidrom(string s, int i, int j)
  {
    if( i < j ||
        s.size() <= i + j ||
        s[i-j] != s[i+j])
    {
      return j - 1;
    }
    return recvOddPalidrom(s, i, j+1);
  }

  int recvEvenPalidrom(string s, int i, int j)
  {
    if( i < j ||
        s.size() <= i + j + 1 ||
        s[i-j] != s[i+j+1])
    {
      return j - 1;
    }
    return recvEvenPalidrom(s, i, j+1);
  }

  string longestPalindrome(string s)
  {
    int iMin = 0, iMax = 0;
    for(int i = 0; i < s.size(); ++i)
    {
      int jL,jH;
      int jE = recvEvenPalidrom(s, i, 0);
      int jO = recvOddPalidrom(s, i, 0);

      if (jE < jO)
      {
        jL = i - jO;
        jH = i + jO;
      }
      else
      {
        jL = i - jE;
        jH = i + jE + 1;
      }

      if(jH - jL > iMax - iMin)
      {
        iMax = jH;
        iMin = jL;
      }
    }
    return s.substr(iMin, iMax - iMin + 1);
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
