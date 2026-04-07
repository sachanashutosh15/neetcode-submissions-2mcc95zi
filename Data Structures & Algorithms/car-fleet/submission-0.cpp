class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> p_s_map;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            p_s_map[position[i]] = speed[i];
        }
        stack<double> st;
        for (auto it = p_s_map.rbegin(); it != p_s_map.rend(); it++) {
            int pos = it->first, speed = it->second;
            double t = (target - pos) / (double) speed;
            if (st.empty() || st.top() < t) {
                st.push(t);
            }
        }
        return st.size();
    }
};
