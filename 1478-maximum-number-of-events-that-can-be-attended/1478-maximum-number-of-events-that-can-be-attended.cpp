class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end()); // sort by startDay
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), res = 0;
        int day = 1;

        while (i < n || !pq.empty()) {
            // Add events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]); // add endDay
                i++;
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend event that ends earliest
            if (!pq.empty()) {
                pq.pop();
                res++;
            }

            day++;
        }
        return res;
    }
};
