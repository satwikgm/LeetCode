class Solution {
public:
    bool fun(vector<int> &dist , double hour , int speed)
    {
        double hrs=0;
        for(int i=0;i<dist.size();i++) {
            double time = (double)(dist[i])/(double)(speed);
            if(i==dist.size()-1) {
                hrs += time;
            } else {
                int t=time;
                if(time > t) {
                    hrs += t+1;
                } else {
                    hrs += t;
                }
            }
        }
        return hrs <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int ans=-1;
        double l=1 , h=1e7;
        while(l<=h)
        {
            int m=(l+h)/2;
            if(fun(dist,hour,m))
            {
                ans=m;
                h=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};