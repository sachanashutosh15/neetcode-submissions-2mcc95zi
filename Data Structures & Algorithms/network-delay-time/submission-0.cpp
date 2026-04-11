class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t: times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        vector<int> reachTimes(n + 1, INT_MAX);
        reachTimes[k] = 0;
        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();
            if (time > reachTimes[node]) continue;
            for (auto& [nbr, wt]: adj[node]) {
                int nTime = time + wt;
                if (reachTimes[nbr] > nTime) {
                    reachTimes[nbr] = nTime;
                    pq.push({reachTimes[nbr], nbr});
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (reachTimes[i] == INT_MAX) return -1;
            res = max(reachTimes[i], res);
        }
        return res;
    }
};
