// Link: https://leetcode.com/problems/search-a-2d-matrix/
#include<iostream>

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            
            int n=matrix.size(), m=matrix[0].size();
            int row_index, col_index, mid, start=0, end=n*m-1;
    
            while(start<=end){
                mid=start+(end-start)/2;
                row_index=mid/m;
                col_index=mid%m;
    
                if(matrix[row_index][col_index]==target)
                    return 1;
                else if(matrix[row_index][col_index]>target)
                    end=mid-1;
                else
                    start=mid+1;
            }
            return 0;
        }
    };