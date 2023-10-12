class Solution {
public:
    void merge(vector<int> &arr , int lo , int mid , int hi) {
        int n1 = mid-lo+1 , n2 = hi-mid;
        int a1[n1] , a2[n2];
        for(int i=0;i<n1;i++) {
            a1[i] = arr[lo+i];
        }
        for(int i=0;i<n2;i++) {
            a2[i] = arr[mid+1+i];
        }
        int i=0 , j=0 , k=lo;
        while(i<n1 && j<n2)
        {
            if(a1[i] <= a2[j])
                arr[k++] = a1[i++];
            else
                arr[k++] = a2[j++];
        }
        while(i<n1) arr[k++] = a1[i++];
        while(j<n2) arr[k++] = a2[j++];
    }
    void mergeSort(vector<int> &arr , int lo , int hi) {
        if(lo>=hi) {
            return;
        }
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