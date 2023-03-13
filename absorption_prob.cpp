#include <bits/stdc++.h>
using namespace std;

void absorption_prob (int n, float** M, float** A, float** G) {
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            float sum = 0;
            for (int k = 0; k<n; k++) {
                sum += M[i][k] * A[k][j];
            }
            G[i][j] = sum;
        }
    }
}

int main () {
    int n = 2;
    
    float** M = new float* [n];      
    for (int i = 0; i<n; i++) {
        M[i] = new float[n];
    }
    
    float** A = new float* [n];      
    for (int i = 0; i<n; i++) {
        A[i] = new float[n];
    }

    ifstream indata;
    indata.open("input3.txt");
    if(!indata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }
    while ( !indata.eof() ) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                indata >> M[i][j];
            }
        }
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                indata >> A[i][j];
            }
        }
    }
    
    float** G = new float* [n];      
    for (int i = 0; i<n; i++) {
        G[i] = new float[n];
    }
    
    absorption_prob(n,M,A,G);
    
    cout << "The matrix G is given by: " << endl << endl;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
 
    
    return 0;
}