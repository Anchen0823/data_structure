#ifndef HEADER_9_11_H
#define HEADER_9_11_H
template <class T>
void insertionSort(T a[], int n) {
    int i, j;
    T temp;

    for (int i=1;i<n;i++) {
        int j=i;
        T temp = a[i];
        while (j>0 && temp < a[j-1]) {
            a[j]=a[j-1];
            j--;
        }
        a[j] = temp;
    }
}
#endif      //HEADER_9_11_H