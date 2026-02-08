#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int deadline[] = {2,1,2,1,3};
    int profit[] = {100,19,27,25,15};
    char job[] = {'1','2','3','4','5'};

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (profit[i] < profit[j]) {
                int tp = profit[i]; profit[i] = profit[j]; profit[j] = tp;
                int td = deadline[i]; deadline[i] = deadline[j]; deadline[j] = td;
                char tj = job[i]; job[i] = job[j]; job[j] = tj;
            }
        }
    }

    int slot[10] = {0};
    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = deadline[i]-1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = job[i];
                total += profit[i];
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        if (slot[i] != 0) cout << "J" << slot[i] << " ";

    cout << endl << total;
    return 0;
}
