// OandaForexP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Algorithms.h"
#include "OandaRequests.h"
#include <vector>
#include <cpr/cpr.h>


using namespace std;

int main()
{
    vector <double> v = { 1,3,5,6,8,12,18,21,22,25 };
    vector <double> avg = Function_SMA(v, 3);
    for (auto it = avg.begin(); it != avg.end(); it++)
        cout << *it << " ";
    cout << endl;

    vector <double> avg1 = Function_EMA(v, 3);
    for (auto it = avg1.begin(); it != avg1.end(); it++)
        cout << *it << " ";
     cout << endl << endl;

     linearRegression(v);
     linearRegressionGradient(v,100);


    return 0;

}
