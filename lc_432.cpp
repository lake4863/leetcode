class AllOne {
private:
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    AllOne() {
        m.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        ++m[key];
        //cout << "inc : " << m[key] << endl;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.count(key)) {
            --m[key];
            if(m[key] <= 0) {
                int i = 0;
                for(auto it = m.find(key); i < 1; ++i) {
                    it = m.erase(it);
                }
            }
        }
        //cout << "dec : " << m[key] << endl;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        string r = "";
        int maxx = -1;
        for(auto it = m.begin(); it != m.end(); ++it) {
            maxx = max(maxx, it->second);
        }
        for(auto it = m.begin(); it != m.end(); ++it) {
            if(it->second == maxx) {
                r = it->first;
            }
        }
        return r;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        int minn = 30001;
        string r = "";
        for(auto it = m.begin(); it != m.end(); ++it) {
            minn = min(minn, it->second);
        }
        for(auto it = m.begin(); it != m.end(); ++it) {
            if(it->second == minn) {
                r = it->first;
            }
        }
        return r;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */