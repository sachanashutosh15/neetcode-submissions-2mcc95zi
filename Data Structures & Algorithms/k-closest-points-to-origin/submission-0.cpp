class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> maxHeap;
        for (vector<int>& point: points) {
            int x = point[0], y = point[1];
            double dist = sqrt(x * x + y * y);
            maxHeap.push({dist, {x, y}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
