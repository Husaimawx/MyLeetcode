#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 回溯

// class Solution 
// {
// public:
//     bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) 
//     {
//         unordered_map<int, vector<int>> adjvex; //邻接表
//         for (auto & v: edges)
//             adjvex[v[0]].push_back(v[1]);
//         if (adjvex.count(destination) > 0)  //终点还有后继结点，必不行
//             return false;
//         vector<bool> visited(n, false);     //记忆化

//         std::function<bool (int)> backtrace = [&] (int x)
//         {
//             if (adjvex.count(x) == 0)       //是叶节点
//                 return x == destination;
//             for (int & y: adjvex[x])
//             {
//                 if (visited[y] == true)     //之前已经visit了，有环
//                     return false;
//                 visited[y] = true;          //借
//                 if (backtrace(y) == false)
//                     return false;
//                 visited[y] = false;         //回溯。有借有还
//             }
//             return true;
//         };
//         visited[source] = true;             //从source出发
//         return backtrace(source);
//     }
// };