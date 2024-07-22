// Runge-Kutta method Fourth order
#include<stdio.h>
#include<math.h>

float f(float x, float y){ 
    return ((3*x) + pow(y,2));
}

int main(){
    int n=0;
    float x,y,k1,k2,k3,k4,k,h,xn;
    // Input initial values and step size
    printf("Enter the value of x0, y0, h, xn: ");
    scanf("%f%f%f%f",&x,&y,&h,&xn);

    printf("\nCalculation table: ");
    printf("\n\nn\t\txn\t\tyn");
    while(x<xn){
        printf("\n%d\tx=%f",n,x);
        k1 = h*f(x,y);
        k2 = h*f(x+h/2.0, y+k1/2.0);
        k3 = h*f(x+h/2.0, y+k2/2.0);
        k4 = h*f(x+h,y+k3);
        
        k = (k1 + 2*k2 + 2*k3 + k4)/6;
        y += k;
        x += h;
        if(x+h > xn){ // Check if next step exceeds xn
            h = xn-x; // Adjust h for the last step
        }
        printf("\ty=%f\t",y);
        n++;
    }
    
    printf("\nThe value of y at x=%f is %.3f",x,y);
    return 0;
}

/*
Enter the value of x0, y0, h, xn: 0 1 0.01 0.1

Calculation table: 

n               xn              yn
0       x=0.000000              y=1.010252
1       x=0.010000              y=1.021016
2       x=0.020000              y=1.032306
3       x=0.030000              y=1.044134
4       x=0.040000              y=1.056515
5       x=0.050000              y=1.069464
6       x=0.060000              y=1.082995
7       x=0.070000              y=1.097127
8       x=0.080000              y=1.111875
9       x=0.090000              y=1.127258
10      x=0.100000              y=1.127258
The value of y at x=0.100000 is 1.127
*/
