// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int MAX = 10;

void readMatrix(int mat[MAX][MAX], int rows, int cols, const string& name) {
    cout << "\n--- Enter elements for Matrix " << name << " (" << rows << "x" << cols << ") ---\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(const int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(const int input[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0; // Initialize sum before accumulating
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];

    cout << "=========================================\n";
    cout << "        PART A: MATRIX TRANSPOSE         \n";
    cout << "=========================================\n";
    int rowsA, colsA;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    readMatrix(A, rowsA, colsA, "A");

    cout << "\nOriginal Matrix:\n";
    printMatrix(A, rowsA, colsA);


    transposeMatrix(A, result, rowsA, colsA);

    cout << "\nTransposed Matrix:\n";
    printMatrix(result, colsA, rowsA);

    cout << "\n=========================================\n";
    cout << "        PART B: MATRIX ADDITION          \n";
    cout << "=========================================\n";
    int rowsAdd, colsAdd;
    cout << "Enter number of rows for both matrices: ";
    cin >> rowsAdd;
    cout << "Enter number of columns for both matrices: ";
    cin >> colsAdd;

    readMatrix(A, rowsAdd, colsAdd, "A");
    readMatrix(B, rowsAdd, colsAdd, "B");

    addMatrices(A, B, result, rowsAdd, colsAdd);

    cout << "\nMatrix A + Matrix B:\n";
    printMatrix(result, rowsAdd, colsAdd);

    cout << "\n=========================================\n";
    cout << "     PART C: MATRIX MULTIPLICATION       \n";
    cout << "=========================================\n";
    int M, N, P;
    cout << "For Matrix A (M x N), enter rows M: ";
    cin >> M;
    cout << "For Matrix A (M x N), enter columns N: ";
    cin >> N;
    cout << "Matrix B will have rows N = " << N << ".\n";
    cout << "For Matrix B (N x P), enter columns P: ";
    cin >> P;

    readMatrix(A, M, N, "A");
    readMatrix(B, N, P, "B");

    multiplyMatrices(A, B, result, M, N, P);

    cout << "\nMatrix A x Matrix B (" << M << "x" << P << "):\n";
    printMatrix(result, M, P);

    return 0;
}
