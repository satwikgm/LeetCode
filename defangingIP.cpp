                    //   Defanging an IP Address

// Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".

// Example :

// Input: address = "255.100.50.0"
// Output: "255[.]100[.]50[.]0"


#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    string defangIPaddr(string address) 
    {
        string t;
        for(auto it : address)
        {
            if(it=='.')
            {
                t=t+"[.]";
            }
            else
            {
                t=t+it;
            }
        }
        return t;
    }
};