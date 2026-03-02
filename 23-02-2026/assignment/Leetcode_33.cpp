// Search in Rotated Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int start=0, end = nums.size()-1;
    while(start<= end){
        int mid = start + (end-start)/2;
        if(nums[mid]==target){
            return mid;
        }
        
        if (nums[start]<=nums[mid]){
            if(target>= nums[start] && target< nums[mid]){
                end=mid-1;
            }
            else start = mid+1;
        }

        else {
            if(target<= nums[end] && target>nums[mid]){
                start=mid+1;
            }
            else end = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums;
    cout<<"Enter the size of the array: ";
    int n; 
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        nums.push_back(element);
    }

    int target;
    cout<<"Enter the target element: ";
    cin>>target;

    cout<<"The index of target is: "<< search(nums,target) << endl;
    return 0;
}