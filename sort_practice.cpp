//practice creating and using Mergesort and Quicksort in cpp

int main() {
    int arr[]={10,34,664,1,98,235,87,111,45};
    mergeSort(arr, arr[0], arr[(arr.length - 1)]);
}

void merge(int arr[], int b, int c, int r) {
    int nL = c - b + 1;
    int nR = r - c;

    new leftArr[0:(nL-1)];
    new rightArr[0:(nR-1)];

    for(i=0; i<=(nL-1); i++) {
        leftArr[i] = arr[b+i];
    }
    for(j=0; j<=(nR-1); j++) {
        rightArr[j] = arr[c+j+1];
    }

    i, j = 0;
    int k = b;

    while (i < nL && j < nR) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    while (i < nL) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < nR) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int b, int r) {
    if (b >= r)
        return;

    int c = (b+r)/2;
    mergeSort(arr, b, c);
    mergeSort(arr, c+1, r);
    merge(arr, b, c, r);
}