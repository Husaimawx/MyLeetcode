#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 着色问题，BFS

class Solution {
public:
    bool isBipartite(vector<vector<int> >& graph) {
        int n = graph.size();
        if (n == 0) {
            return true;
        }
        int* colors = new int[n+1];
        memset(colors, 0, sizeof(int)* (n+1));
        queue<int> q;
        for (int i = 0; i < n; i ++ ){
            if (colors[i] != 0){
                continue;
            }
            q.push(i);
            colors[i] = 1;
            while (!q.empty()) {
                int cur_size = q.size();
                for (int i = 0; i < cur_size; i++) {
                    int front = q.front();
                    q.pop();
                    int color = colors[front];
                    int size = graph[front].size();
                    for (int i = 0; i < size; i++) {
                        int next = graph[front][i];
                        if (colors[next] == color) {
                            return false;
                        }
                        if (colors[next] == 0) {
                            q.push(next);
                            if (color == 1) {
                                colors[next]= 2;
                            }
                            else {
                                colors[next] = 1;
                            }
                        }
                    }   
                }
            }
        }
        return true;
    }
};