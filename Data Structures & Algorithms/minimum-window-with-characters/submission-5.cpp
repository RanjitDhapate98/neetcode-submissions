class Solution {
public:
    string minWindow(string s, string t) {
        if(t==""){
            return "";
        }
        unordered_map<char,int>mp;
       
        for(auto i:t){
            
            mp[i]++;
        }
         int n=mp.size();
        int i=0;
        int j=0;
        int count=0;
       
        string ans="";
        int k=INT_MAX;
        int start=0;
        unordered_map<char,int>mp1;
        while(j<s.size()){
            char temp=s[j];
            mp1[temp]++;
            if(mp[temp]==mp1[temp]){
                count++;
            }
            
            while(count==n ){
                if(j-i+1<=k){
                k=j-i+1;
                start=i;
            
            }
                mp1[s[i]]--;
                if(mp1[s[i]]==0){
                    mp1.erase(s[i]);
                }
                char a=s[i];
                if(mp[a]>0 && mp[a]>mp1[a]){
                    count--;
                }
                i++;
            }
         
            j++;
        }
        if(k==INT_MAX){
            return "";
        }
        return s.substr(start,k);
    }
};
