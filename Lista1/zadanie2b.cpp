#include <iostream>

double f(double x)
{
	return x * x - 2;
}

long double solve(double a, double b, double(*f)(double))
{
	double c = (a + b) / 2;


	if (c == a || c == b) {
		return c;
	}

	if (f(c) < 0)
	{
		return solve(c, b, f);
	}


	if (f(c) > 0)
	{
		return solve(a, c, f);
	}



}
int main()
{
	std::cout << solve(0, 2, f);

}
