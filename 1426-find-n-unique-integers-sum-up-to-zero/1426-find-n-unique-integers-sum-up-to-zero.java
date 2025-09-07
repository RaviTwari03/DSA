class Solution {
    public int[] sumZero(int n) {
        
        int []arr=new int [n];
        if(n==1){
            arr[0]=0;
        }

        if(n%2==1){
            int i=0;
            int j=n-1;

            while(i<j){
                arr[i]=1000-i;
                arr[j]=i-1000;
                i++;
                j--;
            }
            arr[n/2]=0;
        }
        else{
            int i=0;
            int j=n-1;
            while(i<j){
                arr[i]=1000-i;
                arr[j]=i-1000;
                i++;
                j--;

        }
   }
return arr;}
}