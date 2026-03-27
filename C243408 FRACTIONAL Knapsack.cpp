#include <iostream>
using namespace std;

struct I {
    float v, w, r;
};

void srt(I a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j].r < a[j + 1].r) {
                I t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
}

float knap(I a[], int n, float W) {
    srt(a, n);
    float val = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].w <= W) {
            W -= a[i].w;
            val += a[i].v;
        } else {
            val += a[i].r * W;
            break;
        }
    }
    return val;
}

int main() {
    int n; cin >> n;
    I a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i].v >> a[i].w;
        a[i].r = a[i].v / a[i].w;
    }
    float W; cin >> W;
    cout << "Maximum value: " << knap(a, n, W);
    return 0;
}
