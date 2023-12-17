class Solution {
    public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        bool flag=1;
        int i=0;
        while(i<nums.size())
        {
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            
            if(abs(a-b)>k or abs(a-c)>k or abs(b-c)>k)
            {
                flag=0;
                break;
            }
            
            ans.push_back({a,b,c});
            i+=3;
        }
        
        if(!flag)
        return {};
        else
        return ans;
    }
};