class Solution {
public:
    bool fun(vector<int>& arr , int i)
    {
        if(i<0 || i>=arr.size() || vis[i])
        {
            return 0;
        }
        if(arr[i]==0)
        {
            return 1;
        }
        vis[i]=1;
        return fun(arr,i+arr[i]) || fun(arr,i-arr[i]);
    }
    bool vis[50001];
    bool canReach(vector<int>& arr, int start) 
    {
        memset(vis,0,sizeof(vis));
        return fun(arr,start);
    }
};