class Solution {
    public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        
        for(int i=0;i<nums.size();i++)
        {
            int j=i+indexDifference;
            while(j<nums.size())
            {
                if(abs(nums[j]-nums[i])>=valueDifference)
                return {i,j};
                    
                j++;
            }
        }
        
        return {-1,-1};
    }
};