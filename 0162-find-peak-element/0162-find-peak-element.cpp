class Solution {
public:
    int findPeakElement(vector<int>& arr) {
       int st=0, end= arr.size()-1;

       while(st<end){
        int mid = st + (end-st)/2;

        if (arr[mid]<=arr[mid+1]){
            st=mid+1;//right

        }else{
            end=mid;//left
        }
       }return st;
    }
};