//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void fun(int a[] , int N , int ind , vector<string> &ans , string s)
    {
        if(ind == N)
        {
            ans.push_back(s);
            return;
        }
        string str = v[a[ind]];
        for(int i=0;i<str.size();i++)
        {
            s += str[i];
            fun(a , N , ind+1 , ans , s);
            s.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        string s = "";
        fun(a , N , 0 , ans , s);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends