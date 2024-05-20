#include "headers.h"

class Solution
{
public:
    bool OrangeWillRot(vector<vector<int>> &grid, int i, int j)
    {
      if(0 < i && 2 == grid[i-1][j])
      {
        return true;
      }
      if(grid.size() - 1 > i && 2 == grid[i+1][j])
      {
        return true;
      }
      if(0 < j && 2 == grid[i][j-1])
      {
        return true;
      }
      if(grid[0].size() - 1 > j && 2 == grid[i][j+1])
      {
        return true;
      }
      return false;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
      int iMinute = 0;
      int iRotten = 0, iFresh = 0;
      if(0 == grid.size() || 0 == grid[0].size())
      {
        return 0;
      }

      do
      {
        vector<vector<int>> newgrid = grid;
        iRotten = 0;
        iFresh = 0;
        for(int iRow = 0; iRow < grid.size(); ++iRow)
        {
          for(int iCol = 0; iCol < grid[0].size(); ++iCol)
          {
            switch(grid[iRow][iCol])
            {
              case 0:
              case 2:
                continue;
              case 1:
                if(OrangeWillRot(grid,iRow,iCol))
                {
                  newgrid[iRow][iCol] = 2;
                  ++iRotten;
                }
                else
                {
                  ++iFresh;
                }
                break;
              default:
                return -1;
            }
          }
        }

        /*
        std::cout << "iMinute " << iMinute << std::endl << std::endl;
        for(int iRow = 0; iRow < grid.size(); ++iRow)
        {
          for(int iCol = 0; iCol < grid[0].size(); ++iCol)
          {
            std::cout << grid[iRow][iCol] << ",";
          }
          std::cout << std::endl;
        }

        std::cout << std::endl;

        for(int iRow = 0; iRow < grid.size(); ++iRow)
        {
          for(int iCol = 0; iCol < grid[0].size(); ++iCol)
          {
            std::cout << newgrid[iRow][iCol] << ",";
          }
          std::cout << std::endl;
        }
        */
        grid = newgrid;
        ++iMinute;
      }
      while (0 < iRotten);
      if(0 < iFresh)
      {
        return -1;
      }
      return iMinute - 1;
    }
};

TEST(orangesRotting, orangesRotting_1)
{
    Solution s;
    vector<vector<int>> in = {
      {2, 1, 1},
      {1, 1, 0},
      {0, 1, 1}
    };
    int ans = 4;
    EXPECT_EQ(s.orangesRotting(in), ans);
}

TEST(orangesRotting, orangesRotting_2)
{
    Solution s;
    vector<vector<int>> in = {
      {2, 1, 1},
      {0, 1, 1},
      {1, 0, 1}
    };
    int ans = -1;
    EXPECT_EQ(s.orangesRotting(in), ans);
}

TEST(orangesRotting, orangesRotting_3)
{
    Solution s;
    vector<vector<int>> in = {{0, 2}};
    int ans = 0;
    EXPECT_EQ(s.orangesRotting(in), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
