#include <bits/stdc++.h>

void usage(int argc, char const *argv[]){
    fprintf(stderr,
        "C Benchmark: Quick Sort.\n"
        "Usage:\n" 
        "   %s <N>\n"
        "Description:\n"
        "   Sort an array with N elements in an ascending order.\n",
        argv[0]
    );
}

void quickSort(int *a, int l, int r){
    if(l>=r) return;
    int i = l, j = r, mid = a[(l+r)>>1];
    while(i<=j){
        while(a[i] < mid) i++;
        while(mid < a[j]) j--;
        if(i<=j) std::swap(a[i],a[j]), i++, j--;
    }
	if(l < j)quickSort(a, l, j);
	if(i < r)quickSort(a, i, r);
}

int main(int argc, const char** argv) {
    if(argc != 2){
        usage(argc, argv);
        exit(EXIT_FAILURE);
    }
    int N = atoi(argv[1]);
    int *arr = (int*)malloc(sizeof(int) * N);
    quickSort(arr, 0, N-1);
    free(arr);
    return 0;
}