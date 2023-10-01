
#define ll long long
int mod=1e6;
class Solution {
    public:
    long long maximumTripletValue(vector<int>& nums) {
        
        long long result=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int k=j+1;
                while(k<n)
                {
                    long long ans=(((((ll)nums[i])-((ll)nums[j])))*nums[k]);
                    result=max(result,ans);
                    k++;
                }
            }
        }
        
        return result<0? 0:result;
    }
};

// (first-second)*third
// (nums[i] - nums[j]) * nums[k].