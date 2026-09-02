class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0;
        int j=0;
        int m=word1.size();
        int n=word2.size();
        while(i<m && j<n){
            ans+=word1[i];
            ans+=word2[j];
            i++;
            j++;
        }
        if(i<m){
            ans+=word1.substr(i,m-1);
        }
          if(j<n){
            ans+=word2.substr(i,n-1);
        }
        return ans;
    }
};