class CustomStack {
private:
    int size = 0;
    int vol = 0;
    deque<int> dq;
public:
    CustomStack(int maxSize) {
        vol = maxSize;
        dq.clear();
    }
    
    void push(int x) {
        if(size < vol) {
            dq.push_back(x);
            ++size;
        }
        //cout << "push size = " << size << endl;
    }
    
    int pop() {
        if(size > 0) {
            int result = dq.back();
            dq.pop_back();
            --size;
        //cout << "pop size = " << size << endl;
            return result;
        } else {
        //cout << "pop size = " << size << endl;
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int count = 0;
        for(auto &i : dq) {
            if(count < k) {
        //cout << i << ", " << count << "increment size = " << size << endl;
                i += val;
        //cout << i << ", " << count << "increment size = " << size << endl;
                ++count;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */