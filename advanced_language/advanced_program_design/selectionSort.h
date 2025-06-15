#ifndef HEADER_9_12_H
#define HEADER_9_12_H

// 交换x和y
template <class T>
void mySwap(T &x, T &y) {
    T temp=x;
    x=y;
    y=temp;
}

template <class T>
void selectionSort(T a[], int n) {
    for (int i=0;i<n-1;i++) {
        int leastIndex = i;
        for (int j=i+1;j<n;j++) {
            if (a[j] < a[leastIndex]) leastIndex = j;
        }
        mySwap(a[i], a[leastIndex]);
    }
}
#endif      //HEADER_9_12_H