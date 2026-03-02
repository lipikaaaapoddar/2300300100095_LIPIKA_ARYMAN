// Find First and Last Position of Element in Sorted Array
#include<iostream>
#include<vector>
using namespace std;

int firstOccur(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans1 = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans1 = mid; // Store the index of the found target
            high = mid - 1; // Continue searching in the left half
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return ans1; // Return the index of the first occurrence or -1 if not found
}

int LastOccur(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans2 = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans2 = mid; // Store the index of the found target
            low = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return ans2; // Return the index of the first occurrence or -1 if not found
}

vector<int> first_last_occurrence(vector<int> &arr, int target) {
    int first = firstOccur(arr, target);
    int Last = LastOccur(arr, target);

    if (first == -1 || Last == -1) {
        return {-1, -1}; // Target not found in the array
    }

    return {first, Last}; // Return the indices of the first and last occurrences
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
    
    int target;
    cout << "Enter the target element to find: ";
    cin >> target;

    vector<int> result = first_last_occurrence(arr, target);
    cout << "First and Last Occurrence of " << target << " is: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}