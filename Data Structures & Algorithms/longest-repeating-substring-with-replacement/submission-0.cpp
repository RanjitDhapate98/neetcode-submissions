class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int i=0;
        int j=0;
        int maxi=0;
        int ans=0;
        while(j<s.size()){
            
            freq[s[j]]++;
            maxi=max(maxi,freq[s[j]]);
            while((j-i+1)-maxi>k){
                freq[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
