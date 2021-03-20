

class SegmentTree {
private:
    vector<int> sums;
    vector<int> covers;
    unordered_map<int, int> m;
    int n;
    
public:
    SegmentTree(int nn, unordered_map<int, int>& mm) {
        n = nn;
        m = mm;
        sums = vector<int>(n<<2, 0);
        covers = vector<int>(n<<2, 0);
    }
    
    void pushUp(int cur, int l, int r) {
        if(covers[cur]) {
            sums[cur] = m[r + 1] - m[l];
        } else if(l == r) {
            sums[cur] = 0;
        } else {
            sums[cur] = sums[cur << 1] + sums[cur << 1 | 1];
        }
    }
    
    void updateRange(int L, int R, int l, int r, int val, int cur) {
        if(l >= L && r <= R) {
            covers[cur] += val;
            pushUp(cur, l, r);
            return;
        }
        
        int m = (r + l) >> 1;
        
        if(L <= m) {
            updateRange(L, R, l, m, val, cur << 1);
        }
        
        if(R > m) {
            updateRange(L, R, m + 1, r, val, cur << 1 | 1);
        }
        
        pushUp(cur, l, r);
    }
    
    int getSum() {
        return sums[1];
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000007;
        set<int> points;
        
        for(auto& v : rectangles) {
            points.insert(v[0]);
            points.insert(v[2]);
        }
        
        unordered_map<int, int> m;
        unordered_map<int, int> m2;
        int t = 0;
        for(int i : points) {
            m[++t] = i;
            m2[i] = t;
        }
        
        int n = points.size() - 1;
        SegmentTree* st = new SegmentTree(n, m);
        
        set<int> heights;
        unordered_map<int, vector<int>> in;
        unordered_map<int, vector<int>> out;
        
        for(int i = 0; i < rectangles.size(); ++i) {
            heights.insert(rectangles[i][1]);
            heights.insert(rectangles[i][3]);
            in[rectangles[i][1]].push_back(i);
            out[rectangles[i][3]].push_back(i);
        }
         
        long count = 0;
        int lastHeight = 0;
        
        for(int i : heights) {
            int s = st->getSum();
            
            for(int j : in[i]) {
                st->updateRange(m2[rectangles[j][0]], m2[rectangles[j][2]] - 1, 1, n, 1, 1);
            }
            
            for(int j : out[i]) {
                st->updateRange(m2[rectangles[j][0]], m2[rectangles[j][2]] - 1, 1, n, -1, 1);
            }
            
            count += (long)(i - lastHeight) * s;
            count %= mod;
            lastHeight = i;
        }
        
        return (int)count;
    }
};