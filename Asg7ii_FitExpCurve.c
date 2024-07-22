#include<stdio.h>
#include<math.h>
int main(){
    float x[20],y[20],x2[20],Y[20];
    float sum_X=0,sum_Y=0,sum_X2=0,sum_XY=0,a,b,B,A;
    int i,n;
    printf("Enter the number of points: ");
    scanf("%d",&n);

    printf("Enter the value of x and y:\n");
    for(i=0;i<n;i++){
        scanf("%f%f",&x[i],&y[i]);
        Y[i]=log(y[i]);
        sum_X += x[i];
        sum_Y += Y[i];
        sum_X2 += x[i]*x[i];
        sum_XY += x[i]*Y[i];
    }

    A = (sum_X2*sum_Y - sum_X*sum_XY)/(n*sum_X2 - pow(sum_X,2));
    B = (n*sum_XY - sum_X*sum_Y)/(n*sum_X2 - pow(sum_X,2));
    a = pow(2.718,A);
    b = B/1;
    printf("\nThe value of a is: %0.3f",a);
    printf("\nThe value of b is: %0.3f",b);
    printf("\nThe line of best fit is: y = %0.3f*exp(%0.3fx)",a,b);
    return 0;
}

/*
Enter the number of points: 5 
Enter the value of x and y:
2 4
4 11 
6 30
8 82
10 223

The value of a is: 1.469
The value of b is: 0.503
The line of best fit is: y = 1.469*exp(0.503x)
*/