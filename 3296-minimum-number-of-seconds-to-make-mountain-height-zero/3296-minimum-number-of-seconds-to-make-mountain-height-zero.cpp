class Solution {
public:
    bool check(long long T, int mountainHeight, vector<int>& workerTimes) {
        long long total = 0;

        for (long long t : workerTimes) {
            // Find maximum x such that:
            // t * x * (x + 1) / 2 <= T

            long long lo = 0, hi = mountainHeight;

            while (lo <= hi) {
                long long mid = lo + (hi - lo) / 2;

                __int128 time = (__int128)t * mid * (mid + 1) / 2;

                if (time <= T)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }

            total += hi;

            if (total >= mountainHeight)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(
        int mountainHeight,
        vector<int>& workerTimes
    ) {
        long long mn = *min_element(
            workerTimes.begin(),
            workerTimes.end()
        );

        // Fastest worker alone removes entire mountain
        long long high =
            mn * 1LL * mountainHeight * (mountainHeight + 1) / 2;

        long long low = 0;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};