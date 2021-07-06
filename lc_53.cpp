class Solution {
public:
    int maxSubArray(vector<int>& nums) {
   /* 
    int maxSubArray(vector<int>& nums) {
        int sum=0, msa = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            msa = max(sum, msa);
            
            msa = max(nums[i], msa);
            
            sum = max(nums[i], sum);
        }
        return msa;
    }*/
        
        int sum = 0, result = nums[0]; 
        
        if(nums.size() == 1)
            return result;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]); 
            //por ex: [-2, -1] max(-1, (-2-1)) => max(-1, -3) = -1
            result = max(sum, result);
        }
        return result;
    }
};
