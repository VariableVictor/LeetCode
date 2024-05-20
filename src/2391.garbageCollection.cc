#include "headers.h"

class Solution
{
  public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel)
    {
      vector<int> vT4travel = {0,0,0};
      vector<int> vT4garbage = {0,0,0};
      travel.insert(travel.begin(),0);
      int itravel = 0;
      for(int i = 0; i < garbage.size(); ++i)
      {
        itravel += travel[i];
        //std::cout << i << std::endl;
        //std::cout << garbage[i] << std::endl;
        for(char cG : garbage[i])
        {
          switch(cG)
          {
            case 'M':
              vT4travel[0] = itravel;
              (vT4garbage[0])++;
              break;
            case 'P':
              vT4travel[1] = itravel;
              (vT4garbage[1])++;
              break;
            case 'G':
              vT4travel[2] = itravel;
              (vT4garbage[2])++;
              break;
            default:
              break;
          }
        }
      }

      itravel = 0;

      for(int it : vT4travel)
      {
        //std::cout << it <<", ";
        itravel += it;
      }
      for(int ig : vT4garbage)
      {
        //std::cout << ig <<", ";
        itravel += ig;
      }

      return itravel;
    }
};

TEST(garbageCollection, garbageCollection_1)
{
    Solution s;
    vector<string> garbagein = {"G","P","GP","GG"};
    vector<int> travelin = {2, 4, 3};
    int ans = 21;
    EXPECT_EQ(s.garbageCollection(garbagein,travelin), ans);
}

TEST(garbageCollection, garbageCollection_2)
{
    Solution s;
    vector<string> garbagein = {"MMM","PGM","GP"};
    vector<int> travelin = {3, 10};
    int ans = 37;
    EXPECT_EQ(s.garbageCollection(garbagein,travelin), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
