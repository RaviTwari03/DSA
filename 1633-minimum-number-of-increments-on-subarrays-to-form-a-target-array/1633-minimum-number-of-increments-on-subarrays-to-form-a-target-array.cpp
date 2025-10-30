class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0];

        for(int i=0;i<n-1;i++){
            ans+=max(target[i+1]-target[i],0);
        }

        return ans;
    }
};