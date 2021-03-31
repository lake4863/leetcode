class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minn = 1;      //piles.size();
        int maxx = 1000000000;
        int sum = 0;
        
        //for(int i : piles) sum += i;
        //maxx = sum;
        //maxx = (sum + h) / h;
        
        return bs(piles, minn, maxx, h);
    }
    
    int bs(vector<int>& piles, int minn, int maxx, int h) {
        int mid = 0;
        int k = 0;
        
        while(minn < maxx) {
            mid = minn + (maxx - minn) / 2;
            k = counth(piles, mid);
            if(k > h) {
                minn = mid + 1;
            } else {
                maxx = mid;
            }
        }
        
        return minn;
    }
    
    int counth(vector<int>& piles, int k) {
        int result = 0;
        
        //if(k == 0) return -1;
        
        for(int i : piles) {
            result += ((i + k - 1) / k);
        }
        
        return result;
    }
};