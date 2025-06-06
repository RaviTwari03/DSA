class Solution {
public:

    void permut(vector<int>nums,vector<vector<int>>&ans,int index){
        
        // Base condition
        // if(visited.size()==temp.size()){
        //     ans.push_back(temp);
        //     return;
        // }

        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }

        // for(int i=0; i < visited.size();i++){
        //     if(visited[i]==0){
        //         visited[i]=1;
        //         temp.push_back(nums[i]);
        //         permut(nums,ans,temp,visited);
        //         visited[i]=0;
        //         temp.pop_back();
        //     }
        // }
        for(int i = index; i < nums.size(); i++){
        swap(nums[i],nums[index]);
        permut(nums,ans,index+1);
        swap(nums[i],nums[index]);
    }
    // for (int i = index; i < nums.size(); i++) {
    //         swap(nums[i], nums[index]);
    //         permut(nums, ans, index + 1);
    //         swap(nums[i], nums[index]); // backtrack
    //     }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(nums.size(),0);
        permut(nums,ans,0);
        return ans;
    }
};