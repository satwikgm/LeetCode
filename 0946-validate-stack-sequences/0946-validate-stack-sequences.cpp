class Solution {
public:
    bool fun(vector<int>& a, vector<int>& b , int n , int m)
    {
        stack<int> s;
        s.push(a[0]);
        int i=1,j=0;
        while(j<m)
        {
            if(s.empty())
            {
                if(i<n)
                {
                    s.push(a[i]);
                    i++;
                }
                else
                {
                    return false;
                }
            }
            if(b[j]!=s.top() && i==n)
            {
                return false;
            }
            if(b[j]==s.top())
            {
                s.pop();
                j++;
            }
            else
            {
                if(i<n)
                {
                    s.push(a[i]);
                    i++;
                }
            }
        }
        if(s.empty() && j==m)
        {
            return true;
        }
        return false;
    }
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        return fun(pushed,popped,pushed.size(),popped.size());
    }
};