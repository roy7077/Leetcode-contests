class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        
        int sum=0;
        int cnt=0;
        int n=batteryPercentages.size();
        for(int i=0;i<n;i++)
        {
            batteryPercentages[i]=batteryPercentages[i]-sum;
            if(batteryPercentages[i]>0)
            {
                cnt++;
                sum++;
            }
        }
        return cnt;
    }
};