

struct Node {
    int cnt;
    int time;
    int key;
    int value;
    
    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}
    
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
private:
    int capacity;
    int time;
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if(capacity == 0) return -1;
        auto it = key_table.find(key);
        
        if(it == key_table.end()) return -1;
        Node cache = it->second;
        S.erase(cache);
        cache.cnt++;
        cache.time = ++time;
        S.insert(cache);
        it->second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        auto it = key_table.find(key);
        
        if(it == key_table.end()) {
            if(key_table.size() == capacity) {
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            Node cache = Node(1, ++time, key, value);
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        } else {
            Node cache = it->second;
            S.erase(cache);
            cache.cnt++;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it->second = cache;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */