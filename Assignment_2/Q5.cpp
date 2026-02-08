#include <iostream>
using namespace std;

int main() {
    int n = 6;
    char ch[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};

    int parent[20], left[20], right[20];
    for (int i = 0; i < 20; i++) parent[i] = -1;

    int size = n;

    while (true) {
        int x = -1, y = -1;
        for (int i = 0; i < size; i++) {
            if (parent[i] == -1) {
                if (x == -1 || freq[i] < freq[x]) {
                    y = x;
                    x = i;
                } else if (y == -1 || freq[i] < freq[y]) {
                    y = i;
                }
            }
        }
        if (y == -1) break;

        freq[size] = freq[x] + freq[y];
        left[size] = x;
        right[size] = y;
        parent[x] = size;
        parent[y] = size;
        parent[size] = -1;
        size++;
    }

    for (int i = 0; i < n; i++) {
        int cur = i;
        char code[10];
        int k = 0;
        while (parent[cur] != -1) {
            if (left[parent[cur]] == cur) code[k++] = '0';
            else code[k++] = '1';
            cur = parent[cur];
        }
        cout << ch[i] << " ";
        for (int j = k-1; j >= 0; j--) cout << code[j];
        cout << endl;
    }
    return 0;
}
