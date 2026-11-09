class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        vector<int> count(k, 0);

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        int maxRequests = 0;

        for (int i = 0; i < arrival.size(); i++) {

            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty())
                continue;

            int target = i % k;

            auto it = available.lower_bound(target);

            if (it == available.end())
                it = available.begin();

            int server = *it;

            available.erase(it);

            count[server]++;
            maxRequests = max(maxRequests, count[server]);

            busy.push({arrival[i] + load[i], server});
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxRequests)
                ans.push_back(i);
        }

        return ans;
    }
};