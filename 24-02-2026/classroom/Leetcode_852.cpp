#include<iostream>
#include<vector>
using namespace std;

int PeakElem(vector<int> &arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1; // Continue searching in the right half
        } else {
            high = mid; // Continue searching in the left half
        }
    }

    return low; // Return the index of the peak element
}

int main() {
    vector<int> arr = {1, 10, 5, 2};
    int result = PeakElem(arr);
    if (result != -1) {
        cout << "Peak element is at index: " << result << endl;
    } else {
        cout << "Peak element not found in the array." << endl;
    }

    return 0;
}