#include <stdio.h>
#include <math.h>
float lb[50], ub[50],f[50];
int n;

int input_data() {
    printf("Enter the number of classes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the lower class interval : ");
        scanf("%f", &lb[i]);
        printf("Enter the upper class interval : ");
        scanf("%f",&ub[i]);
        printf("Enter the frequency : ");
        scanf("%f",&f[i]);
    }
    return n;
}

void display_data() {
    printf("\tC.I.\t\t\tf\n");
    for (int i = 0; i < n; i++){
        printf("%0.2f-%0.2f\t\t\t%f\n", lb[i], ub[i], f[i]);
    }
    printf("\n");
}

float mean_data() {
    float sum = 0.0, mean = 0.0;
    int sumf = 0;
    for (int i = 0; i < n; i++) {
        sum += ((ub[i] + lb[i]) / 2.0) * f[i];
        sumf += f[i];
    }
    mean = sum / sumf;
    return mean;
}

float median_data() {
    float median, h;
    int sum = 0, sumf = 0, mi, cf;
    for (int i = 0; i < n; i++){
        sumf += f[i];
    }
    for (int i = 0; i < n; i++){
        sum += f[i];            
        if (sum >= sumf / 2){
            mi = i;
            break;
        }
    }
    h = ub[mi] - lb[mi];
    cf = sum - f[mi];
    median = lb[mi] + h * (sumf / 2.0 - cf) / f[mi];
    return median;
}

float mode_data() {
    float mode, h;
    int cf = 0, mi = 0, f0, f1, f2, max = 0;
    for (int i = 0; i < n; i++){
        if (f[i] > max) {
            max = f[i];
            mi = i;
        }
    }
    f0 = f[mi - 1];   // f0 = frequency before the maximum frequency  
    f1 = f[mi];       // f1 = maximum frequency
    f2 = f[mi + 1];   // f2 = frequency after the maximum frequency
    h = ub[mi] - lb[mi];
    mode = lb[mi] + h * ((f1 - f0) / (2.0 * f1 - f0 - f2));
    return mode;
}

float std_dev_data() {
    float s1 = 0.0, s2 = 0.0, x, std_dev, mean = mean_data();
    for (int i = 0; i < n; i++) {
        x = (ub[i] + lb[i]) / 2.0;
        s1 += f[i] * pow(fabs(x - mean), 2);
        s2 += f[i];
    }
    std_dev = sqrt(s1 / s2);
    return std_dev;
}

int main() {
    input_data();
    display_data();
    printf("\nMean: %f", mean_data());
    printf("\nMedian: %f", median_data());
    printf("\nMode: %f", mode_data());
    printf("\nStandard deviation: %f", std_dev_data());
    return 0;
}

/*
Enter the number of classes: 7
Enter the lower class interval : 200  
Enter the upper class interval : 220
Enter the frequency : 7
Enter the lower class interval : 220
Enter the upper class interval : 240
Enter the frequency : 15
Enter the lower class interval : 240
Enter the upper class interval : 260
Enter the frequency : 20
Enter the lower class interval : 260
Enter the upper class interval : 280
Enter the frequency : 6
Enter the lower class interval : 280
Enter the upper class interval : 300
Enter the frequency : 6
Enter the lower class interval : 300
Enter the upper class interval : 320
Enter the frequency : 4
Enter the lower class interval : 320
Enter the upper class interval : 340
Enter the frequency : 2
        C.I.                    f
200.00-220.00                   7
220.00-240.00                   15
240.00-260.00                   20
260.00-280.00                   6
280.00-300.00                   6
300.00-320.00                   4
320.00-340.00                   2


Mean: 253.000000
Median: 248.000000
Mode: 245.263153
Standard deviation: 30.512293
*/