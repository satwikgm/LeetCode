//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
    int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int s1=0,s2=0;
        int i=0,j=0;
        int res=0;
        while(i<l1 && j<l2)
        {
            if(A[i] > B[j])
            {
                s1+=B[j++];
            }
            else if(A[i] < B[j])
            {
                s2+=A[i++];
            }
            else
            {
                res+=max(s1,s2)+A[i];
                s1=0,s2=0;
                i++;j++;
            }
        }
        while(j<l2)
        {
            s1+=B[j++];
        }
        while(i<l1)
        {
            s2+=A[i++];
        }
        return res+max(s1,s2);
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends