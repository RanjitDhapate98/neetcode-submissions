class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>f1;
        unordered_map<char,int>f2;
        if(s1.size()>s2.size()){
         return false;
        }
        for(auto i:s1){
         f1[i]++;
        }
        int n=s1.size();
        int i=0;
        int j=0;
        while(j<s2.size()){
            if(n>0){
               
              f2[s2[j]]++;
              n--; 
              j++;
              
            }else{
            f2[s2[j]]++;
            f2[s2[i]]--;
            if(f2[s2[i]]==0){
               f2.erase(s2[i]);
            }
            i++;
            j++;
            }
            if(f1==f2){
               return true;
            }

        }
        return false;
    }
};
