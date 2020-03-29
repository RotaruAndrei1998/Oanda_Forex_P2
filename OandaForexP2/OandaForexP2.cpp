// OandaForexP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Algorithms.h"
#include <vector>
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

    return 0;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
