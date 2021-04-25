class Solution {
private:
    struct SegNode {
        long long lo;
        long long hi;
        int add;
        SegNode* lchild;
        SegNode* rchild;
        SegNode(long long left, long long right) : lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
    };

public:
    void insert(SegNode* root, long long val) {
        root->add++;
        if (root->lo == root->hi) {
            return;
        }
        long long mid = (root->lo + root->hi) >> 1;
        if (val <= mid) {
            if (!root->lchild) {
                root->lchild = new SegNode(root->lo, mid);
            }
            insert(root->lchild, val);
        }
        else {
            if (!root->rchild) {
                root->rchild = new SegNode(mid + 1, root->hi);
            }
            insert(root->rchild, val);
        }
    }

    int count(SegNode* root, long long left, long long right) const {
        if (!root) {
            return 0;
        }
        if (left > root->hi || right < root->lo) {
            return 0;
        }
        if (left <= root->lo && root->hi <= right) {
            return root->add;
        }
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum = {0};
        for(int v: nums) {
            sum += v;
            preSum.push_back(sum);
        }
        
        long long lbound = LLONG_MAX, rbound = LLONG_MIN;
        for (long long x: preSum) {
            lbound = min({lbound, x, x - lower, x - upper});
            rbound = max({rbound, x, x - lower, x - upper});
        }
        
        SegNode* root = new SegNode(lbound, rbound);
        int ret = 0;
        for (long long x: preSum) {
            ret += count(root, x - upper, x - lower);
            insert(root, x);
        }
        return ret;
    }
};