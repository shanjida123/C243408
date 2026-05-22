#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char s1[100], s2[100];

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int n = strlen(s1);
    int m = strlen(s2);

    int dp[100][100];


    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }


    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= m; j++) {

            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                if(dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << "\nLength of LCS = " << dp[n][m];

    return 0;
}
