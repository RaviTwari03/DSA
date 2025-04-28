class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        while (low < high) {
            int mid = (low + high) / 2;
            int hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid; // same as ceil(pile/mid)
            }
            
            if (hours <= h) {
                high = mid; // try to eat slower
            } else {
                low = mid + 1; // need to eat faster
            }
        }
        
        return low;
    }
};