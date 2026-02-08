#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int value[] = {100,60,120};
    int weight[] = {20,10,40};
    int W = 50;

    float ratio[10];
    for (int i = 0; i < n; i++)
        ratio[i] = (float)value[i] / weight[i];

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                float tr = ratio[i]; ratio[i] = ratio[j]; ratio[j] = tr;
                int tv = value[i]; value[i] = value[j]; value[j] = tv;
                int tw = weight[i]; weight[i] = weight[j]; weight[j] = tw;
            }
        }
    }

    float total = 0;
    for (int i = 0; i < n; i++) {
        if (W >= weight[i]) {
            W -= weight[i];
            total += value[i];
        } else {
            total += ratio[i] * W;
            break;
        }
    }

    cout << total;
    return 0;
}
