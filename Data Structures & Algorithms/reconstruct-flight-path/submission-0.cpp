class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        Graph adj;    
        for (auto& t: tickets) {
            adj[t[0]].push(t[1]);
        }
        vector<string> res;
        dfs("JFK", res, adj);
        reverse(res.begin(), res.end());
        return res;
    }
private:
    using StrMinHeap = priority_queue<string, vector<string>, greater<>>;
    using Graph = unordered_map<string, StrMinHeap>;
    void dfs(string city, vector<string>& res, Graph& adj) {
        auto& pq = adj[city];
        while (!pq.empty()) {
            string nbr = pq.top(); pq.pop();
            dfs(nbr, res, adj);
        }
        res.push_back(city);
    }
};
