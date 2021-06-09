class MKAverage {
private:
    priority_queue<int> pq;
    queue<int> q;
    int con;
    int del;
    
    int compute(priority_queue<int> pq) {
        int count = 0;
        int sum = 0;
        priority_queue<int> p(pq);
        while(count < del) {
            p.pop();
            ++count;
        }
        
        count = 0;
        while(p.size() > del) {
            //cout << sum << ", pq.size() = " << pq.size() << ", q.size() = " << q.size() << ", ";
            sum += p.top();
            ++count;
            p.pop();
        }
        //cout << endl;
        return sum / count;
    }
public:
    MKAverage(int m, int k) {
        priority_queue<int> empty_pq;
        pq.swap(empty_pq);
        con = m;
        del = k;
    }
    
    void addElement(int num) {
        q.push(num);
        pq.push(num);
    }
    
    int calculateMKAverage() {
        if(q.size() < con) {
            return -1;
        } else {
            int count = con;
            queue<int> tempq;
            priority_queue<int> temppq;
            while(count) {
                int t = q.front();
                q.pop();
                tempq.push(t);
                temppq.push(t);
                --count;
            }
            pq.swap(temppq);
            q.swap(tempq);
            while(!temppq.empty()) {
                cout << temppq.top() << ", **";
                temppq.pop();
            }
            cout << endl;
            while(!q.empty()) {
                cout << q.front() << ", ##";
                q.pop();
            }
            cout << endl;
            return compute(pq);
        }
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */