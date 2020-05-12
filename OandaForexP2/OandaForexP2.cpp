#include "Algorithms.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <double> v = { 1,3,5,6,8,12,18,21,22,25 };
    
    
    vector <double> avg = Function_SMA(v, 3);
    for (auto it = avg.begin(); it != avg.end(); it++)
        cout << *it << " ";
    cout << endl;

    vector <double> avg1 = Function_EMA(v, 5);
    for (auto it = avg1.begin(); it != avg1.end(); it++)
        cout << *it << " ";
    cout << endl << endl;

    vector <double> avg2 = linearRegression(v, 3);
    for (auto it = avg2.begin(); it != avg2.end(); it++)
        cout << *it << " ";
    cout << endl << endl;
   
    vector <double> avg3 = linearRegressionGradient(v, 100, 3);
    for (auto it = avg3.begin(); it != avg3.end(); it++)
        cout << *it << " ";
    cout << endl << endl;
    
    vector <double> avg4 = polynomialRegression(3, v, 3);
    for (auto it = avg4.begin(); it != avg4.end(); it++)
        cout << *it << " ";
    cout << endl << endl;


    return 0;

}
