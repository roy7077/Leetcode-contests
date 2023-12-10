#include <algorithm>
#include <cmath>
class Solution {
public:
    
    static int power(int base,int n,int mod)
    {
        int ans=1;
        int last=base%10;
        while(n)
        {
            ans=(ans*last)%mod;
            n--;
        }
        return ans;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        
        for(int i=0;i<variables.size();i++)
        {
            int cal1=power(variables[i][0],variables[i][1],10);
            int cal2=power(cal1,variables[i][2],variables[i][3]);
    
            if(cal2==target)
            ans.push_back(i);
        }
        
        
        return ans;
    }
};