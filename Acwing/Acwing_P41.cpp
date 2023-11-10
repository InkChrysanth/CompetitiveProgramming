// Problem: 包含min函数的栈
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/90/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(mins.empty() || x<=mins.top())
            mins.push(x);
    }
    
    void pop() {
        if(s.top()==mins.top()) mins.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};