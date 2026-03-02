#include<iostream>
#include<vector>
using namespace std;

int Sqrroot(int target) {
    int low = 1;
    int high = target;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mid*mid == target) {
            return mid; // Return the index of the square root
        } else if (mid*mid < target) {
            ans = mid; // Store the index of the found target
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return ans; // Return the index of the floor of square root or -1 if not found
}

int main() {
    int target ;
    cout << "Enter the target number: ";
    cin >> target;

    int result = Sqrroot(target);
    cout << "The floor of the square root of " << target << " is: " << result << endl;

    return 0;
}