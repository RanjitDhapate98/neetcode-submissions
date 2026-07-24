class Solution {
public:
    string longestPalindrome(string s) {
        int maxi=INT_MIN;
        string ans="";
        for(int k=0;k<s.size();k++){
            int j=k;
            int i=k;
            while(i>=0 && j<s.size()&& s[i]==s[j]){
                i--;
                j++;
            }
            if(j-i-1>maxi){
                maxi=j-i-1;
                ans=s.substr(i+1,j-i-1);
            }
            j=k+1;
            i=k;
            while(i>=0 && j<s.size()&& s[i]==s[j]){
                i--;
                j++;
            }
            if(j-i-1>maxi){
                maxi=j-i-1;
                ans=s.substr(i+1,j-i-1);
            }
        }
        return ans;
    }
};
