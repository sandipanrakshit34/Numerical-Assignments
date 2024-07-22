#include <stdio.h>
float x[100], y[100][100];
float result = 0;

int main() {
    int n, i, j;
    float h,val,u,p=1.0,term,flag=1;
    printf("Enter the number of values: ");
    scanf("%d",&n);

    printf("Enter X and Y values:\n");
    for (i=0;i<n;i++){
        scanf("%f%f",&x[i],&y[i][0]);
    }
    printf("Enter the interpolation point: ");
    scanf("%f",&val);

    h=x[1]-x[0];
    for (i=1;i<n-1;i++){
        if ((x[i+1]-x[i])!=h){
            flag=0;
            break;
        }
    }
    if(flag == 0){
        printf("Error: Inconsistent intervals in x values.\n");
        return 1;
    }
    // Generate the backward difference table
    for (j=1;j<n;j++) {
        for (i=j;i<n;i++) {
            y[i][j] = y[i][j-1]-y[i-1][j-1];
        }
    }
    // Print the difference table
    printf("The difference table is:\n");
    for (i=0;i<n;i++) {
        for (j=0;j<=i;j++) {
            printf("%0.4f\t",y[i][j]);
        }
        printf("\n");
    }
    u=(val-x[n-1])/h;
    term=y[n-1][0];
    // Apply Newton's backward interpolation formula
    for (j=1;j<n;j++) {
        p*=(u+j-1)/j;
        term+=p*y[n-1][j];
    }

    result=term;

    // Print the result
    printf("The result is: %0.3f\n",result);

    return 0;
}

/*
Enter the number of values: 4
Enter X and Y values:
2 12
4 10
6 9
8 14
Enter the interpolation point: 6.5
The difference table is:
12.0000
10.0000 -2.0000
9.0000  -1.0000 1.0000
14.0000 5.0000  6.0000  5.0000
The result is: 9.492
*/