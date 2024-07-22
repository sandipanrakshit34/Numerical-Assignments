#include<stdio.h>
#include<math.h>

float f(float x){
	return (pow(x,3)-(3*x)-5);
}

int main(){
	float a,b,x,e;
	int i=0;
	do{
		printf("Enter the value of the start and End point: ");
		scanf("%f%f",&a,&b);
		printf("Enter upto which decimal point to approx(eg-0.001): ");
		scanf("%f",&e);
		if(f(a)*f(b)>0){
			printf("\nOut of range, try again\n");
		}
	}while(f(a)*f(b)>0);
	
	printf("Calculation Table: \n");
	printf("\nIter\t\t  a\t\t  b\t\t  x\t\t  f(a)\t\t  f(b)\t\t  f(x)\n\n");
	
	do{
		x=((a*f(b))-(b*f(a)))/(f(b)-f(a));
		printf("%d\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n\n",i,a,b,x,f(a),f(b),f(x));
		if(f(a)*f(x)<0){
			b=x;
		}
		else{
			a=x;
		}
		i++;
	}while(fabs(f(x))>e);
	printf("The approximated root (upto %0.4f term) is: %0.3f",e,x);
	return 0;
}