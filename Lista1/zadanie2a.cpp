
#include <iostream>

double f(double x)
{
	return x*x-2;
}

long double solve(double a, double b, double(*f)(double))
{
	double c;
	while (true)
	{
		c = (a + b) / 2;
		if (c == a) break;
		if (c == b) break;
		if (f(c) < 0) a = c;
		if (f(c) > 0) b = c;
		
	}
	return c;

	
	


}
int main()
{
    std::cout << solve(0,2, f);

}