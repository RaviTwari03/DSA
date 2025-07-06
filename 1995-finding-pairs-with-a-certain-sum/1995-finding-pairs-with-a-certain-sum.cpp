class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq; // frequency map for nums2

public:
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;

        for (int num : nums2)
            freq[num]++;
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freq[oldVal]--;               // remove old value
        nums2[index] += val;
        freq[nums2[index]]++;         // add new value
    }

    int count(int tot) {
        int result = 0;
        for (int a : nums1) {
            int target = tot - a;
            if (freq.count(target)) {
                result += freq[target];
            }
        }
        return result;
    }
};
