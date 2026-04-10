class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    unordered_map<int, set<int>>followeeMap;
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
        if (tweetMap[userId].size()>10){
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        for(auto it : tweetMap[userId]){
            pq.push(it);
            if(pq.size()>10)pq.pop();
        }

        for (auto followe :followeeMap[userId] ){
            for(auto it : tweetMap[followe]){
            pq.push(it);
            if(pq.size()>10)pq.pop();
        }
        }

        while(!pq.empty()){
            auto it = pq.top(); 
            ans.push_back(it.second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
 followeeMap[followerId].insert(followeeId);
        }
       
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followeeMap[followerId].erase(followeeId);
        }
        
    }
};
