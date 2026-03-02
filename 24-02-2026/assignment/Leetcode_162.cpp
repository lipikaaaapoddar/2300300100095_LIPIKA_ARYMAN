#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int s=0, e=nums.size()-1 ;
    while(s<e){
        int mid = s + (e-s)/2;
        if (nums[mid]<nums[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    return nums[s];
}

int main() {
    vector<int> arr;
    int count;
    cout << "Enter the number of elements in the array: ";  
    cin >> count;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < count; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    int result = findPeakElement(arr);
    cout << " Peak element of the array is :" << result << endl;

    return 0;
}