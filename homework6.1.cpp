#include <iostream>

using namespace std;

const int MAX_1D = 100;
const int MAX_2D = 10;

void printNotDivBy7_1D_Index(const int arr[], int size) {
    cout << "Индексы (через []): ";
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 7 != 0) {
            cout << i << " "; 
        }
    }
    cout << endl;
}

void printNotDivBy7_1D_Pointer(const int* arr, int size) {
    cout << "Индексы (через указатели): ";
    const int* end = arr + size; 
    int index = 0;
    
    for (const int* ptr = arr; ptr < end; ++ptr, ++index) {
        if (*ptr % 7 != 0) {
            cout << index << " ";
        }
    }
    cout << endl;
}

void printNotDivBy7_2D_Index(const int matrix[][MAX_2D], int rows, int cols) {
    cout << "Координаты (через []): ";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % 7 != 0) {
                cout << "[" << i << "][" << j << "] ";
            }
        }
    }
    cout << endl;
}

void printNotDivBy7_2D_Pointer(const int* firstElem, int rows, int cols, int maxCols) {
    cout << "Координаты (через указатели): ";
    const int* rowPtr = firstElem; 
    for (int i = 0; i < rows; ++i) {
        const int* colPtr = rowPtr; 
        for (int j = 0; j < cols; ++j) {
            if (*colPtr % 7 != 0) {
                cout << "[" << i << "][" << j << "] ";
            }
            ++colPtr; 
        }
        rowPtr += maxCols; 
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int arr[MAX_1D];
    int n;
    cout << "=== ОДНОМЕРНЫЙ МАССИВ ===" << endl;
    cout << "Введите размер массива (до " << MAX_1D << "): ";
    cin >> n;
    
    if (n <= 0 || n > MAX_1D) {
        cout << "Некорректный размер!" << endl;
        return 1;
    }

    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    printNotDivBy7_1D_Index(arr, n);
    printNotDivBy7_1D_Pointer(arr, n);

    int matrix[MAX_2D][MAX_2D];
    int rows, cols;
    cout << "\n=== ДВУМЕРНЫЙ МАССИВ ===" << endl;
    cout << "Введите количество строк и столбцов (до " << MAX_2D << "x" << MAX_2D << "): ";
    cin >> rows >> cols;

    if (rows <= 0 || rows > MAX_2D || cols <= 0 || cols > MAX_2D) {
        cout << "Некорректные размеры матрицы!" << endl;
        return 1;
    }

    cout << "Введите элементы матрицы (" << rows * cols << " чисел):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    printNotDivBy7_2D_Index(matrix, rows, cols);
    printNotDivBy7_2D_Pointer(&matrix[0][0], rows, cols, MAX_2D);

    return 0;
}
