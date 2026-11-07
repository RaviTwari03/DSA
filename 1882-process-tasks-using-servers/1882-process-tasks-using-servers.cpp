class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using ll = long long;

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> available;

        priority_queue<tuple<ll, int, int>,
            vector<tuple<ll, int, int>>,
            greater<tuple<ll, int, int>>> busy;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);
        ll time = 0;

        for (int i = 0; i < m; i++) {
            time = max(time, (ll)i);

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, idx] = busy.top();
                busy.pop();
                available.push({weight, idx});
            }

            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, idx] = busy.top();
                    busy.pop();
                    available.push({weight, idx});
                }
            }

            auto [weight, idx] = available.top();
            available.pop();

            ans[i] = idx;

            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};
