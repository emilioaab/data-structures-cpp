#include <stdio.h>
#define N 8
#define M 3

int main() {
    int BinaryTable[N][M];
    for (int i = 0; i < N; i++) {
        int n = i;
        for (int j = M-1; j >= 0; j--) {
            BinaryTable[i][j] = n % 2;
            n /= 2;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", BinaryTable[i][j]);
        }
        printf("\n");
    }
    return 0;
}
