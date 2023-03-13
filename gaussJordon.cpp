#include <bits/stdc++.h>
using namespace std;

void inverse (int n, float** J) {
    float temp;   // for storing swapped variable
    // Pivotings and eliminations
    for(int i = 0; i<n; i++) {   // Repeated pivoting and elimination till we get R.E. form
    
        // Partial pivoting
        for (int j = i+1; j<n; j++) {   // check for the absolute largest element 
                                        // in each column and make it pivot
            if (abs(J[i][i]) < abs(J[j][i]) ) {
                for (int k = 0; k<2*n; k++){   //swap rows if found
                    temp = J[j][k];
                    J[j][k] = J[i][k];
                    J[i][k] = temp;
                }
            }
        }
            
        float d = J[i][i];  // making the leading coefficient 1 in each row and updating each row.
        for (int k =0;k<2*n;k++) {
            J[i][k] = J[i][k]/d;
        }
    
        // Elimination 
        for (int j = i+1; j < n; j++) {    // All the elements below pivot made zero
            float f = J[j][i]/J[i][i];   // Factor
            for (int k = 0; k<2*n; k++) {  // Update all rows below pivot row.
                J[j][k] -= f*J[i][k];
            }
        }
    
    }
    
    // Row reduced echelon form(identity matrix) from row echelon form
    for (int i = 0; i<n; i++) {    // Updating ith row, making elements of A zero, except for diagonal element.
        for (int j =i+1; j<n; j++) {
            float g = J[i][j];   // Factor 
            for (int k = 0; k<2*n; k++) {  // Multiply g with jth row and subtract from ith row to update ith row.
                J[i][k] = J[i][k] - g*J[j][k];
            }
        }
    }
}


int main () {
    int n = 2;
    float** B = new float* [n];      
    for (int i = 0; i<n; i++) {
        B[i] = new float[n];
    }

    ifstream indata;
    indata.open("input2.txt");
    if(!indata) { // file couldn't be opened
      cerr << "Error: file could not be opened" << endl;
      exit(1);
    }
    while ( !indata.eof() ) {
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                indata >> B[i][j];
            }
        }
    }
    
    float** M = new float* [n];      
    for (int i = 0; i<n; i++) {
        M[i] = new float[n];
    }
    
    float I[n][n];
    for (int i = 0; i<n ; i++) {
        for (int j = 0; j<n; j++) {
            if (i != j) {
                I[i][j] = 0;
            }
        }
        I[i][i] = 1;
    }
    
    for (int i = 0; i<n ; i++) {
        for (int j = 0; j<n; j++) {
            M[i][j] = I[i][j] - B[i][j];
        }
    }
    
    float** J = new float* [n];      
    for (int i = 0; i<n; i++) {
        J[i] = new float[2*n];
    }
    
    for (int i = 0; i<n ;i++) {
        for (int j = 0; j<n; j++) {
            J[i][j] = M[i][j];
            if (i != j) {
                J[i][i+n] = 0;
            }
        }
        J[i][i+n] = 1;
    }
    inverse (n,J);
    
    cout << "The matrix M is given by: " << endl << endl;
    for (int i = 0; i<n ; i++) {
        for (int j = 0; j<n; j++) {
            cout << J[i][j+n] << " ";
        }
        cout << endl;
    }
    
    return 0;
}