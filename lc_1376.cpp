class Solution {
private:
    int findManager(int i, vector<int>& manager, vector<int>& informTime) {
        if(manager[i] != -1) {
            informTime[i] += findManager(manager[i], manager, informTime);
            manager[i] = -1;
        }
        return informTime[i];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        
        for(int i = 0; i < n; ++i) {
            //cout << i << " ";
            res = max(res, findManager(i, manager, informTime));
        }
        //cout << endl;
        
        return res;
    }
};
