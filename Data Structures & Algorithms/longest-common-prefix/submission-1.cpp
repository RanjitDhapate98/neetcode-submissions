class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string a=strs[0];
        string b=strs[strs.size()-1];
        int i=0;
        int j=0;
        string ans="";
        while(i<a.size() && j<b.size() && a[i]==b[j]){
            ans+=a[i];
            i++;
            j++;

        }
        return ans;
    }
};