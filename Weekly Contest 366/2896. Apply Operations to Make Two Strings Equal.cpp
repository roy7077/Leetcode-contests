class Solution {
public:
    
    int n;
    int c;
    int dp[502][502][2];
    int help(string& s1,string& s2,int i,int j,int cap)
    {
        //base case
        if(i==n)
        {
            if(j%2==0)
            return (j/2)*c;
            else
            return 1e9;
        }
        
        //recursive calls
        if(dp[i][j][cap]==-1)
        {
            int current=s1[i];
            if(cap)
            {
                current='1'-s1[i]+'0';
            }
            
            if(current==s2[i])
            {
                if(i+1<=n-1)
                {
                    dp[i][j][cap]=min(help(s1,s2,i+1,j,0),1+help(s1,s2,i+1,j+1,1));
                }
                else
                dp[i][j][cap]=help(s1,s2,i+1,j,0);
            }
            else
            {
                if(i+1<=n-1)
                dp[i][j][cap]=min(help(s1,s2,i+1,j+1,0),1+help(s1,s2,i+1,j,1));
                else
                dp[i][j][cap]=help(s1,s2,i+1,j+1,0);
            }
        }
        
        return dp[i][j][cap];
    }
    int minOperations(string s1, string s2, int x) {
        
        n=s1.length();
        c=x;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            dp[i][j][0]=dp[i][j][1]=-1;
        }
        
        int ans=help(s1,s2,0,0,0);
        if(ans>=1e9)
        return -1;
        else
        return ans;
        
    }
};
