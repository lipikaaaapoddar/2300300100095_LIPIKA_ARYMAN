#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int c = matrix[0].size();
    int r = matrix.size();
    int s=0 , e = c * r -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        int row = mid/c , col = mid % c;
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]<target){
            s = mid + 1 ;
        }
        else {
            e = mid -1 ;
        }
    }
    return false;
}

int main(){
    int n , m , t ;
    cout << " enter no of rows : ";
    cin >> n ;
    cout << " enter no of col : ";
    cin >> m ;

    vector <vector<int>> mat(n , vector<int>(m));
    
    for(int i =0 ; i<n ; i++){
         for(int j =0 ; j<m ; j++){
            cin >> mat[i][j];
         }
    }
    
    cout << " enter target : ";
    cin >> t ;

    bool ans = searchMatrix(mat , t);
    cout << ans ;
}