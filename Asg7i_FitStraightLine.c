#include<stdio.h>
#include<math.h>
int main(){
    float x[20],y[20],x2[20];
    float sum_X=0, sum_Y=0, sum_X2=0, sum_XY=0, B, A;
    int i,n;
    printf("Enter the number of points: ");
    scanf("%d",&n);

    printf("Enter the value of x and y:\n");
    for(i=0;i<n;i++){
        scanf("%f%f",&x[i],&y[i]);
        sum_X += x[i];
        sum_Y += y[i];
        sum_X2 += x[i]*x[i];
        sum_XY += x[i]*y[i];
    }

    A = (sum_X2*sum_Y - sum_X*sum_XY)/(n*sum_X2 - pow(sum_X,2));
    B = (n*sum_XY - sum_X*sum_Y)/(n*sum_X2 - pow(sum_X,2));
    printf("\nThe value of A is: %0.3f",A);
    printf("\nThe value of B is: %0.3f",B);
    printf("\nThe line of best fit is: y = %0.3f+%0.3fx",A,B);
    return 0;
}

/*
Enter the number of points: 5
Enter the value of x and y:
0 1.1
1 1.9
2 2.7
3 3.5
4 4.3

The value of A is: 1.100
The value of B is: 0.800
The line of best fit is: y = 1.100+0.800x
*/