// chao le yige neng pass de
class NumArray {
private:
    int sum[120005];
    int number[30005];
    int n;
    
    inline void pushup(int k) {
        sum[k] = sum[k << 1] + sum[k << 1 | 1];
    }
    
    void build(int k, int l, int r) {
        if(l == r) {
            sum[k] = number[l];
            return;
        }
        int mid = (r + l) >> 1;
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
        pushup(k);
    }
    
    void change(int k, int x, int y, int l, int r) {
        if(l == r) {
            sum[k] = y;
            return;
        }
        int mid = (r + l) >> 1;
        if(x <= mid) {
            change(k << 1, x, y, l, mid);
        } else {
            change(k << 1 | 1, x, y, mid + 1, r);
        }
        pushup(k);
    }
    
    int query(int k, int l, int r, int nl, int nr) {
        if(l <= nl && nr <= r) return sum[k];
        int mid = (nr + nl) >> 1;
        int ans = 0;
        
        if(l <= mid) {
            ans += query(k << 1, l, r, nl, mid);
        }
        
        if(r > mid) {
            ans += query(k << 1 | 1, l, r, mid + 1, nr);
        }
        return ans;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        for(int i = 0; i < nums.size(); ++i) {
            number[i + 1] = nums[i];
        }
        build(1, 1, n);
    }
    
    void update(int index, int val) {
        change(1, index + 1, val, 1, n);
    }
    
    int sumRange(int left, int right) {
        return query(1, left + 1, right + 1, 1, n);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class NumArray {
private:
    vector<int> num;
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        num = nums;
        /*
        for(auto i : num) cout << i << ", ";
        cout << endl;
        */
        sum.resize(nums.size() + 1);
        sum[0] = 0;
        sum[1] = num[0];
        for(int i = 1; i < num.size(); ++i) {
            sum[i + 1] = sum[i] + num[i];
        }
    }
    
    void update(int index, int val) {
        int ori = num[index];
        num[index] = val;
        for(int i = index; i < num.size(); ++i) {
            sum[i + 1] += val - ori;
        }
    }
    
    int sumRange(int left, int right) {
        //cout << sum[right] << ", " << sum[left] << endl;
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
 
 /**
 * 抄的第一个版本，没改出来：
 */
 class SegmentTree {
private:
    int start;
    int end;
    int sum;
    SegmentTree* left;
    SegmentTree* right;
public: 
    SegmentTree(int st, int en, int s, SegmentTree* l, SegmentTree* r) {
        start = st;
        end = en;
        sum = s;    // can be max/min
        left = l;
        right = r;
    }
};

class NumArray {
private:
    struct SegmentTreeNode {
        int start;
        int end;
        int sum;
        SegmentTreeNode* left;
        SegmentTreeNode* right;
        SegmentTreeNode(int st, int en, int s, SegmentTreeNode* l, SegmentTreeNode* r) : 
            start(st), end(en), sum(s), left(l), right(r) {}
    };
    
    SegmentTreeNode* build(int st, int en, vector<int>& vals) {
        if(st == en) {
            SegmentTreeNode* n = new SegmentTreeNode(st, en, vals[st], nullptr, nullptr);
            return n;
            //return SegmentTreeNode(st, en, vals[st], nullptr, nullptr);
        } 
        int mi = st + (en - st) / 2;
        
        SegmentTreeNode* left = build(st, mi, vals);
        SegmentTreeNode* right = build(mi + 1, en, vals);
        SegmentTreeNode* t = new SegmentTreeNode(st, en, left->sum + right->sum, left, right);
        return t;
    }
    
    void updateTree(SegmentTreeNode* root, int index, int val) {
        if(root->start == root->end && root->start == index) {
            root->sum = val;
            return;
        }
        int mi = st + (en - st) / 2;
        if(index <= mid) {
            updateTree(root.left, index, val);
        } else {
            updateTree(root.right, index, val);
        }
        root.sum = root.left.sum + root.right.sum;
    }
    
    int querySum(SegmentTreeNode* root, int l, int r) {
        if(root.start == l and root.end == r) {
            return root.sum;
        }
        int mi = st + (en - st) / 2;
        if(r <= mi) {
            return querySum(root.left, l, r);
        } else if(l > mi) {
            return querySum(root.right, l, r);
        } else {
            return querySum(root.left, l, mi) + querySum(root.right, mi, r);
        }
    }
public:
    NumArray(vector<int>& nums) {
        root = build(0, nums.size() - 1, nums);
    }
    
    void update(int index, int val) {
        updateTree(root, index, val);
    }
    
    int sumRange(int left, int right) {
        querySum(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */