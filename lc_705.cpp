class MyHashSet {
public:
    vector<int> v;
    /** Initialize your data structure here. */
    MyHashSet() {
    }
    
    void add(int key) {
        v.push_back(key);
    }
    
    void remove(int key) {
        for(auto it = v.begin(); it != v.end(); ) {
            if(*it == key) {
                it = v.erase(it);
            } else {
                ++it;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        bool con = false;
        for(int i : v) {
            if(i == key) {
                con = true;
            }
        }
        
        return con;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
