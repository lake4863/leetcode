class RandomizedSet {
private:
    unordered_set<int> s;
    bool remove_val(int val) {
        if(!s.count(val)) {
            return false;
        }
        
        for(auto it = s.find(val); s.count(val); ) {
            it = s.erase(it);
        }
        
        return true;
    }
    int get_rand() {
        int r = std::rand() % s.size();
        int random = 0;
        for(auto it = s.begin(); s.find(random) == s.end(); ) {
            advance(it, r);
            random = *it;
        }
        return random;
    }
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        s.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return remove_val(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        /*
        vector<int> v(s.size());
        copy(s.begin(), s.end(), v.begin());
        return v[rand() % v.size()];
        */
        return get_rand();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
private:
    unordered_set<int> s;
    bool remove_val(int val) {
        if(!s.count(val)) {
            return false;
        }
        
        for(auto it = s.find(val); s.count(val); ) {
            it = s.erase(it);
        }
        
        return true;
    }
    int get_rand() {
        int r = std::rand() % s.size();
        int random = 0;
        for(auto it = s.begin(); s.find(random) == s.end(); ) {
            advance(it, r);
            random = *it;
        }
        return random;
    }
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        s.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return remove_val(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        /*
        vector<int> v(s.size());
        copy(s.begin(), s.end(), v.begin());
        return v[rand() % v.size()];
        */
        return get_rand();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
private:
    unordered_set<int> s;
    bool remove_val(int val) {
        if(!s.count(val)) {
            return false;
        }
        
        for(auto it = s.begin(); it != s.end(); ) {
            if(*it == val) {
                it = s.erase(it);
            } else {
                ++it;
            }
        }
        
        return true;
    }
    int get_rand() {
        int r = std::rand() % s.size();
        int i = 0;
        int random;
        for(auto it = s.begin(); it != s.end(); ++it) {
            if(i == r) {
                random = *it;
            }
            ++i; 
        }
        return random;
    }
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        s.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return remove_val(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        /*
        vector<int> v(s.size());
        copy(s.begin(), s.end(), v.begin());
        return v[rand() % v.size()];
        */
        return get_rand();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

class RandomizedSet {
private:
    unordered_set<int> s;
    bool remove_val(int val) {
        if(!s.count(val)) {
            return false;
        }
        
        for(auto it = s.begin(); it != s.end(); ) {
            if(*it == val) {
                it = s.erase(it);
            } else {
                ++it;
            }
        }
        
        return true;
    }
    int get_rand() {
        int r = std::rand() % (s.size() - 1);
        int i = 0;
        for(auto it = s.begin(); it != s.end(); ++i, ++it) {
            if(i == r) {
                i = *it;
            }
        }
        return i;
    }
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        s.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return remove_val(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        vector<int> v(s.size());
        copy(s.begin(), s.end(), v.begin());
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
 
 class RandomizedSet {
private:
    unordered_set<int> s;
    bool remove_val(int val) {
        if(!s.count(val)) {
            return false;
        }
        
        for(auto it = s.begin(); it != s.end(); ) {
            if(*it == val) {
                it = s.erase(it);
            } else {
                ++it;
            }
        }
        
        return true;
    }
    int get_rand() {
        int r = std::rand() % s.size();
        int i = 0;
        int random;
        for(auto it = s.begin(); it != s.end(); ++it) {
            if(i == r) {
                random = *it;
            }
            ++i; 
        }
        return random;
    }
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        s.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.count(val)) {
            return false;
        } else {
            s.insert(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return remove_val(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        /*
        vector<int> v(s.size());
        copy(s.begin(), s.end(), v.begin());
        return v[rand() % v.size()];
        */
        return get_rand();
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */