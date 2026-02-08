#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int target) {
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (arr[m] == target) return m;
    if (arr[m] > target) return binarySearch(arr, l, m - 1, target);
    return binarySearch(arr, m + 1, r, target);
}

int main() {
    int arr[] = {2,5,8,12,16,23,38,56,72,91};
    cout << binarySearch(arr, 0, 9, 23);
    return 0;
}
