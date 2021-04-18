class LRUCache {
private:
    unordered_map<int, int> m;
    list<int> l;
    int cap = 0;
public:
    LRUCache(int capacity) {
        l.clear();
        m.clear();
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            l.remove_if([&key](int i){ return i == key; });
            l.push_front(key);
            return m[key];
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // if size == cap, remove LRU element from m & q,
        // else put the value directly, retain LRU sequence.
        if(m.size() == cap && m.find(key) == m.end()) {
            m.erase(l.back());
            l.pop_back();
        } 
        
        l.remove_if([&key](int i){ return i == key; });
        l.push_front(key);
        m[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */