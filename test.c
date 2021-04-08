#include "ln.h"

int main()
{
	double x = 0.5;
	double res = (ln(x));
	double precision = 0.001;
	double expected = 0.40543;
	double delta = expected - res;

	if (delta < 0) { delta *= -1; }

	if (delta > precision) { return 101; }

	 x = -0.5;
	 res = (ln(x));
	 precision = 0.001;
	 expected = -0.6931;
	 delta = expected - res;

	if (delta < 0) { delta *= -1; }

	if (delta > precision) { return 102; }

	x = 1;
	res = (ln(x));
	precision = 0.2;
	expected = 0.63;
	delta = expected - res;

	if (delta < 0) { delta *= -1; }

	if (delta > precision) { return 103; }

	x = -0.84;
	res = (ln(x));
	precision = 0.1;
	expected = -1.82;
	delta = expected - res;

	if (delta < 0) { delta *= -1; }

	if (delta > precision) { return 104; }

	x = -0.666;
	res = (ln(x));
	precision = 0.01;
	expected = -1.091;
	delta = expected - res;

	if (delta < 0) { delta *= -1; }

	if (delta > precision) { return 105; }

	x = 0.666;
	res = (ln(x));
	precision = 0.001;
	expected = 0.5113;
	delta = expected - res;

	if (delta < 0) { delta *= -1; }

	if (delta > precision) { return 106; }

	x = 0.27;
	res = (ln(x));
	precision = 0.000001;
	expected = 0.2390169;
	delta = expected - res;

	if (delta < 0) { delta *= -1; }

	if (delta > precision) { return 107; }


	return 0;
	

}