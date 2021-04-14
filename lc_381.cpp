class RandomizedCollection {
private:
    unordered_multiset<int> s;
    bool remove_val(int val) {
        if(!s.count(val)) {
            return false;
        }
        
        int i = 0;
        for(auto it = s.find(val); i < 1; ++i) {
            it = s.erase(it);
        }
        
        return true;
    }
    int get_rand() {
        int random = 0;
        int r = std::rand() % s.size();
        //int r = (std::rand() % (s.size() + 1)) - 1;
        for(auto it = s.begin(); s.find(random) == s.end(); ) {
            advance(it, r);
            random = *it;
        }
        return random;
    }
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        s.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int size = s.size();
        s.insert(val);
        //cout << "size when insert = " << s.size() << endl;
        return size + 1 == s.size();
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        //cout << "size when remove = " << s.size() << endl;
        return remove_val(val);
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        //cout << "size when getRan = " << s.size() << endl;
        return get_rand();
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */