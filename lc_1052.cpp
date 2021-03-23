class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0;   // sum of customers while not grumpy.
        int dif = 0;   // sum of customers while grumpy in range X.
        int mx  = 0;   // max customers while grumpy can be covered by X
        
        for(int i = 0; i < customers.size(); ++i) {
            if(grumpy[i] == 0) {
                sum += customers[i];
            } else {
                dif += customers[i];
            }
            
            if(i >= X) {
                //cout << customers[i] << ", " << mx << endl;
                dif -= customers[i - X] * grumpy[i - X];
            }
            mx = max(mx, dif);
        }
        
        return sum + mx;
    }
};