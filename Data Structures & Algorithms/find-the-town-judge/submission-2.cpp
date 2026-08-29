class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>vp(n+1,0);
        vector<bool>visited(n+1,false);
        for(auto i:trust){
            int a=i[0];
            int b=i[1];
            visited[a]=true;
            vp[b]+=1;
        }
        int k=n-1;
        for(int i=1;i<=n;i++){
            if(vp[i]==k && visited[i]==false){
               return i;
            }
        }
        return -1;
    }
};