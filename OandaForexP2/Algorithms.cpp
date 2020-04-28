#include "Algorithms.h" 
#include <iostream>
#include <vector>

using namespace std;

vector <double> Function_SMA(vector<double>& arr, double period) {
    double sum = 0;
    vector <double> average;
    int j = arr.size();

    for (int i = 0; i < j; i++) {

        sum += arr[i];

        if (i >= period)  sum -= arr[i - period];


        average.push_back(sum / period);

    }

    return average;
}


vector < double> Function_EMA(vector<double>& arr, double period) {
    int j = arr.size();
    vector <double> average;
    double weight = (2.0 / (period + 1));

    double EMA_yday = arr[0] * weight;
    average.push_back(EMA_yday);
    double EMA_today;
    for (int i = 1; i < j; i++) {

        EMA_today = arr[i] * weight + EMA_yday * (1 - weight);

        average.push_back(EMA_today);

        EMA_yday = EMA_today;

    }

    return average;





}

void linearRegression(vector<double>& y) {
    vector<double> x;
    for (int i = 0; i < y.size(); i++) {
        x.push_back(i);
        cout << i;
    }
    cout << x.size();

    double sumX = 0;
    double sumX2 = 0;
    double sumY = 0;
    double sumXY = 0;
    double a, b;

    for (int i = 0; i < x.size(); i++) {
        sumX = sumX + x[i];
        sumX2 = sumX2 + x[i] * x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
    }

    b = (x.size() * sumXY - sumX * sumY) / (x.size() * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / x.size();

    cout << "Equation of best fit is: y = " << a << " + " << b << "x";

}

void linearRegressionGradient(vector<double>& y, double it) {

    vector<double> error;
    vector<double> x;
    for (int i = 0; i < y.size(); i++) {
        x.push_back(i);
    }

    double err;
    double a = 0;
    double b = 0;
    double alpha = 0.01;
    for (int i = 0; i < x.size() * it; i++) {
        int idx = i % x.size();
        double p = a + b * x[idx];    //predictia
        err = p - y[idx];
        a = a - alpha * err;
        b = b - alpha * err * x[idx];
        cout << a << " " << b << endl;
     
    }



    cout << endl;

    cout << "Final Values are: " << "a=" << a << " " << "b=" << b;




}