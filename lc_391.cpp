class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> st;
        int x_min = INT_MAX;
        int x_max = INT_MIN;
        int y_min = INT_MAX;
        int y_max = INT_MIN;
        int size = 0;
        
        for(auto r : rectangles) {
            if(r[0] < x_min) x_min = r[0];
            if(r[2] > x_max) x_max = r[2];
            if(r[1] < y_min) y_min = r[1];
            if(r[3] > y_max) y_max = r[3];
            
            size += (r[2] - r[0]) * (r[3] - r[1]);
            
            string lb = to_string(r[0]) + "_" + to_string(r[1]); 
            string lt = to_string(r[0]) + "_" + to_string(r[3]); 
            string rb = to_string(r[2]) + "_" + to_string(r[1]); 
            string rt = to_string(r[2]) + "_" + to_string(r[3]); 
            
            if(st.count(lb)) st.erase(lb);
            else st.insert(lb);
            if(st.count(lt)) st.erase(lt);
            else st.insert(lt);
            if(st.count(rb)) st.erase(rb);
            else st.insert(rb);
            if(st.count(rt)) st.erase(rt);
            else st.insert(rt);
        }
        
        string leftbottom  = to_string(x_min) + "_" + to_string(y_min);
        string lefttop     = to_string(x_min) + "_" + to_string(y_max);
        string rightbottom = to_string(x_max) + "_" + to_string(y_min);
        string righttop    = to_string(x_max) + "_" + to_string(y_max);
        
        if(!st.count(leftbottom) || 
           !st.count(lefttop) || 
           !st.count(rightbottom) || 
           !st.count(righttop) || 
           st.size() != 4) return false;
        return size == (x_max - x_min) * (y_max - y_min);
    }
};