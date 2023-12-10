class Solution {
    public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        
        for(auto it:nums1)
        mp1[it]++;
        
        for(auto it:nums2)
        mp2[it]++;
        
        int a,b;
        a=b=0;
        
        for(auto it:nums1)
        {
            if(mp2.count(it))
            a++;
        }
        
        for(auto it:nums2)
        {
            if(mp1.count(it))
            b++;
        }
        
        return {a,b};
    }
};