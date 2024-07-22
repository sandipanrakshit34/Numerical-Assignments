#include <stdio.h>

float x[100],y[100][100];
float result = 0;

int main() {
    int n, i, j;
    float h,val,u,p=1.0,term,flag=1;
    printf("Enter the number of values: ");
    scanf("%d",&n);

    printf("Enter X and Y values:\n");
    for(i=0;i<n;i++){
        scanf("%f %f",&x[i],&y[i][0]);
    }
    printf("Enter the interpolation point: ");
    scanf("%f",&val);

    h=x[1]-x[0];
    for (i=1;i<n-1;i++){
        if((x[i+1]-x[i])!=h){
            flag=0;
            break;
        }
    }
    if (flag==0){
        printf("Error: Inconsistent intervals in x values.\n");
        return 1;
    }
    // Generate the difference table
    for (j=1;j<n;j++) {
        for (i=j;i<n;i++) {
            y[i][j]=y[i][j-1]-y[i-1][j-1];
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

    u=(val-x[0])/h;
    term=y[0][0];
    for (j=1;j<n;j++) {
        p*=(u-j+1)/j;
        term+=p*y[j][j];
    }

    result=term;
    printf("The result is: %0.3f\n",result);
    return 0;
}

/*
Enter the number of values: 6
Enter X and Y values:
30 0.5000
35 0.5736
40 0.6428
45 0.7071
50 0.7660
55 0.8192
Enter the interpolation point: 32
The difference table is:
0.5000
0.5736  0.0736
0.6428  0.0692  -0.0044
0.7071  0.0643  -0.0049 -0.0005
0.7660  0.0589  -0.0054 -0.0005 -0.0000
0.8192  0.0532  -0.0057 -0.0003 0.0002  0.0002
The result is: 0.530
*/