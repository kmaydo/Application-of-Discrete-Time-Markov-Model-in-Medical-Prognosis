#include <bits/stdc++.h>
using namespace std;

void Mult (int n, float** P, float** M, float** a) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            float sum = 0;
            for (int k = 0; k<n; k++) {
                sum += M[i][k] * P[k][j];
            }
            a[i][j] = sum;
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            M[i][j] = a[i][j];
        }
    }
}

int main () {
    int n = 3;
    float** P = new float* [n];      
    for (int i = 0; i<n; i++) {
        P[i] = new float[n];
    }

    ifstream indata;
    indata.open("input1.txt");
    if(!indata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }
    while ( !indata.eof() ) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                indata >> P[i][j];
            }
        }
    }
    
    float** M = new float* [n];      
    for (int i = 0; i<n; i++) {
        M[i] = new float[n];
    }
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            M[i][j] = P[i][j];
        }
    }
    
    float** a = new float* [n];      
    for (int i = 0; i<n; i++) {
        a[i] = new float[n];
    }
    
    for (int k = 1; k<10; k++) {
        Mult (n,P,M,a);
        if (k == 3 || k == 9) {
            cout << "P power " << k+1 << " is given by:" << endl << endl;
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    cout << M[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    
    return 0;
}