#include<stdio.h>
#include<math.h>
float f(float x){
	return (x*sin(x)+pow(x,3));
}

int main() {
	float l,u,h,x[50],y[50],sum=0,final;
	int i,n;
	
	printf("Enter lower limit, upper limit and no. of sub intervals: ");
	scanf("%f%f%d",&l,&u,&n);
	h=(u-l)/n;

    printf("\nThe calculation table :\n");
    printf("\n\tX \t Y\n");
	
	for(i=0;i<=n;i++){
		x[i]=l+i*h;
		y[i]=f(x[i]);
        printf("\nx[%d]=%.3f , y[%d]=%.3f",i,x[i],i,y[i]);
	}
	for(i=1;i<=n-1;i++){
		sum += 2*y[i];
	}
	final=(y[0]+y[n]+sum)*h/2;
	printf("\nThe final soltion = %.3f",final);
	return 0;
}

/*
Enter lower limit, upper limit and no. of sub intervals: 0 1 24

The calculation table :

        X        Y

x[0]=0.000 , y[0]=0.000
x[1]=0.042 , y[1]=0.002
x[2]=0.083 , y[2]=0.008
x[3]=0.125 , y[3]=0.018
x[4]=0.167 , y[4]=0.032
x[5]=0.208 , y[5]=0.052
x[6]=0.250 , y[6]=0.077
x[7]=0.292 , y[7]=0.109
x[8]=0.333 , y[8]=0.146
x[9]=0.375 , y[9]=0.190
x[10]=0.417 , y[10]=0.241
x[11]=0.458 , y[11]=0.299
x[12]=0.500 , y[12]=0.365
x[13]=0.542 , y[13]=0.438
x[14]=0.583 , y[14]=0.520
x[15]=0.625 , y[15]=0.610
x[16]=0.667 , y[16]=0.709
x[17]=0.708 , y[17]=0.816
x[18]=0.750 , y[18]=0.933
x[19]=0.792 , y[19]=1.059
x[20]=0.833 , y[20]=1.196
x[21]=0.875 , y[21]=1.342
x[22]=0.917 , y[22]=1.498
x[23]=0.958 , y[23]=1.664
x[24]=1.000 , y[24]=1.841
The final soltion = 0.552
*/