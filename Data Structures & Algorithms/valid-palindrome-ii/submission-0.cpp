class Solution {
public:
    bool solve(string s,int i,int j,int c){
        if(c>1){
            return false;
        }

         while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                bool t1=solve(s,i+1,j,c+1);
                bool t2=solve(s,i,j-1,c+1);
                return t1||t2;
            }
         }
         return true;
    }
    bool validPalindrome(string s) {
        return solve(s,0,s.size()-1,0);
    }
};