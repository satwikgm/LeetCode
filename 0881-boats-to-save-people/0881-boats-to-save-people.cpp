class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        int i=0 , j=people.size()-1;
        sort(people.begin(),people.end());
        int ans=0 , sum=0;
        while(i<=j)
        {
            int s = people[i]+people[j];
            if(s<=limit)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
        return ans;
    }
};