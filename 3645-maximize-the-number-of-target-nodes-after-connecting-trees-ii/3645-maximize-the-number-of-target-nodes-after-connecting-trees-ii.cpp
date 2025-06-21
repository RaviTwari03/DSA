class Solution {
public:
    void dfs(int node, int color, vector<vector<int>>& adj, vector<int>& colors, int& count0, int& count1) {
        colors[node] = color;
        if (color == 0) count0++;
        else count1++;

        for (int nei : adj[node]) {
            if (colors[nei] == -1) {
                dfs(nei, 1 - color, adj, colors, count0, count1);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);

        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> color1(n, -1), color2(m, -1);
        int cnt1_0 = 0, cnt1_1 = 0, cnt2_0 = 0, cnt2_1 = 0;

        dfs(0, 0, adj1, color1, cnt1_0, cnt1_1);
        dfs(0, 0, adj2, color2, cnt2_0, cnt2_1);

        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            // node i has color color1[i]
            if (color1[i] == 0) {
                // option 1: connect to color-0 node in tree2 → total even nodes = cnt1_0 + cnt2_0
                // option 2: connect to color-1 node in tree2 → total even nodes = cnt1_0 + cnt2_1
                res[i] = max(cnt1_0 + cnt2_0, cnt1_0 + cnt2_1);
            } else {
                res[i] = max(cnt1_1 + cnt2_0, cnt1_1 + cnt2_1);
            }
        }

        return res;
    }
};
