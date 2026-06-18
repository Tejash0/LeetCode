class LRUCache {
public:
    unordered_map<int,pair<int,list<int>::iterator>> cache;
    list<int> lru;
    int c;
    LRUCache(int capacity) {
        c = capacity;
        cache.reserve(c);
    }
    
    int get(int key) {
        if(cache.contains(key))
        {
            lru.erase(cache[key].second);
            lru.push_back(key);
            cache[key].second = prev(lru.end());
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.contains(key))
        {
            lru.erase(cache[key].second);
        }
        else
        {
            if(cache.size() >= c)
            {
                cache.erase(lru.front());
                lru.pop_front();
            }
        }
        lru.push_back(key);
        cache[key] = {value,prev(lru.end())};
    }
};
