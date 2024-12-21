#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef double (*TFun)(double);

int calculate(TFun prtf, double* x, int n);

double fun(double x) {
    return x * x - 2 * x + 2;
}

int main() {
    int n;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    double* x = (double*)malloc(n * sizeof(double));

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }

    int count = calculate(fun, x, n);

    printf("Количество значений y, удовлетворяющих условиям: %d\n", count);

    free(x);
}

int calculate(TFun prtf, double* x, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double y = prtf(x[i]);
        if (y > 0.4 || y < -3) {
            count++; 
        }
    }
    return count;
}