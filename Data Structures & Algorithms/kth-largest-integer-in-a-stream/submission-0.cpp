class KthLargest {
    priority_queue<int> maxHeap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            maxHeap.push(nums[i]);
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        stack<int> st;
        int t = k;
        while (t-- > 1) {
            st.push(maxHeap.top());
            maxHeap.pop();
        }
        int res = maxHeap.top();
        while(!st.empty()) {
            maxHeap.push(st.top());
            st.pop();
        }
        return res;
    }
};
