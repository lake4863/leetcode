class NumMatrix {
private:
    int sum[250005];
    int number[50005];
    int n;
    int l;
    
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
    /*
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
    */
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        l = matrix[0].size();
        n = l * m;
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < l; ++j) {
                number[i * l + j + 1] = matrix[i][j];
            }
        }
        build(1, 1, n);
    }
    
    void update(int row, int col, int val) {
        int index = row * l + col;
        change(1, index + 1, val, 1, n);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for(int i = row1; i <= row2; ++i) {
            result += query(1, i * l + col1 + 1, i * l + col2 + 1, 1, n);
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */