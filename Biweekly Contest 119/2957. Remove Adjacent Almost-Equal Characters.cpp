class Solution {
    public:
    int removeAlmostEqualCharacters(string s) {
        int cnt=0;
        int i=1;
        while(i<s.length())
        {
            if(s[i]==s[i-1] or s[i]+1==s[i-1] or s[i]==s[i-1]+1)
            {
                cnt++;
                i+=2;
            }
            else
            i++;
        }
        return cnt;
    }
};