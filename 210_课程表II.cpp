#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        int** matrix = new int*[numCourses];
        for (int i = 0; i < numCourses; i++ ){
            matrix[i] = new int[numCourses];
            memset(matrix[i], 0, sizeof(int)*numCourses);
        }
        int* degree = new int[numCourses];
        memset(degree, 0, sizeof(int)*numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            matrix[prerequisites[i][1]][prerequisites[i][0]] = 1;
            degree[prerequisites[i][0]] ++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if (!degree[i]) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int front = q.front();
            // cout << front << endl;
            q.pop();
            ans.push_back(front);
            for (int i = 0; i < numCourses; i++) {
                if (matrix[front][i]) {
                    int pos = i;
                    degree[pos] --;
                    if (degree[pos] == 0) {
                        matrix[front][i] = 0;
                        q.push(pos);
                    }
                }
            }
        }
        if (ans.size() != numCourses) {
            ans.clear();
        }

        // for (int i = 0; i < numCourses; i++){
        //     cout << degree[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < numCourses; i++) {
        //     for (int j = 0; j < numCourses; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return ans;
    }
};