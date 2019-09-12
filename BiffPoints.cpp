#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Points {
	double r1;
	double r2;
};
void GetPoint(double *x, double *r)
{
	*x = 4 * (*r)*(*x)*(1 - (*x));
}
double proizv(double x1, double x2, double r1, double r2) {
	double pr = (double)(x2 - x1) / ((double)(r2 - r1));
	return pr;
}
int main() {
	double x = 0.2;
	double r=0.75;
	double x1=0.2;
	double r1 = 0.75;
	double r2 = 0;
	double x2=0.2;
	int i = 0;
	struct Points P[10];
	for (int j = 0; j < 1000; j++) {
		GetPoint(&x1, &r);
	}
	r = 0.75 + 0.0004;
	for (int j = 0; j < 1000; j++) {
		GetPoint(&x2, &r);
	}
	double pr1 = proizv(x1, x2, r1, r2);
	double pr2 = 0;
	for(r = 0.75+0.0008; r <= 1; r += 0.0004) {
		x2 = 0.2;
		for (int j = 0; j < 1000; j++) {
			GetPoint(&x2, &r);
		}
		for (int N = 0; N <= 512; N++){
			r2 = r;
			pr2= proizv(x1, x2, r1, r2);
			if (fabs(pr2) > 2 * fabs(pr1)) {
				P[i].r1 = r1;
				P[i].r2 = r2;
				i++;
				if (i == 10) break;
			}
			x1 = x2;
			r1 = r2;
		}

	}
	for (i = 0; i < 10; i++) {
		printf("%lg -- %lg", P[i].r1, P[i].r2);
	}
	return 0;
}
	
