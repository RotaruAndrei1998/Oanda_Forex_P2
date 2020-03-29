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