#include <stdio.h>

void add(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void traditional_mult(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;
    int temp1, temp2;

    // M1 = (A11 + A22) * (B11 + B22)
    temp1 = A[0][0] + A[1][1];
    temp2 = B[0][0] + B[1][1];
    M1 = temp1 * temp2;

    // M2 = (A21 + A22) * B11
    temp1 = A[1][0] + A[1][1];
    M2 = temp1 * B[0][0];

    // M3 = A11 * (B12 - B22)
    temp2 = B[0][1] - B[1][1];
    M3 = A[0][0] * temp2;

    // M4 = A22 * (B21 - B11)
    temp2 = B[1][0] - B[0][0];
    M4 = A[1][1] * temp2;

    // M5 = (A11 + A12) * B22
    temp1 = A[0][0] + A[0][1];
    M5 = temp1 * B[1][1];

    // M6 = (A21 - A11) * (B11 + B12)
    temp1 = A[1][0] - A[0][0];
    temp2 = B[0][0] + B[0][1];
    M6 = temp1 * temp2;

    // M7 = (A12 - A22) * (B21 + B22)
    temp1 = A[0][1] - A[1][1];
    temp2 = B[1][0] + B[1][1];
    M7 = temp1 * temp2;

    // C11 = M1 + M4 - M5 + M7
    C[0][0] = M1 + M4 - M5 + M7;

    // C12 = M3 + M5
    C[0][1] = M3 + M5;

    // C21 = M2 + M4
    C[1][0] = M2 + M4;

    // C22 = M1 - M2 + M3 + M6
    C[1][1] = M1 - M2 + M3 + M6;
}

void print_matrix(int M[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C1[2][2], C2[2][2];

    traditional_mult(A, B, C1);
    printf("Traditional Multiplication Result:\n");
    print_matrix(C1);

    strassen(A, B, C2);
    printf("Strassen Multiplication Result:\n");
    print_matrix(C2);

    return 0;
}