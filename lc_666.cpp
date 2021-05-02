class Solution {
public:
    int pathSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(5, vector<int>(8, 0));
        //{ {0}, {0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
        int result = 0;
        int depth = 0;
        int width = 0;
        
        for(int i : nums) {
            int x = i / 100;
            int y = i % 100 / 10 - 1;
            v[x][y] = v[x - 1][y / 2] + i % 10;
        }
        
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 8; ++j) {
                if(i == 4 || v[i][j] && !v[i + 1][j * 2] && !v[i + 1][j * 2 + 1]) {
                    result += v[i][j];
                }
            }
        }
        
        return result;
    }
};

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0;
        queue<info> q;
        info dummy(0);
        info* p = &dummy; // parent start with dummy info, root have no real parent;
        for (int n : nums) {
            info c(n); // child;
            while (!p->isparent(c) && !q.empty()) {
                sum += p->leaf ? p->v : 0;
                p = &q.front();
                q.pop();
            }
            p->leaf = false;
            c.v += p->v;
            q.push(c);
        }
        while (!q.empty()) {
            sum += q.front().v;
            q.pop();
        }
        return sum;
    }
private:
    struct info {
        int i, j, v;
        bool leaf;
        info(int n) : i(n / 100 - 1), j((n % 100) / 10 - 1), v(n % 10), leaf(true) {};
        bool isparent(info other) { return i == other.i - 1 && j == other.j / 2;};
    };
};