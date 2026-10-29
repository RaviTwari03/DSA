class Solution {
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;
    string s;

    int charMask(char c) {
        return 1 << (c - 'a');
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;

        for (int j = 1; j < LOG; j++)
            up[j][u] = up[j - 1][up[j - 1][u]];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    void add(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int get(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (diff & (1 << j))
                u = up[j][u];

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        this->n = n;
        this->s = s;
        LOG = 1;

        while ((1 << LOG) <= n)
            LOG++;

        timer = 0;
        adj.assign(n, {});
        up.assign(LOG, vector<int>(n, 0));
        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        bit.assign(n + 1, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, 0);

        for (int u = 0; u < n; u++) {
            int val = charMask(s[u]);
            add(tin[u], val);

            if (tout[u] < n)
                add(tout[u] + 1, val);
        }

        vector<bool> ans;

        for (string& q : queries) {
            string type, third;
            int u;

            stringstream ss(q);
            ss >> type >> u >> third;

            if (type == "update") {
                char c = third[0];
                int delta = charMask(s[u]) ^ charMask(c);

                if (delta != 0) {
                    add(tin[u], delta);

                    if (tout[u] < n)
                        add(tout[u] + 1, delta);

                    s[u] = c;
                }
            } else {
                int v = stoi(third);
                int w = lca(u, v);

                int pathMask = get(tin[u]) ^ get(tin[v]) ^ charMask(s[w]);

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
