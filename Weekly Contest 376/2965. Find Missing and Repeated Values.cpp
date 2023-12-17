class Solution {
    public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> map((n*m)+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            map[grid[i][j]]++;
        }
        
        int a,b;
        for(int i=1;i<=(n*m);i++)
        {
            if(map[i]==0)
            b=i;
            else if(map[i]>=2)
            a=i;
        }
        
        return {a,b};
    }
};