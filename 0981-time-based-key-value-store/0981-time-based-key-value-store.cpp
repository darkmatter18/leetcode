class TimeMap {
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        int l=0, r=data[key].size()-1, m;
        string s;
        
        while(l <= r){
            m = (l+r)/2;
            // if(v[m].first == timestamp){
            //     return v[m].second;
            // }
            // else 
            if(data[key][m].first > timestamp){
                r = m-1;
            }
            else {
                s = data[key][m].second;
                l = m+1;
            }
        }
        
        return s;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */