
#include <iostream>
using namespace std;


int myMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    cin >> n;

    int price[n];
    for(int i = 0; i < n; i++)
        cin >> price[i];

    int dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        int maxVal = -1;

        for(int j = 0; j < i; j++) {
            maxVal = myMax(maxVal, price[j] + dp[i - j - 1]);
        }

        dp[i] = maxVal;
    }

    cout << dp[n];
}
