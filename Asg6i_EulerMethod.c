#include<stdio.h>
#include<math.h>

float f(float x,float y){
    return ((3*x)+pow(y,2));
}
int main() {
    float x,y,h,xn;
    int n=0;
    // Input initial values and step size
    printf("Enter the value of x0, y0, h, xn: ");
    scanf("%f%f%f%f",&x,&y,&h,&xn);
    
    printf("\nCalculation table: ");
    printf("\n\nn\t\txn\t\tyn\t\tf(xn,yn)\t\tyn+1\n");
    
    while(x<xn) {
        printf("\nn=%d\t\tx=%.3f\t\ty=%.3f\t\tf(xn,yn)=%.3f\t",n,x,y,f(x,y));
        y += h*f(x,y);  // Update y using Euler's method
        x += h;            // Update x
        if(x+h>xn){    // Check if next step exceeds xn
            h = xn-x;    // Adjust h for the last step
        }
        printf("\ty=%f\t",y);  // Print updated y value
        n++;                    // Increment n
    }
    printf("\nThe value of y at x=%f is %.3f\n",x,y);
    return 0;
}

/*
Enter the value of x0, y0, h, xn: 0 1 0.01 0.1

Calculation table: 

n               xn              yn              f(xn,yn)                yn+1

n=0             x=0.000         y=1.000         f(xn,yn)=1.000          y=1.010000
n=1             x=0.010         y=1.010         f(xn,yn)=1.050          y=1.020501
n=2             x=0.020         y=1.021         f(xn,yn)=1.101          y=1.031515
n=3             x=0.030         y=1.032         f(xn,yn)=1.154          y=1.043056
n=4             x=0.040         y=1.043         f(xn,yn)=1.208          y=1.055135
n=5             x=0.050         y=1.055         f(xn,yn)=1.263          y=1.067768
n=6             x=0.060         y=1.068         f(xn,yn)=1.320          y=1.080969
n=7             x=0.070         y=1.081         f(xn,yn)=1.378          y=1.094754
n=8             x=0.080         y=1.095         f(xn,yn)=1.438          y=1.109139
n=9             x=0.090         y=1.109         f(xn,yn)=1.500          y=1.124141
n=10            x=0.100         y=1.124         f(xn,yn)=1.564          y=1.124141
The value of y at x=0.100000 is 1.124
*/