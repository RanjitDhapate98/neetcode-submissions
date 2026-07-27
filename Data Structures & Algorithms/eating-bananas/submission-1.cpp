class Solution {
public:
    int solve(int i,vector<int>& piles){
        int hrs=0;
        for(auto a:piles){
            hrs+=ceil(double(a)/double(i));
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=0;
        for(auto a:piles){
            j=max(j,a);
        }
        int ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            int hrs=solve(mid,piles);
           

            if(hrs<=h){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};
