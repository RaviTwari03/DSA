class Solution {
public:
    struct Event {
        double y;
        int type;
        int xStart;
        int xEnd;

        Event(double _y, int _type, int _xStart, int _xEnd)
            : y(_y), type(_type), xStart(_xStart), xEnd(_xEnd) {}
    };

    vector<int> coverCount;
    vector<double> coveredLength;

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        set<int> xs;

        for (auto &sq : squares) {
            int x = sq[0];
            int y = sq[1];
            int size = sq[2];

            events.emplace_back(y, 1, x, x + size);
            events.emplace_back(y + size, -1, x, x + size);

            xs.insert(x);
            xs.insert(x + size);
        }

        vector<int> x(xs.begin(), xs.end());
        int n = x.size();

        sort(events.begin(), events.end(),
             [](const Event &a, const Event &b) {
                 return a.y < b.y;
             });

        coverCount.assign(4 * n, 0);
        coveredLength.assign(4 * n, 0.0);

        double totalArea = 0.0;
        double prevY = events[0].y;

        vector<array<double, 3>> parts;

        int i = 0;
        while (i < events.size()) {
            double currY = events[i].y;

            if (currY > prevY) {
                double height = currY - prevY;
                double width = coveredLength[1];
                totalArea += width * height;
                parts.push_back({prevY, currY, width});
                prevY = currY;
            }

            while (i < events.size() && events[i].y == currY) {
                auto &e = events[i];
                int left = lower_bound(x.begin(), x.end(), e.xStart) - x.begin();
                int right = lower_bound(x.begin(), x.end(), e.xEnd) - x.begin();
                updateTree(1, 0, n, left, right, e.type, x);
                i++;
            }
        }

        double half = totalArea / 2.0;
        double sum = 0.0;

        for (auto &part : parts) {
            double y1 = part[0];
            double y2 = part[1];
            double width = part[2];
            double area = width * (y2 - y1);

            if (sum + area >= half) {
                return y1 + (half - sum) / width;
            }
            sum += area;
        }

        return prevY;
    }

    void updateTree(int node, int start, int end,
                    int left, int right, int val,
                    vector<int>& x) {

        if (right <= start || end <= left) return;

        if (left <= start && end <= right) {
            coverCount[node] += val;
        } else {
            int mid = (start + end) / 2;
            updateTree(node * 2, start, mid, left, right, val, x);
            updateTree(node * 2 + 1, mid, end, left, right, val, x);
        }

        if (coverCount[node] > 0) {
            coveredLength[node] = x[end] - x[start];
        } else {
            if (end - start == 1) {
                coveredLength[node] = 0;
            } else {
                coveredLength[node] =
                    coveredLength[node * 2] + coveredLength[node * 2 + 1];
            }
        }
    }
};
