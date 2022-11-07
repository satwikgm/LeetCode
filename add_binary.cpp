class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i=a.size()-1 , j=b.size()-1;
        int c=0;
        string res="";
        while(i>=0 || j>=0 || c)
        {
            if(i>=0)
            {
                c+=a[i]-'0';
                i--;
            }
            if(j>=0)
            {
                c+=b[j]-'0';
                j--;
            }
            res += (c%2+'0');
            c /= 2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
