#include <stdio.h>
#include <math.h>

int main()
{
    printf("Calculating '4\\cdot \\sum_{k=1}^{10^6} \\frac{(-1)^{k+1}}{2k-1} = 4\\cdot(1-1/3+1/5-1/7+1/9-1/11\\ldots)'\n");
    
    int max = pow(10, 6);
    int min = 1;
    double result;
    
    int a1 = 1;
    double an = 1 / 1999999 * (-1);
    
    double numerator = max * (a1 + an);
    int denominator = 2;
    
    result = numerator / denominator * 4;
    printf("Result is: %.0f\n", result);
    
}
