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

    int first = firstOccur(arr, target);
    int last = LastOccur(arr, target);

    int totalOccurrences = (first != -1 && last != -1) ? (last - first + 1) : 0;
    cout << "Total occurrences of " << target << " is: " << totalOccurrences << endl;

    return 0;
}