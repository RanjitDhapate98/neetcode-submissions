class Solution {
public:
    int countSubstrings(string s) {
        
        int count=0;
        for(int k=0;k<s.size();k++){
            int j=k;
            int i=k;
            while(i>=0 && j<s.size()&& s[i]==s[j]){
                i--;
                j++;
                count++;
            }
           
            j=k+1;
            i=k;
            while(i>=0 && j<s.size()&& s[i]==s[j]){
                i--;
                j++;
                 count++;
            }
           
        }
        return count;
    }
};
