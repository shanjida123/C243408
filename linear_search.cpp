#include <iostream>
using namespace std;


int linear_search(int A[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(A[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter value to search: ";
    cin >> x;

    int result = linear_search(arr, n, x);

    if(result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
