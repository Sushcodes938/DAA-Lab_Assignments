#include <iostream>
using namespace std;

int maxSum(int arr[], int l, int r) {
    if (l == r) return arr[l];
    int m = (l + r) / 2;
    int left = maxSum(arr, l, m);
    int right = maxSum(arr, m + 1, r);
    int sum = 0, leftMax = -100000;
    for (int i = m; i >= l; i--) {
        sum += arr[i];
        if (sum > leftMax) leftMax = sum;
    }
    sum = 0;
    int rightMax = -100000;
    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        if (sum > rightMax) rightMax = sum;
    }
    int cross = leftMax + rightMax;
    if (left >= right && left >= cross) return left;
    if (right >= left && right >= cross) return right;
    return cross;
}

int main() {
    int arr[] = {-2,-5,6,-2,-3,1,5,-6};
    cout << maxSum(arr, 0, 7);
    return 0;
}
