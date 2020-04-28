#ifndef  ALGORITHMS_H
#define  ALGORITHMS_H
#include <vector>
using namespace std;
vector<double> Function_EMA(vector<double> &arr, double period);
vector<double> Function_SMA(vector<double> &arr, double period);
void linearRegression(vector<double>& y);
void linearRegressionGradient(vector<double>& y, double it);



#endif // ! ALGORITHMS_H
