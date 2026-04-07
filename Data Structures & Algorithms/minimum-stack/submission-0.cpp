class MinStack {
    multiset<int> sortedOrder;
    stack<int> st;
public:
    MinStack() {}
    
    void push(int val) {
        this->st.push(val);
        this->sortedOrder.insert(val);
    }
    
    void pop() {
        this->sortedOrder.erase(this->sortedOrder.find(st.top()));
        this->st.pop();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return *this->sortedOrder.begin();
    }
};
