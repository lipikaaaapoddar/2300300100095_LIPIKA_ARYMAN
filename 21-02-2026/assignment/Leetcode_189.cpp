#include <iostream>
#include <vector>
using namespace std;

// Function to rotate array by k steps
void rotate(vector<int>& nums, int k) {
    if (nums.size() <= 1) return;

    k = k % nums.size();   // handle k > size

    int l = 0, r = nums.size() - 1;

    // Step 1: reverse whole array
    while (l < r) {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }

    // Step 2: reverse first k elements
    l = 0; 
    r = k - 1;
    while (l < r) {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }

    // Step 3: reverse remaining elements
    l = k; 
    r = nums.size() - 1;
    while (l < r) {
        swap(nums[l], nums[r]);
        l++;
        r--;
    }
}

int main() {
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k (rotation steps): ";
    cin >> k;

    rotate(nums, k);

    cout << "Array after rotation: ";
    for (int x : nums) {
        cout << x << " ";
    }

    return 0;
}