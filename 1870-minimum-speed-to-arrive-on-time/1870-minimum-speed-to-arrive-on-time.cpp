class Solution {
public:
    bool fun(vector<int> &dist , double hour , int m)
    {
        double sum=0;
        for(int i=0;i<dist.size();i++)
        {
            double time = (double)(dist[i])/(double)(m);
            if(i==dist.size()-1)
            {
                sum += time;
                continue;
            }
            int t = time;
            if(time>t)
            {
                sum += t+1;
            }
            else
            {
                sum+=t;
            }
        }
        return sum <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int l=1,h=1e7,ans=-1;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(fun(dist,hour,m))
            {
                h=m-1;
                ans=m;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};