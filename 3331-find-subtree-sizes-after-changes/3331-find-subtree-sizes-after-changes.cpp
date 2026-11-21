class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> original(n);
        for (int i = 1; i < n; i++) {
            original[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);

        function<void(int)> dfs1 = [&](int node) {
            int c = s[node] - 'a';
            int prev = last[c];

            if (prev != -1)
                newParent[node] = prev;

            last[c] = node;

            for (int child : original[node]) {
                dfs1(child);
            }

            last[c] = prev; 
        };

        dfs1(0);

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<int(int)> dfs2 = [&](int node) {
            int size = 1;

            for (int child : children[node]) {
                size += dfs2(child);
            }

            return ans[node] = size;
        };

        dfs2(0);
        return ans;
    }
};