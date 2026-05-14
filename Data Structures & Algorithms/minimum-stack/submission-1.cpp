class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(minimums.empty()) minimums.push(val);
        else if (minimums.top() > val) minimums.push(val);
        else minimums.push(minimums.top());
    }
    
    void pop() {
        s.pop();
        minimums.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minimums.top();
    }
private:
    stack<int> s;
    stack<int> minimums;
};
