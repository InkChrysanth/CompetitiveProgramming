#include <cstdio>
using namespace std;
int n;
const int max_size = 1 << 10;

int res[max_size][max_size];

void recursive(int x, int y, int n, int t) {
    if (n == 0) {
        res[x][y] = t;
        return;
    }
    int step = 1 << (n - 1);
    recursive(¢Ú, n - 1, t);
    recursive(x, y + step, n - 1, t);
    recursive(x + step, y, n - 1, t);
    recursive(¢Û, n - 1, !t);
}

int main() {
    scanf("%d", &n);
    recursive(0, 0, ¢Ü);
    int size = ¢Ý;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d", res[i][j]);
        puts("");
    }
    return 0;
}	
