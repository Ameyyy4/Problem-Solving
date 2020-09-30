// GFG Question
// TC : O(row+col) soln
// SC : O(1)
#include <iostream>
#include <vector>
using namespace std;


int searchmatrix(vector< vector<int> >& matrix, int target)
{
    int R_index = 0;
    int C_index = matrix[0].size() - 1;
    while(R_index<matrix.size() && C_index>-1)
    {
        if(target == matrix[R_index][C_index])
        {
            return 1;
        }
        if(target > matrix[R_index][C_index])
        {
            R_index++;
            continue;
        }
        if(target < matrix[R_index][C_index])
        {
            C_index--;
            continue;
        }
    }
    if(R_index == matrix.size() || C_index == -1)
    {
        return 0;
    }
}
 
// Leetcode Question
// Special Case of null that is matrix.size() = 0
// Case : [], 0
// TC : O(log(row+col)) soln
// SC : O(1)
// DOUBT : How to implement binarysearch in 2-d vector? My approach last col and then in row

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if(matrix.size() == 0)
        return 0;
    int First = 0;
    int Last = matrix[0].size()*matrix.size() - 1;
    int col = matrix[0].size();
     
    int mid;
    while(First<=Last)
    {
        mid = First + (Last-First)/2;
        if(matrix[mid/col][mid%col] == target)
            return 1;
        if(matrix[mid/col][mid%col] > target)
        {
            Last = mid - 1;
            // Trick : Earlier I was doing Last = (Last + mid)/2
            continue;
        }
        if(matrix[mid/col][mid%col] < target)
        {
            First = mid + 1;
            //Trick : Earlier I was doing First = (Last + mid)/2 which caused infinite Loop
            continue;
        }
    }
    return 0;
}


int main()
{
    //code
    int t;
    cin>>t;
    
    int row;
    int col;
    
    int temp;
    for(int i=0; i<t; i++)
    {
        cin>>row>>col;
        
        vector< vector<int> > matrix(row);
        for(int i=0; i<row; i++)
        {
            matrix[i] = vector<int> (col);
            for(int j = 0; j<matrix[i].size(); j++)
            {
                cin>>temp;
                matrix[i][j] = temp;
            }
        }
        
        cin>>temp;
        cout<<searchmatrix( matrix, temp)<<endl;
    }
    return 0;
     
}

