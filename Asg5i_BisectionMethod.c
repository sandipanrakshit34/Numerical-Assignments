#include <stdio.h>
#include <math.h>
float f(float x) {
    return (pow(x,3)-(3*x)-5);
}
int main() {
    float a,b,c,e;
    int i=0;
    do{
        printf("Enter the value of a and b: ");
        scanf("%f%f",&a,&b);
        printf("Enter the desired precision (e.g., 0.001): ");
        scanf("%f",&e);
        if(f(a)*f(b)>0){
            printf("The root does not lie between these values. Please try again.\n");
        }
    }while(f(a)*f(b)>0);
    printf("\nCalculation table:\n");
    printf("\nIter\t\t a\t\t b\t\t c\t\t f(a)\t\t f(b)\t\t f(c)\n\n");
    do{
        c=(a+b)/2;
        printf("%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\t\t%0.4f\n\n",i,a,b,c,f(a),f(b),f(c));
        if(f(a)*f(c)<0){
            b=c;
        }
        else{
            a=c;
        }
        i++;
    }while(fabs(a-b)>e);
    printf("\nThe approximate root (up to %f precision) is: %0.3f\n",e,c);
    return 0;
}