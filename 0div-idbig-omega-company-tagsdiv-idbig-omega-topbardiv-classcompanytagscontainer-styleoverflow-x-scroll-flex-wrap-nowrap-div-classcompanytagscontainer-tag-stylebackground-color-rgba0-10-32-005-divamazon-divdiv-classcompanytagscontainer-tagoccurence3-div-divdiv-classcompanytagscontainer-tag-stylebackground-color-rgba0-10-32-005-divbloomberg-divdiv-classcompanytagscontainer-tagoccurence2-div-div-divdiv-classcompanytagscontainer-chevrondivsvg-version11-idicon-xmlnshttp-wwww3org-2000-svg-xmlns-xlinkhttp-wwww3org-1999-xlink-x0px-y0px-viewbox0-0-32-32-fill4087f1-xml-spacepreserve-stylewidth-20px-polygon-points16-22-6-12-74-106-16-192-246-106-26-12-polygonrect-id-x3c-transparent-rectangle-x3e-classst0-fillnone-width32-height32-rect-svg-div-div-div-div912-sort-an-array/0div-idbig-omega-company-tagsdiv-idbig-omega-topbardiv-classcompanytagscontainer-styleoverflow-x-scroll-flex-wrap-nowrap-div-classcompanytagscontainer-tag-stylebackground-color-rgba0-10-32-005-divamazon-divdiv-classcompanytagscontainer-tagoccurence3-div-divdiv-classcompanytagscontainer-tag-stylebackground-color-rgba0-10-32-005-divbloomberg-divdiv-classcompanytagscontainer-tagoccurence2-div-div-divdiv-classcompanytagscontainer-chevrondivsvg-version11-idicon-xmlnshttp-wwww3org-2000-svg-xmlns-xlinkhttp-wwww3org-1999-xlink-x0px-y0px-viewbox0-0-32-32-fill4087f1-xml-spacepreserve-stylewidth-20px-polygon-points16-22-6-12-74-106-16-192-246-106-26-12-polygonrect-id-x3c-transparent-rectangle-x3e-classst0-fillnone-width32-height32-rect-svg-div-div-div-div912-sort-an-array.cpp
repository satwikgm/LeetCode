class Solution {
public:
    void merge(vector<int> &arr , int lo , int mid , int hi)
    {
        int n1 = mid-lo+1;
        int n2 = hi-mid;
        int arr1[n1];
        int arr2[n2];
        for(int i=0;i<n1;i++)
        {
            arr1[i] = arr[lo+i];
        }
        for(int j=0;j<n2;j++)
        {
            arr2[j] = arr[mid+1+j];
        }
        int i=0,j=0,k=lo;
        while(i<n1 && j<n2)
        {
            if(arr1[i]>=arr2[j])
            {
                arr[k++]=arr2[j++];
            }
            else
            {
                arr[k++]=arr1[i++];
            }
        }
        while(i<n1) arr[k++] = arr1[i++];
        while(j<n2) arr[k++] = arr2[j++];
    }
    void mergeSort(vector<int> &arr , int lo , int hi)
    {
        if(lo>=hi)
            return;
        int mid = (lo+hi)/2;
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);
        merge(arr,lo,mid,hi);
        
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};