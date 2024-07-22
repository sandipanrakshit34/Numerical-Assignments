#include <stdio.h>
#include <math.h>

int main() {
    int i,n, j, max_iter, iter = 0;
    float sum, temp,A[10][10], X[10];
    printf("Enter number of equations (n), and no. of iterations: ");
    scanf("%d%d", &n, &max_iter);

    printf("Enter the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &A[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        X[i] = 0.0;
    }
    printf("\nCalculation table:\n");
    printf("i\t");
    for (i = 0; i < n; i++) {
        printf("x_%d\t", i + 1);
    }
    printf("\n");
    do{
        printf("%d\t", iter);
        for (i = 0; i < n; i++) {
            printf("%.4f\t", X[i]);
        }
        for (i = 0; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * X[j];
                }
            }
            X[i] = (A[i][n] - sum) / A[i][i];
        }
        iter++;
    } while (iter <= max_iter);

    printf("\nSolution:\n");
    for (i = 0; i < n; i++) {
        printf("x_%d = %0.4f\n", i + 1, X[i]);
    }

    return 0;
}

/*
Enter number of equations (n), and no. of iterations: 3 10
Enter the augmented matrix:
9 -2 1 50 
1 5 -3 18
-2 2 7 19

Calculation table:
i       x_1     x_2     x_3
0       0.0000  0.0000  0.0000
1       5.5556  2.4889  3.5905
2       5.7097  4.6123  3.0278
3       6.2441  4.1679  3.3075
4       6.1142  4.3616  3.2150
5       6.1676  4.2955  3.2492
6       6.1491  4.3197  3.2370
7       6.1558  4.3110  3.2414
8       6.1534  4.3141  3.2398
9       6.1543  4.3130  3.2404
10      6.1540  4.3134  3.2402
Solution:
x_1 = 6.1541
x_2 = 4.3133
x_3 = 3.2402
*/

