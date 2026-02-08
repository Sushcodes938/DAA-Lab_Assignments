#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int at[] = {900,910,920,1100,1120};
    int dt[] = {940,1200,950,1130,1140};

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (at[i] > at[j]) {
                int t = at[i]; at[i] = at[j]; at[j] = t;
                t = dt[i]; dt[i] = dt[j]; dt[j] = t;
            }
        }
    }

    int plat = 1, maxp = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            plat++;
            if (plat > maxp) maxp = plat;
            i++;
        } else {
            plat--;
            j++;
        }
    }

    cout << maxp;
    return 0;
}
