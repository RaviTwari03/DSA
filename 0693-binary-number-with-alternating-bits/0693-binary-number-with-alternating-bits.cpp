class Solution {
public:
    bool hasAlternatingBits(int n) {
        // bitset<32>b(n);
        // int bits = log2(n);
        // for(int i=0;i<=bits;i++){
        //     if(b[i] == b[i+1]){
        //         return false;
        //     }
        // }
        // return true;

        int currBits = n%2;
        n/=2;
        while(n>0){
            if(currBits == n%2){
                return false;
            }
            currBits = n%2;
            n/=2;

        }
        return true;
    }
};