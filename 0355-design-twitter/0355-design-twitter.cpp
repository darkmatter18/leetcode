class Tweet {
public:
    int id;
    int time;
    int user;
    
    Tweet(int _id, int _time, int _user){
        id=_id;
        time=_time;
        user=_user;
    }
};

class Compare
{
public:
    bool operator() (Tweet left, Tweet right)
    {
        return (left.time) < (right.time);
    }
};


class Twitter {
    int currTime;
    
    priority_queue<Tweet, vector<Tweet>, Compare> tweet_set;
    
    unordered_map<int, unordered_set<int>> followers;
    
public:
    Twitter() {
        currTime = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_set.push(Tweet(tweetId, currTime, userId));
        currTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<Tweet> buff;
        int len = 0;
        
        unordered_set<int> s = followers[userId];
        s.insert(userId);
        
        while(len < 10 && !tweet_set.empty()){
            Tweet t = tweet_set.top();
            tweet_set.pop();
            // cout << t.user << " " << t.id << endl;
            if(s.contains(t.user)){
                ans.push_back(t.id);
                len++;
            }
            buff.push_back(t);
            
        }
        
        
        for(Tweet t : buff){
            tweet_set.push(t);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */