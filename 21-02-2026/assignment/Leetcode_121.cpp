#include <iostream>
#include <vector>
using namespace std;

// Function to calculate maximum profit
int maxProfit(vector<int>& prices) {
    int prof = 0, minprice = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] < minprice) {
            minprice = prices[i];
        } 
        else {
            prof = max(prof, prices[i] - minprice);
        }
    }
    return prof;
}

int main() {
    int n;
    
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    if (n == 0) {
        cout << "No prices entered!" << endl;
        return 0;
    }

    int result = maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}