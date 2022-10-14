class MyQueue {
private:
    stack<int> s1, s2;
    void maintain() {
        if (s2.size() == 0) {
            while (s1.size() > 0) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        maintain();
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    int peek() {
        maintain();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */