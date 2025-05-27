class Solution {
public:
    int searchInsert(vector<int>& arr, int k) {
       int st=0;
        int end=arr.size()-1;
        int mid,index=arr.size();

       while(st <= end) {
        int mid = st + (end - st) / 2;

        if(arr[mid] == k) {
            index = mid;
            break;  
        }
        else if(arr[mid] < k) {
            st = mid + 1;  
        } else {
            index = mid;
            end = mid - 1;  
        }
    }

        return index;
    }
    };
