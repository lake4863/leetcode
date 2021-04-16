class SnapshotArray {
private:
    vector<map<int, int>> v;
    int version = 0;
public:
    SnapshotArray(int length) {
        v = vector<map<int, int>>(length);
        //v = vector<map<int, int>>(length, map<int, int>());
        //v.resize(length);          really slow, do not use
    }
    
    void set(int index, int val) {
        v[index][version] = val;
    }
    
    int snap() {
        return version++;
    }
    
    int get(int index, int snap_id) {
        auto it = v[index].upper_bound(snap_id);
        if(it == v[index].begin()) {
            return 0;
        }
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
 
 class SnapshotArray {
private:
    int id = 0;
    unordered_map<int, unordered_map<int, int>> m;
    unordered_map<int, int> arr;
public:
    SnapshotArray(int length) {
        m.clear();
        arr.clear();
    }
    
    void set(int index, int val) {
        arr[index] = val;
    }
    
    int snap() {
        unordered_map<int, int> c(arr);
        m[id] = c;
        return id++;
    }
    
    int get(int index, int snap_id) {
        return m[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */