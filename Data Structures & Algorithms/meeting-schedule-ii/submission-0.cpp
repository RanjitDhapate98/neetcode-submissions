/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int count=0;
        vector<pair<int,int>>vp;
        for(auto i:intervals){
          int a=i.start;
          int b=i.end;
          vp.push_back({a,+1});
          vp.push_back({b,-1});
        }
        sort(vp.begin(),vp.end());
        int ans=0;
        for(auto i:vp){
            int a=i.first;
            int b=i.second;
            count+=b;
            ans=max(ans,count);
        }
        return ans;

    }
};
