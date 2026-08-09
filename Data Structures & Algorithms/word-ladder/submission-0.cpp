class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            string curr=top.first;
            int count=top.second;
            if(curr==endWord){
                return count;
            }
            for(int i=0;i<curr.size();i++){
                char ori=curr[i];
                for(char j='a';j<='z';j++){
                    curr[i]=j;
                    if(st.find(curr)!=st.end()){
                        st.erase(curr);
                        q.push({curr,count+1});
                    }
                }
                curr[i]=ori;
            }

        }
        return 0;
    }
};