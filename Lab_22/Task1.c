#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*TFun) (double);

double fun1(double);
double fun2(double);
double fun3(double);
void t_rez(TFun, double, double, double);


void main() {
	setlocale(LC_ALL, "RUS");
	double a, b, h;
	printf("Введите a, b и h: ");
	scanf("%lf %lf %lf", &a, &b, &h);

	puts("\n Таблица для функции - Y(x):");
	t_rez(fun1, a, b, h);

	puts("\n Таблица для функции - V(x):");
	t_rez(fun2, a, b, h);

	puts("\n Таблица для функции - S(x):");
	t_rez(fun3, a, b, h);


}

double fun1(double x) {
	if (x > 0)
		return log(fabs(sqrt(pow(x, 3))));
}

double fun2(double x) {
	if (x > 1)
		return sqrt(tan(pow(x, 2) - 1));
	else if (0 <= x && x <= 1)
		return -2 * x;
	else if (x < 0)
		return exp(cos(x));
}

double fun3(double x) {
	return (x - 1) / (x + 1) + (1/3) * pow((x - 1) / (x + 1), 3) + (1/5) * pow((x - 1) / (x + 1), 5) + (1/7) * pow((x - 1) / (x + 1), 7);
}

void t_rez(TFun f, double xn, double xk, double h)
{
	for (double x = xn; x <= xk; x += h)
		printf("| x = %5.2f, y = %8.4f |\n", x, f(x));
	printf("---------------------------");
}