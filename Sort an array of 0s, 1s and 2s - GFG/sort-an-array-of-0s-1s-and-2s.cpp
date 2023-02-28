//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[a[i]]++;
        }
        int i=0;
        for(int x=0;x<m[0];x++)
        {
            a[i++]=0;
        }
        for(int x=0;x<m[1];x++)
        {
            a[i++]=1;
        }
        for(int x=0;x<m[2];x++)
        {
            a[i++]=2;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends