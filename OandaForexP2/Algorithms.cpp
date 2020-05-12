#include "Algorithms.h" 
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <double> Function_SMA(vector<double>& arr, double period) {
    double sum = 0;
    vector <double> average;
    int i;
    for (i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (i >= period)  sum -= arr[i - period];
        average.push_back(sum / period);
    }
    sum += average[average.size() - 1];
    sum -= arr[i - period];
   
    average.push_back(sum / period);

    return average;
}


vector <double> Function_EMA(vector<double>& arr, double period) {
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
    EMA_today = average[average.size() - 1] * weight + EMA_yday * (1 - weight);

    return average;
}

vector <double> linearRegression(vector<double>& y, int period) {
    vector<double> x;
    vector<double> predict;

    for (int i = 0; i < y.size(); i++) {
        x.push_back(i);
    }

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

    for (int i = 1; i <= x.size() + period; i++) {
        predict.push_back(a + b * i);
    }
    return predict;
}

vector<double> linearRegressionGradient(vector<double>& y, double it, int period) {

    vector<double> error;
    vector<double> x;
    vector<double> predict;

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
    }
    for (int i = 1; i <= x.size() + period; i++) {
        predict.push_back(a + b * i);
    }

    return predict;
}

vector<double> polynomialRegression(int grad, vector<double> &values, int period){   
    vector<double> c(grad+1);
    vector<double> predict;
    // Calculare valori xi^2n
    vector<double> X(2 * grad + 1);
    for (int i = 0; i < 2 * grad + 1; i++){
        X[i] = 0;
        for (int j = 0; j < values.size(); j++){
            X[i] += pow(j, i);
        }
    }

    // Calculare matrice normala augmentata
    vector < vector <double>> A(grad + 1);
    for (int i = 0; i < grad + 1; i++)
       A[i].resize(grad + 2);

    for (int i = 0; i <= grad; i++){
        for (int j = 0; j <= grad; j++) {
            A[i][j] = X[i + j];
        }
    }
    
    // Calculare valori xi^n * yi
    vector<double> Y(grad + 1);
    for (int i = 0; i < grad + 1; i++){
        Y[i] = 0;
        for (int j = 0; j < values.size(); j++){
            Y[i] += pow(j, i) * values[j];
        }
    }

    // Memorare valori pe ultima coloana a matricii A
    for (int i = 0; i <= grad; i++){
        A[i][grad + 1] = Y[i];
    }
    grad++;
   
    // Pivotare matrice A
    for (int i = 0; i < grad; i++){
        for (int k = i + 1; k < grad; k++)
            if (A[i][i] < A[k][i])
                for (int j = 0; j <= grad; j++) {
                    double temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
    }
    // Eliminarea Gaussiana (creare zerouri sub pivoti)
    for (int i = 0; i < grad - 1; i++){
        for (int k = i + 1; k < grad; k++){
            double t = A[k][i] / A[i][i];
            for (int j = 0; j <= grad; j++){
                A[k][j] -= t * A[i][j];
            }
        }
    }

    // UTRIS (Rezolvare Ax = b)
    for (int i = grad - 1; i >= 0; i--){
     c[i] = A[i][grad];
        for (int j = i + 1; j < grad; j++){
            c[i] -= A[i][j] * c[j];
        }
        c[i] /= A[i][i];
    }
  
    for (int i = 1; i <= values.size() + period; i++) {
        double curentValue = 0;
        for (int j = 0; j < grad; j++)
            curentValue += pow(i, j) * c[j];
        predict.push_back(curentValue);
   }

    return predict;
}