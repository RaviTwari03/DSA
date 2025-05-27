class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1, i = 0;

        while (k > 0) {
            if (i < arr.size() && arr[i] == num) {
                i++;
            } else {
                k--;
            }
            num++;
        }

        return num - 1;
    }
};
