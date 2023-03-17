class Solution {
public:
    void fun(vector<char> &s , int i , int j)
    {
        if(i>=j)
        {
            return;
        }
        swap(s[i] , s[j]);
        fun(s,i+1,j-1);
    }
    void reverseString(vector<char>& s) 
    {
        fun(s,0,s.size()-1);
    }
};