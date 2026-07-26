class Solution {
public:
    bool isPalindrome(string s) {
        string curr="";
        for(auto i:s){
            char temp=i;
            if(temp>=65 && temp<=90 ) {
                curr+=temp;
            }if(temp>=97 && temp<=122){
                curr+=temp-32;
            }
            if(temp>='0' && temp<='9'){
                curr+=temp;
            }
        }
        int i=0;
        int j=curr.size()-1;
        while(i<=j){
            if(curr[i]!=curr[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
