class Solution {
public:
    void merge(vector<int> &arr , int l , int m , int h)
    {
        int i = l , j = m+1;
        vector<int> temp;
        while(i<=m && j<=h)
        {
            if(arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
            }
        }
        while(i<=m) temp.push_back(arr[i++]);
        while(j<=h) temp.push_back(arr[j++]);
        for(int i=l;i<=h;i++)
        {
            arr[i]=temp[i-l];
        }
    }
    void mergeSort(vector<int> &arr , int l , int h)
    {
        if(l>=h)
        {
            return;
        }
        int m=(l+h)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int l=0 , h=n-1;
        mergeSort(nums,l,h);
        return nums;
    }
};