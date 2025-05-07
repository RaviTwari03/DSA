class Solution {
public:
    string defangIPaddr(string s) {
       int start = 0; 
       int end = s.size();
        string result;
        
    while ( start < end){
        if(s[start]=='.'){
            result += "[.]";
        }else{
            result += s[start];
        }
            start++;
    }
    return result;
}
};