class Solution {
public:
    void merge(vector<int> &a , int l , int m , int h)
    {
        vector<int> temp;
        int i=l,j=m+1;
        while(i<=m && j<=h)
        {
            if(a[i] <= a[j])
            {
                temp.push_back(a[i++]);
            }
            else
            {
                temp.push_back(a[j++]);
            }
        }
        while(i<=m) temp.push_back(a[i++]);
        while(j<=h) temp.push_back(a[j++]);
        for(int i=l;i<=h;i++)
        {
            a[i] = temp[i-l];
        }
    }
    void mergeSort(vector<int> &a , int l , int h)
    {
        if(l>=h) return;
        int m = (l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,l,m,h);
    }
    vector<int> sortArray(vector<int>& a) {
        mergeSort(a,0,a.size()-1);
        return a;
    }
};