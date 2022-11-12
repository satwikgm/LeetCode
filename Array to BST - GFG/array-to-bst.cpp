//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
class Solution {
public:
    Node* toBST(vector<int> &v , int l , int h)
    {
        if(l>h)
        {
            return NULL;
        }
        int m = (l+h)/2;
        Node* root = new Node(v[m]);
        root->left = toBST(v,l,m-1);
        root->right = toBST(v,m+1,h);
        return root;
    }
    vector<int> ans;
    void pre(Node* root)
    {
        if(root)
        {
            ans.push_back(root->data);
            pre(root->left);
            pre(root->right);
        }
    }
    vector<int> sortedArrayToBST(vector<int>& nums) 
    {
        Node* root = toBST(nums,0,nums.size()-1);
        pre(root);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends