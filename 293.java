class Solution {
    public List<String> generatePossibleNextMoves(String currentState) {
        List<String> res = new ArrayList<String>();
        char pre = currentState.charAt(0);
        int n = currentState.length();
        
        for(int i = 1; i < n; ++i) {
            if(pre == '+' && currentState.charAt(i) == '+') {
                res.add(currentState.substring(0, i - 1) + "--" + currentState.substring(i + 1, n));
            }
            pre = currentState.charAt(i);
        }
        return res;
    }
}
