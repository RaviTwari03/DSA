class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // CHANGED:
        // Handle the two cases based on the parity of stones
        // whose remainder is 0.
        if (cnt[0] % 2 == 0) {
            // With an even number of 0-mod-3 stones,
            // Alice needs at least one stone from each group.
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // CHANGED:
        // When cnt[0] is odd, Alice wins if one of the
        // non-zero remainder groups has at least two more
        // stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};
