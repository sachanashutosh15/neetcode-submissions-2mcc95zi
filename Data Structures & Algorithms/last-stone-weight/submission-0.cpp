class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int wt: stones) {
            maxHeap.push(wt);
        }
        while(!maxHeap.empty() && maxHeap.size() != 1) {
            int a = maxHeap.top(); maxHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();
            int remWt = abs(a - b);
            if (remWt > 0) maxHeap.push(remWt);
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
