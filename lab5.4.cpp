#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;
double P0(const double N, double p0)
{
	
	for (int k = 1; k <= N; k++)
	{
		p0 *= ((1. * k * k) / (1. * N * N)) * cos((1. * N * N) / (1. * k * k));
	}
	return p0;
}
double P1(const double N, double k, double p1)
{
	
	if (N < k)
		return 1;
	else
		return p1 *= ((1. * k * k) / (1. * N * N)) * cos((1. * N * N) / (1. * k * k)) * P1(N, k + 1, p1);
}
double P2(const double N, double k, double p2)
{
	
	if (k < 1)
		return 1;
	else
		return p2 *= ((1. * k * k) / (1. * N * N)) * cos((1. * N * N) / (1. * k * k))  * P2(N, k - 1, p2);
}
double P3(const double N, double k, double p)
{
	p *= ((1. * k * k) / (1. * N * N)) * cos((1. * N * N) / (1. * k * k));
	if (N <= k)
		return p;
	else
		return P3(N, k + 1, p);
}
	double P4(const double N, double k, double p)
	{
		p *= ((1. * k * k) / (1. * N * N)) * cos((1. * N * N) / (1. * k * k));
		if (k <= 1)
			return p;
		else
			return P4(N, k - 1, p);


}

int main()
{
	int k;
	int N;
	cout << "N= "; cin >> N;
	cout << "P0 = " << P0(N, 1) << endl;
	cout << "P1 = " << P1(N, 1, 1) << endl;
	cout << "P2 = " << P2(N, N, 1) << endl;
	cout << "P2 = " << P3(N, 1, 1) << endl;
	cout << "P4 = " << P4(N, N, 1) << endl;

	return 0;
}
