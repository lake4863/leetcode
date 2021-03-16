class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(!points.size()) return 0;
        int result = 1;
        int index = 0;
        int mx;
        int mi;
        
        sort(begin(points), end(points));
        //for(auto i : points) cout << i[0] << " : " << i[1] << endl;
        
        mi = points[0][0];
        mx = points[0][1];
        while(index < points.size()) {
            mi = max(mi, points[index][0]);
            mx = min(mx, points[index][1]);
                //cout << points[index][0] << "; " << points[index][1] << endl;
            if(points[index][0] > mx || points[index][1] < mi) {
                //cout << points[index][0] << ", " << points[index][1] << endl;
                ++result;
                mi = points[index][0];
                mx = points[index][1];
            }
            ++index;
        }
        
        return result;
    }
};