#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int i = 0, j = i + 1;
    int n = nums.size();

    while (j < n) {
        if (nums[i] == nums[j]) {
            j++;
        } 
        else {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return i + 1;   // number of unique elements
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}