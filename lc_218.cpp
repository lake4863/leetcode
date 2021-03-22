        unordered_map<int, int> line;
        unordered_map<int, int> rline;
        int n = buildings.size();
        set<int> l;
        int top = -2;
        int pre = -1;
        for(int i = 0; i < n; i++) {
            l.insert(buildings[i][0]);
            l.insert(buildings[i][1]);
        }
        set<int>::iterator it;
        for(it = l.begin(); it != l.end(); it++) {
            if(pre != -1 && *it == pre+1) {
                top++;
            }
            else {
                top+=2;
            }
            line[*it] = top;
            rline[top] = *it;
            pre = *it;
        }
        for(int i = 0; i < n; i++) {
            update(1, 0, top, line[buildings[i][0]], line[buildings[i][1]], buildings[i][2]);
        }
        vector<pair<int, int>> res;
        int ph = 0;
        for(int i = 0; i <= top; i++) {
            int h = query(1, 0, top, i);
            if(h != ph) {
                res.push_back(make_pair(h > ph ? rline[i] : rline[i-1], h));
                ph = h;
            }
        }
        if(n > 0) {
            res.push_back(make_pair((rline[top]), 0));
        }
        return res;
    }