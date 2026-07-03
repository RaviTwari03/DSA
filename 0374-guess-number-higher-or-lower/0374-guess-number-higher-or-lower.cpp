/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        //int ans;
        int start = 1,end = n;

        while(start<=end){
            int mid = start + (end-start)/2;
            int val = guess(mid);
            if(val == -1){
                end = mid-1;
            }else if (val == 1){
                start = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
// class Solution {
// public:
//     int guessNumber(int n) {
//         int l = 1, r = n;
        
//         while(l <= r) {
//             int mid = l + (r-l)/2;
//             int val = guess(mid);
            
//             if(val == -1) {
//                 r = mid-1;
//             } else if(val == 1) {
//                 l = mid+1;
//             } else {
//                 return mid;
//             }
//         }
        
//         return -1;
//     }
// };