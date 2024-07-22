#include<stdio.h>
#include<math.h>

float f(float x){
    return(pow(x,3)-(3*x)-5);
}

float df(float x){
    return(3*(pow(x,2))-3);
}

int main(){
    int i=0;
    float xn,xn1,x,e,a;

    printf("Enter the value you want the result to correct up to (0.00 format) : ");
    scanf("%f",&e);

    printf("\nEnter the Value of xn : ");
    scanf("%f",&xn);

    printf("The calculation table is :\n");
    printf("\nn\t    xn\t\t   f(xn)\t\t df(xn)\t\t f(xn)/f'(xn)\t\t  xn1\n");

    do{
        a=(f(xn)/df(xn));
        xn1 = xn-a;
        printf("\n%d\t%0.4f\t\t%0.4f\t\t  %0.4f\t\t  %0.4f\t\t  %0.4f\n",i,xn,f(xn),df(xn),a,xn1);
        i++;
        xn = xn1;
    } while(fabs(f(xn))>e);

    printf("The approximate root is (up to %f) : %0.3f",e,xn);
    return 0;
}
