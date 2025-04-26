class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
       for (int i=0; i<=arr.size()-1; i++){
        for (int j=arr.size()-1; j>i; j--){
            if(arr[j]==2*arr[i]){
                return true;
            }else if(arr[j]*2==arr[i]){
                return true;
            }
            }
        }
        return false; 
       }
    
};