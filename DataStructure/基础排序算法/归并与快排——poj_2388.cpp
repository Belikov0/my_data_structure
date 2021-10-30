#include <iostream>

using namespace std;
const int INF = 100001;

// merge means merging two array
void merge(int* A, int begin, int dot, int end){
    int left[5001];                     // dot-begin+1 means how many that left[] should store
    int right[5001];

    int i, j, k;
    for (i = 0; i < dot - begin + 1; ++i)
        left[i] = A[i+begin]; // left[] is started from 0, and the left of A[] is started from 'begin'


    for (j = 0; j < end-dot; ++j)
        right[j] = A[j+dot+1];  // right[] is started from 0, and the right of A[] is started from 'dot+1'

    left[dot-begin+1] = INF; // if INF, it can not be sorted into A[]
    right[end-dot] = INF;

    i = 0, j = 0;
    for (k = begin; k <= end; ++k) {
        if (left[i] > right[j])  //(ascending order, while INF > 0
            A[k] = right[j++];
        else
            A[k] = left[i++];
    }
}

void merge_Sort(int * A, int begin, int end){
    if(end > begin)
    {
        int dot = (begin + end) / 2;
        merge_Sort(A, begin, dot);
        merge_Sort(A, dot + 1, end);
        merge(A, begin, dot, end);
    }
}

int partition(int* A, int left, int right){
    int pivot = A[left];

    while (left < right){
        while (left < right && A[right] >= pivot)
            right--;
        A[left] = A[right];

        while (left < right && A[left] <= pivot) //
            left++;
        A[right] = A[left];
    }
    A[left] = pivot;

    return left;
}

void quickSort(int* A, int begin, int end){
    if (end > begin){
        int mid = partition(A, begin, end );
        quickSort(A, begin, mid-1);
        quickSort(A, mid+1, end);
    }
}


int findMiddle(int * A, int len){
    return A[(len-1)/2];
}

int main (){
    int array[10000];

    int nums = 0;
    cin >> nums;
    for (int i = 0; i < nums; ++i) {
        long n ;
        cin >> n;
        array[i] = n;
    }
//    merge_Sort(array, 0, nums - 1);
    quickSort(array, 0, nums-1);
    cout << findMiddle(array, nums) ;

}