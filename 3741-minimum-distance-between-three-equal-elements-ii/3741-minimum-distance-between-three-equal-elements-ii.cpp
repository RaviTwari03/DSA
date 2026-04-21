class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>indices;
        int n=nums.size();

        for(int i=0;i<n;++i){
            indices[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &p :indices){
            auto &v =p.second;
            if(v.size()<3) continue;

            for(int i=0;i+2<v.size();++i){
                int i1=v[i],i2=v[i+1],i3=v[i+2];
                int dist=abs(i1-i2)+abs(i2-i3)+abs(i3-i1);
                ans=min(ans,dist);
            }
        }
        return ans == INT_MAX? -1:ans;
    }
};