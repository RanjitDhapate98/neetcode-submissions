class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
        int i=0;
        int j=0;
        int ans=0;
        while(j<s.size()){
            while(freq[s[j]]>0){
                freq[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            freq[s[j]]++;
            j++;
        }
        return ans;
    }
};
