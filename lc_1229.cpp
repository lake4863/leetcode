class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto i : slots1) {
            if(i[1] - i[0] >= duration) {
                pq.push({ i[0], i[1] });
            }
        }
        
        for(auto i : slots2) {
            if(i[1] - i[0] >= duration) {
                pq.push({ i[0], i[1] });
            }
        }
        
        while(pq.size() > 1) {
            //cout << pq.top().first << ", " << pq.top().second << endl;
            int end = pq.top().second;
            pq.pop();
            int start = pq.top().first;
            if(start <= end - duration) {
                return { start, start + duration };
            }
        }
        
        return {};
    }
};

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        map<int, int> m;
        vector<int> result = { -1, -1 };
        int count = 0;
        bool contin = false;
        
        for(auto i : slots1) {
            ++m[i[0]];
            --m[i[1]];
        }
        
        for(auto i : slots2) {
            ++m[i[0]];
            --m[i[1]];
        }
            
        for(auto it = m.begin(); it != m.end(); ++it) {
            count += it->second;
            if(count == 2 && !contin) {
                result[0] = it->first;
                contin = true;
            }
            
            if(count != 2 && contin) {
                result[1] = it->first;
                if(result[1] - result[0] >= duration) {
                    result[1] = result[0] + duration;
                    contin = true;
                } else {
                    contin = false;
                    result[0] = -1;
                }
            }
        }
        if(result[0] == -1) {
            result.clear();
        }
        return result;   
    }
};