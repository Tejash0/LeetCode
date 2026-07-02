class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>> store;
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string s = "";
        vector<pair<int,string>> &v = store[key];
        int l = 0;
        int r = v.size()-1;
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(v[m].first == timestamp)
                return v[m].second;
            else if(v[m].first > timestamp)
                r = m-1;
            else
            {
                l = m+1;
                s = v[m].second;
            }
        }
        return s;
    }
};
