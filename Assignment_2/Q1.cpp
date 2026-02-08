#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int start[] = {1,3,0,5,8,5};
    int finish[] = {2,4,6,7,9,9};

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (finish[i] > finish[j]) {
                int t = finish[i]; finish[i] = finish[j]; finish[j] = t;
                t = start[i]; start[i] = start[j]; start[j] = t;
            }
        }
    }

    int count = 1;
    int last = finish[0];
    cout << "( " << start[0] << ", " << finish[0] << " ) ";

    for (int i = 1; i < n; i++) {
        if (start[i] >= last) {
            cout << "( " << start[i] << ", " << finish[i] << " ) ";
            last = finish[i];
            count++;
        }
    }
    cout << endl << count;
    return 0;
}
