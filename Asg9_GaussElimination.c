#include <stdio.h>
int main() {
    int i, j, k, n;
    float A[20][20], c, X[10], sum = 0.0, det = 1.0;
    // Input the order of the matrix
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    // Input the elements of the augmented matrix
    printf("Enter the elements of the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &A[i][j]);
        }
    }
    // Perform Gaussian elimination to convert the matrix to upper triangular form
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j){
                c = A[i][j] / A[j][j];
                for (k = 0; k < n + 1; k++){
                    A[i][k] = A[i][k] - (c * A[j][k]);
                }
            }
        }
    }
    // Calculate the determinant of the matrix
    for (i = 0; i < n; i++) {
        det *= A[i][i];
    }
    if (det == 0) {
        printf("Solution doesn't exist!\n");
    }
    else {
        // Perform back substitution to find the solution
        for (i = n - 1; i >= 0; i--) {
            sum = 0;
            for (j = i + 1; j < n; j++) {
                sum += A[i][j] * X[j];
            }
            X[i] = (A[i][n] - sum) / A[i][i];
        }
        // Print the solution
        printf("The solution is:\n");
        for (i = 0; i < n; i++) {
            printf("X%d = %.2f\n", i + 1, X[i]);
        }
    }
    return 0;
}

/*
Enter the order of the matrix: 3
Enter the elements of the augmented matrix:
3 4 5 18
2 -1 8 13
5 -2 7 20
The solution is:
X1 = 3.00
X2 = 1.00
X3 = 1.00
*/