#include <bits/stdc++.h>


void usage(int argc, char const *argv[]){
    fprintf(stderr,
        "C Benchmark: General Matrix Multiplication(GEMM).\n"
        "Usage:\n" 
        "   %s <N> <K> <M>\n"
        "Description:\n"
        "   Calculate the multiplication of Matrix A_{NxK} and Matrix B_{KxM}.\n",
        argv[0]
    );
}


void gemm(int *A, int *B, int *C, int N, int K, int M){
    for(int i = 0; i < N; i++)
        for(int k = 0; k < K; k++)
            for(int j = 0; j < M; j++)
                C[i * M + j]+=A[i * K + k] * B[k * M + j];  
}

int main(int argc, char const *argv[]){
    if(argc != 4){
        usage(argc, argv);
        exit(EXIT_FAILURE);
    }
    int N = atoi(argv[1]);
    int K = atoi(argv[2]);
    int M = atoi(argv[3]);

    int (*A)[K] = (int (*)[K])malloc(sizeof(int) * N * K);
    int (*B)[M] = (int (*)[M])malloc(sizeof(int) * K * M);
    int (*C)[M] = (int (*)[M])malloc(sizeof(int) * N * M);

    memset((int*)C, 0, sizeof(int) * N * M);    

    gemm((int*)A, (int*)B, (int*)C, N, K, M);

    free(A);
    free(B);
    free(C);
    return 0;
}
