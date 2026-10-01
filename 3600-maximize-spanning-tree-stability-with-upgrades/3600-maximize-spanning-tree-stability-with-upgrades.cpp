class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    bool check(int n, vector<vector<int>>& edges, int k, int x) {
        parent.resize(n);
        sz.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);

        // 1. Mandatory edges
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            int must = e[3];

            if (must == 1) {
                if (s < x)
                    return false;

                // Mandatory edge creates cycle
                if (!unite(u, v))
                    return false;
            }
        }

        // 2. Optional edges that already satisfy X
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            int must = e[3];

            if (must == 0 && s >= x) {
                unite(u, v);
            }
        }

        // 3. Optional edges that need an upgrade
        int upgrades = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int s = e[2];
            int must = e[3];

            if (must == 0 && s < x && 2 * s >= x) {
                if (unite(u, v)) {
                    upgrades++;

                    if (upgrades > k)
                        return false;
                }
            }
        }

        // Check if graph is connected
        int root = find(0);

        for (int i = 1; i < n; i++) {
            if (find(i) != root)
                return false;
        }

        return true;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo = 1;
        int hi = 200000;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(n, edges, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};