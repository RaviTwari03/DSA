class Solution {
public:
    void bfs(int src, vector<vector<int>>& adj, vector<int>& dist) {
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dx(n, -1), dy(n, -1), dz(n, -1);

        bfs(x, adj, dx);
        bfs(y, adj, dy);
        bfs(z, adj, dz);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int a = dx[i], b = dy[i], c = dz[i];
            int p[3] = {a, b, c};
            sort(p, p + 3);

            if (1LL * p[0] * p[0] + 1LL * p[1] * p[1] == 1LL * p[2] * p[2]) {
                ans++;
            }
        }

        return ans;
    }
};
