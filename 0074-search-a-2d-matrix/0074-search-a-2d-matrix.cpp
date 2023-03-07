class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0 , j=0;
        while(i<m)
        {
            if(matrix[i][0]<=target && matrix[i][n-1]>=target)
            {
                int l=0 , h=n-1;
                while(l<=h)
                {
                    int m=(l+h)/2;
                    if(matrix[i][m]==target)
                    {   
                        return 1;
                    }
                    else if(matrix[i][m]>target)
                    {
                        h=m-1;
                    }
                    else
                    {
                        l=m+1;
                    }
                }
                return 0;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }
};