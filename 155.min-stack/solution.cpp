class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        cache1.push(x);
        if (cache2.empty() || cache2.top() >= x)
            cache2.push(x);
    }

    void pop() {
        if (cache1.top() == cache2.top())
            cache2.pop();
        cache1.pop();
    }

    int top() {
        return cache1.top();
    }

    int getMin() {
        return cache2.top();
    }
private:
    stack<int> cache1;
    stack<int> cache2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
