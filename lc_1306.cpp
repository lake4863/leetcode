class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 || start >= arr.size() || arr[start] < 0) return false;
        
        if(!arr[start]) return true;
        arr[start] = -arr[start];
        
        return canReach(arr, start - arr[start]) || canReach(arr, start + arr[start]);
    }
};

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        
        return dfs(arr, visited, start);
    }
    
    bool dfs(vector<int>& arr, vector<bool>& visited, int start) {
        if(start < 0 || start > arr.size() || visited[start]) return false;
        
        //visited[start] = true;    // mark visited before or after are both OK
        if(!arr[start]) return true;
        visited[start] = true;
        
        return dfs(arr, visited, start - arr[start]) || dfs(arr, visited, start + arr[start]);
    }
};