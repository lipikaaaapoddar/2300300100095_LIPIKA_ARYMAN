#include<iostream>
#include<vector>
using namespace std;

int firstOccur(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            ans = mid; // Store the index of the found target
            high = mid - 1; // Continue searching in the left half
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return ans; // Return the index of the first occurrence or -1 if not found
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

    int result = firstOccur(arr, target);
    if (result != -1) {
        cout << "First occurrence of " << target << " is at index: " << result << endl;
    } else {
        cout << target << " not found in the array." << endl;
    }

    return 0;
}