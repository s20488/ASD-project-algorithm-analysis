# include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

//Generowanie i wyświetlanie tablicy i tablicy odwrotnej zawierającej 6 elementów
int A[6];

void randomArr() {
    for (int i = 0; i <= 6; i++) {
        A[i] = 1 + rand() % 100;
    }
}

void showArr() {
    for (int i = 0; i <= 6; i++) {
        cout << A[i] << " ";
    }
}

void reverseArr() {
    sort(A, A + 7, greater<int>());
}

//QuickSort
int partition(int A[], int lo, int hi){
    int pivot = A[hi];
    int i = lo;
    int temp;

    for (int j = lo; j < hi; j++) {
        if (A[j] < pivot){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
        }
    }

    temp = A[i];
    A[i] = A[hi];
    A[hi] = temp;

    return i;
}


void quicksort(int A[], int lo, int hi) {
    if (lo < hi) {
        int q = partition(A, lo, hi);
        quicksort(A, lo, q - 1);
        quicksort(A, q+1, hi);
    }
}

//Heapsort
void buildHeapsort(int A[], int hi, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < hi && A[left] > A[largest]) {
        largest = left;
    }

    if (right < hi && A[right] > A[largest]) {
    largest = right;
    }

    if (largest != i) {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        buildHeapsort(A, hi, largest);
    }
}

void heapsort(int A[], int hi){
    for (int i = hi / 2 - 1; i >= 0; i--) {
        buildHeapsort(A, hi, i);
    }

    for (int i = hi - 1; i >= 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        buildHeapsort(A, i, 0);
    }
}

//Sortowanie przez wstawianie
void insertionSort(int A[], int hi){
    int temp1, temp2;

    for(int i = hi - 2; i >= 0; i--) {
        temp2 = A[i];
        temp1 = i + 1;

        while((temp1 < hi) && (temp2 > A[temp1])) {
            A[temp1 - 1] = A[temp1];
            temp1++;
        }
        A[temp1 - 1] = temp2;
    }
}

//Sortowanie przez wybór
void selectionSort(int A[], int hi){
    int min;

    for(int i = 0; i < hi - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < hi; j++)
            if(A[j] < A[min]) min = j;
        swap(A[min], A[i]);
    }
}

//Czas wykonania algorytmów
void quickSortTimeCounting(int A[]) {
    cout << "--------------------------------------";
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    quicksort(A,0,6);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();
    cout << "\nQuicksort time: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n\n";
}

void heapsortTimeCounting(int A[]) {
    cout << "--------------------------------------";
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    heapsort(A, 6);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();
    cout << "\nHeapsort time: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n\n";
}

void insertionSortTimeCounting(int A[]) {
    cout << "--------------------------------------";
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    insertionSort(A, 6);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();
    cout << "\nInsertionSort time: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n\n";
}

void selectionSortTimeCounting(int A[]) {
    cout << "--------------------------------------";
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    selectionSort(A, 6);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();
    cout << "\nSelectionSort time: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n\n";
}
int main() {
    srand(time(NULL));

    cout << "QuickSort: " << endl;
    randomArr();
    cout << "UNSORTED: [ ";
    showArr();
    cout << "]" << endl;
    quicksort(A, 0, 6);
    cout << "SORTED: [ ";
    showArr();
    cout << "]" << endl;
    reverseArr();
    cout << "REVERSE SORTED: [ ";
    showArr();
    cout  << "]" << endl;
    quickSortTimeCounting(A);

    cout << "Heapsort: " << endl;
    randomArr();
    cout << "UNSORTED: [ ";
    showArr();
    cout << "]" << endl;
    heapsort(A, 6);
    cout << "SORTED: [ ";
    showArr();
    cout << "]" << endl;
    reverseArr();
    cout << "REVERSE SORTED: [ ";
    showArr();
    cout  << "]" << endl;
    heapsortTimeCounting(A);

    cout << "InsertionSort: " << endl;
    randomArr();
    cout << "UNSORTED: [ ";
    showArr();
    cout << "]" << endl;
    insertionSort(A, 6);
    cout << "SORTED: [ ";
    showArr();
    cout << "]" << endl;
    reverseArr();
    cout << "REVERSE SORTED: [ ";
    showArr();
    cout  << "]" << endl;
    insertionSortTimeCounting(A);

    cout << "SelectionSort: " << endl;
    randomArr();
    cout << "UNSORTED: [ ";
    showArr();
    cout << "]" << endl;
    selectionSort(A, 6);
    cout << "SORTED: [ ";
    showArr();
    cout << "]" << endl;
    reverseArr();
    cout << "REVERSE SORTED: [ ";
    showArr();
    cout  << "]" << endl;
    selectionSortTimeCounting(A);
}