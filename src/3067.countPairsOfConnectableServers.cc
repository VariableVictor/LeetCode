#include "headers.h"

class Solution
{
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
      vector<unordered_map<int,int>> vertices(edges.size()+1);
      for(auto eg : edges)
      {
        vertices[eg[0]][eg[1]] = eg[2];
        vertices[eg[1]][eg[0]] = eg[2];
      }
      vector<int> ans;
      for(int i = 0; i <= edges.size(); ++i)
      {
        int cn = vertices[i].size();//childs number
        vector<int> childs(0);
        for(auto r : vertices[i])
        {
          queue<pair<int,int>> Qu;
          unordered_set<int> pcd = {i};//produced
          int count = 0;
          Qu.push(r);
          pcd.insert(r.first);
          while(!Qu.empty())//BFS
          {
            auto j = Qu.front();
            Qu.pop();
            if(0 == j.second % signalSpeed)
            {
              ++count;
            }
            for(auto n : vertices[j.first])
            {
              if(!pcd.contains(n.first))
              {
                pcd.insert(n.first);

                n.second += j.second;
                Qu.push(n);
              }
            }
          }
          childs.push_back(count);
        }
        int sum = 0;
        for(int e :childs)
        {
          sum += e;
        }
        int res = 0;
        for(int e :childs)
        {
          res += e * (sum - e);
        }
        res /= 2;
        ans.push_back(res);
      }
      return ans;
    }
};

TEST(countPairsOfConnectableServers, countPairsOfConnectableServers_1)
{
    Solution s;
    vector<vector<int>> in = {{0,1,1},{1,2,5},{2,3,13},{3,4,9},{4,5,2}};
    int ins = 1;
    vector<int> ans = {0,4,6,6,4,0};
    EXPECT_EQ(s.countPairsOfConnectableServers(in, ins), ans);
}

TEST(countPairsOfConnectableServers, countPairsOfConnectableServers_2)
{
    Solution s;
    vector<vector<int>> in = {{0,6,3},{6,5,3},{0,3,1},{3,2,7},{3,1,6},{3,4,2}};
    int ins = 3;
    vector<int> ans = {2,0,0,0,0,0,2};
    EXPECT_EQ(s.countPairsOfConnectableServers(in, ins), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
