#include <iostream>
using namespace std;

void sortAct(int s[], int e[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j] > e[j + 1]) {
                int t = e[j]; e[j] = e[j + 1]; e[j + 1] = t;
                t = s[j]; s[j] = s[j + 1]; s[j + 1] = t;
            }
        }
    }
}

void selAct(int s[], int e[], int n) {
    sortAct(s, e, n);
    int l = 0;
    cout << l;
    for (int i = 1; i < n; i++) {
        if (s[i] >= e[l]) {
            cout << " " << i;
            l = i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int s[100], e[100];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> e[i];
    selAct(s, e, n);
    return 0;
}
