//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void fun(int ind , vector<int> &arr , set<vector<int>> &ans , vector<int> &v)
    {
        if(ind==arr.size())
        {
            ans.insert(v);
            return;
        }
        // not pick
        fun(ind+1,arr,ans,v);
        
        // pick
        v.push_back(arr[ind]);
        fun(ind+1,arr,ans,v);
        v.pop_back();
    }
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        set<vector<int>> ans;
        vector<int> v;
        sort(arr.begin(),arr.end());
        fun(0,arr,ans,v);
        vector<vector<int>> answer;
        for(auto it : ans)
        {
            answer.push_back(it);
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends