#include <iostream>
#include <stack>

using namespace std;


class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
        
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s1.empty())
        {
            return -1;
        }
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
};

/*
    众数 答案

    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (!s2.empty()){
            int result=s2.top();
            s2.pop();
            return result;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int result=-1;
        if (!s2.empty()){
            result=s2.top();
            s2.pop();
        }
        return result;
    }

*/