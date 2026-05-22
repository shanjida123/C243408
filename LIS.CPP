#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    int lis[100];

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        lis[i] = 1;
    }


    for(int i = 1; i < n; i++) {

        for(int j = 0; j < i; j++) {

            if(arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maxLength = 0;

    for(int i = 0; i < n; i++) {

        if(lis[i] > maxLength) {
            maxLength = lis[i];
        }
    }

    cout << "\nLength of LIS = " << maxLength;

    return 0;
}
