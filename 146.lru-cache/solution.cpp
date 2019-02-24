class LRUCache {
public:
    LRUCache(int capacity) : remain(capacity) {

    }

    int get(int key) {
        auto mapit = mapcache.find(key);
        if (mapit == mapcache.end())
            return -1;
        int value = mapit->second->second;
        if (mapit->second != listcache.begin())
        {
            listcache.erase(mapit->second);
            listcache.emplace_front(key, value);
            mapit->second = listcache.begin();
        }
        return value;
    }

    void put(int key, int value) {
        auto mapid = mapcache.find(key);
        if (mapid != mapcache.end()) {
            if (mapid->second == listcache.begin())
            {
                mapid->second->second = value;
            } else {
                listcache.erase(mapid->second);
                listcache.emplace_front(key, value);
                mapid->second = listcache.begin();
            }
            return;
        }
        if (remain > 0)
        {
            remain--;
        } else if (!listcache.empty())
        {
            mapcache.erase(listcache.back().first);
            listcache.pop_back();
        }
        listcache.emplace_front(key, value);
        mapcache.emplace(key, listcache.begin());
    }

private:
    int remain;
    list<pair<int, int>> listcache;
    unordered_map<int, list<pair<int, int>>::iterator> mapcache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
