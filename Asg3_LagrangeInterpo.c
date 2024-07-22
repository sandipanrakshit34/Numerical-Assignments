#include<stdio.h>
int main(){

    int n,i,j;
    float x[50],y[50],a,sum=0.0,term;
    printf("Enter the no. of arguments: ");
    scanf("%d",&n);
    printf("Enter the Values of X and Y: \n");
    for(i=0; i<n; i++){
        scanf("%f%f",&x[i],&y[i]);
    }
    printf("Enter the value of interpolating point: ");
    scanf("%f",&a);

    // Applying the Formula
    for(i=0;i<n;i++){
        term=1;
        for(j=0;j<n;j++){
            if(i!=j){
                term *= ((a-x[j])/(x[i]-x[j]));
            }
        }
        sum += term*y[i];
    }
    
    printf("\nFor X=%g the value of f(x) is = %0.3f\n",a,sum);
    return 0;
}

/*
Enter the no. of arguments: 5
Enter the Values of X and Y:
1 2
2 4
3 8
4 6
7 128
Enter the value of interpolating point: 6

For X=6 the value of f(x) is = 33.333
*/