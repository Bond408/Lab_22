#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef double (*TFun) (double);

double fun1(double);
double fun2(double);
double fun3(double);
void t_rez(TFun, double, double, double);
double golden_section_max(TFun, double, double, double);


int main() {
	setlocale(LC_ALL, "RUS");
    int choice;
    double x, a, b, h, tol = 1e-5, result;
    TFun selected_function = NULL;
	
    while (1) {
        // ����� ����
        printf("\n����\n");
        printf("1. ��������� �������� �������\n");
        printf("2. ������������ �������\n");
        printf("3. ����� ������������ �������� ������� ������� �������� �������\n");
        printf("4. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("�������� ������� (1 - Y(x), 2 - V(x), 3 - S(x)): ");
            int func_choice;
            scanf("%d", &func_choice);
            switch (func_choice) {
            case 1: 
                selected_function = fun1; 
                break;
            case 2: 
                selected_function = fun2; 
                break;
            case 3: 
                selected_function = fun3; 
                break;
            default: 
                printf("������ �������� ���.\n"); 
                continue;
            }
            printf("������� �������� x: ");
            scanf("%lf", &x);
            result = selected_function(x);
            printf("�������� �������: %.6f\n", result);
            break;

        case 2: // ��������� �������
            printf("�������� ������� (1 - Y(x), 2 - V(x), 3 - S(x)): ");
            scanf("%d", &func_choice);
            switch (func_choice) {
            case 1: selected_function = fun1; break;
            case 2: selected_function = fun2; break;
            case 3: selected_function = fun3; break;
            default: printf("������ �������� ���.\n"); continue;
            }
            printf("������� ������ ��������� a, ����� ��������� b � ��� h: ");
            scanf("%lf %lf %lf", &a, &b, &h);
            t_rez(selected_function, a, b, h);
            break;

        case 3:
            printf("�������� ������� (1 - Y(x), 2 - V(x), 3 - S(x)): ");
            scanf("%d", &func_choice);
            switch (func_choice) {
            case 1: selected_function = fun1; break;
            case 2: selected_function = fun2; break;
            case 3: selected_function = fun3; break;
            default: printf("������ �������� ���.\n"); continue;
            }
            printf("������� ������ ��������� a � ����� ��������� b: ");
            scanf("%lf %lf", &a, &b);
            result = golden_section_max(selected_function, a, b, tol);
            printf("�������� ������� � ����� x = %.6f\n", result);
            printf("�������� ������� � �����: %.6f\n", selected_function(result));
            break;

        case 4:
            printf("����� �� ���������.\n");
            return 0;

        default:
            printf("�������� �����.\n");
        }
    }
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
	return (x - 1) / (x + 1) + (1 / 3) * pow((x - 1) / (x + 1), 3) + (1 / 5) * pow((x - 1) / (x + 1), 5) + (1 / 7) * pow((x - 1) / (x + 1), 7);
}

void t_rez(TFun f, double xn, double xk, double h)
{
	for (double x = xn; x <= xk; x += h)
		printf("| x = %5.2f, y = %8.4f |\n", x, f(x));
	printf("---------------------------");
}

double golden_section_max(TFun f, double a, double b, double tol) {
    const double fi = (1 + sqrt(5)) / 2;
    double x1 = b - (b - a) / fi;
    double x2 = a + (b - a) / fi;
    while (fabs(b - a) > tol) {
        if (f(x1) > f(x2)) {
            b = x2;
        }
        else {
            a = x1;
        }
        x1 = b - (b - a) / fi;
        x2 = a + (b - a) / fi;
    }
    return (a + b) / 2;
}