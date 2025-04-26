class Solution {
    public int mySqrt(int x) {
        if (x < 2) return x;  // Handle 0 and 1 directly

        
        int low=0;
        int high=x/2+1;
        int res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long square=(long)mid*mid;
            if(square==x){// in case of perfect square
                res=mid;
                return res;
            }else if(square<x){
                res=mid;
                low=mid+1;
            }else{
                
                high=mid-1;
            }
        }
        return res;
    }
}