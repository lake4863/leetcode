class Solution {
private:
    map<int, int> m;
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int count = 0;
        int start = -1;
        int end = -1;
        bool in = false;
        
        changeMap(firstList);
        changeMap(secondList);
        
        for(auto it = m.begin(); it != m.end(); ++it) {
                //cout << "\t" << it->first << ",# " << it->second << endl;
            count += it->second;
            if(count == 2) {
                //cout << it->first << ",* " << it->second << endl;
                start = it->first;
                in = true;
            }
            
            if(in && (it->second == -1 || it->second == -2)) {
                result.push_back({ start, it->first });
                in = false;
            }
            
            if(it->second == 0) {
                result.push_back({ it->first, it->first });
            }
        }
        
        return result;
    }
    
    void changeMap(vector<vector<int>>& list) {
        for(auto i : list) {
            ++m[i[0]];
            --m[i[1]];
        }
    }
};
