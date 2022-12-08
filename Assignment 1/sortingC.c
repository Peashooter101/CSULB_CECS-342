#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

void qsortSection(int* a, int start, int end) {
    // One Element remains or Invalid Index
    if (start >= end) { return; }
    int pivot = a[end];
    int pivotLoc = end;
    bool pivotSwapped = false;
    // For every element from front to back...
    for (int i = start; i < end; i++) {
        // If the element is larger than the pivot...
        if (a[i] > pivot) {
            // Check for any elements between the larger and pivot...
            for (int j = i+1; j <= end; j++) {
                // If it is just the pivot and the larger remaining, swap them.
                if (j == end) {
                    pivotLoc = i;
                    pivotSwapped = true;
                    swap (a+j, a+i);
                    break;
                }
                // That are smaller than the pivot and swap them...
                else if (a[j] < pivot) {
                    swap (a+j, a+i);
                    break;
                }
            }
        }
        // If the pivot got swapped, we found the right spot for the pivot...
        if (pivotSwapped) { break; }
    }
    // Sort the left side of the pivot...
    qsortSection(a, start, pivotLoc-1);
    // Sort the right side of the pivot...
    qsortSection(a, pivotLoc+1, end);
}

void qsort2(int* a, int n) {
    qsortSection(a, 0, n-1);
}

void merge (int* a, int l, int mid, int r) {
    // Create left and right arrays
    int lSize = mid-l+1;
    int rSize = r-mid;
    int left[lSize];
    int right[rSize];
    for (int i = 0; i < lSize; i++) {
        left[i] = a[l+i];
    }
    for (int i = 0; i < rSize; i++) {
        right[i] = a[mid+1+i];
    }

    // Go through both arrays and put into new array positions...
    int lIter = 0;
    int rIter = 0;
    int aLoc = l;
    // Until one of the arrays runs out...
    while (lIter < lSize && rIter < rSize) {
        if (left[lIter] < right[rIter]) {
            a[aLoc] = left[lIter];
            lIter++;
        }
        else {
            a[aLoc] = right[rIter];
            rIter++;
        }
        aLoc++;
    }
    // If there is still stuff in the left array...
    while (lIter < lSize) {
        a[aLoc] = left[lIter];
        aLoc++;
        lIter++;
    }
    // If there is still stuff in the right array...
    while (rIter < rSize) {
        a[aLoc] = right[rIter];
        aLoc++;
        rIter++;
    }
}

void mergeSort(int* a, int l, int r) {
    // Invalid Indexes
    if (l >= r) { return; }
    // Determine middle value.
    int mid = l + (r - l) / 2;
    // Divide the left-side problem more...
    mergeSort(a, l, mid);
    // Divide the right-side problem more...
    mergeSort(a, mid+1, r);
    // Merge the components...
    merge(a, l, mid, r);
}

void msort(int* a, int n) {
    mergeSort(a, 0, n-1);
}

int main(int argc, char *argv[]) {
    int arrQ[] = {6,5,10,3,2,1};
    int arrM[] = {6,5,10,3,2,1};
    printf("%d, %d, %d, %d, %d, %d\n", arrQ[0], arrQ[1], arrQ[2], arrQ[3], arrQ[4], arrQ[5]);
    qsort2(arrQ, 6);
    msort(arrM, 6);
    printf("%d, %d, %d, %d, %d, %d\n", arrQ[0], arrQ[1], arrQ[2], arrQ[3], arrQ[4], arrQ[5]);
    printf("%d, %d, %d, %d, %d, %d\n", arrM[0], arrM[1], arrM[2], arrM[3], arrM[4], arrM[5]);
    
    int arrQ2[] = {10, 2, 55, 891, 22, 1, -5};
    int arrM2[] = {10, 2, 55, 891, 22, 1, -5};
    printf("%d, %d, %d, %d, %d, %d\n", arrQ2[0], arrQ2[1], arrQ2[2], arrQ2[3], arrQ2[4], arrQ2[5]);
    qsort2(arrQ2, 7);
    msort(arrM2, 7);
    printf("%d, %d, %d, %d, %d, %d\n", arrQ2[0], arrQ2[1], arrQ2[2], arrQ2[3], arrQ2[4], arrQ2[5]);
    printf("%d, %d, %d, %d, %d, %d\n", arrM2[0], arrM2[1], arrM2[2], arrM2[3], arrM2[4], arrM2[5]);
}