class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!store.count(key)) return "";
        auto& pairs = store[key];
        int i = 0, j = pairs.size() - 1;
        string res = "";
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (pairs[mid].first <= timestamp) {
                res = pairs[mid].second;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return res;
    }
};
