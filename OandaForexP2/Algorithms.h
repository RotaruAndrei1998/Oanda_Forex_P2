#ifndef  ALGORITHMS_H
#define  ALGORITHMS_H
#include <vector>
using namespace std;
vector<double> Function_EMA(vector<double> &arr, double period);
vector<double> Function_SMA(vector<double> &arr, double period);
vector<double> linearRegression(vector<double>& y, int period);
vector<double> linearRegressionGradient(vector<double>& y, double it, int period);
vector<double> polynomialRegression(int grad, vector<double>& values, int period);



#endif // ! ALGORITHMS_H
