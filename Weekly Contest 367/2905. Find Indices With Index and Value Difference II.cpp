class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        set<pair<int,int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i-indexDifference>=0)
            st.insert({nums[i-indexDifference],i-indexDifference});
            
            if(st.size())
            {
                auto s=*(st.begin());
                auto e=*(--st.end());
                
                if(abs(s.first-nums[i])>=valueDifference and i-s.second>=indexDifference)
                return {s.second,i};
                
                if(abs(e.first-nums[i])>=valueDifference and i-e.second>=indexDifference)
                return {e.second,i};
            }
        }
        
        return {-1,-1};
    }
};