#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <sys/time.h>

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


template<class T>
void gemm(void *A_, void *B_, void *C_, int N, int K, int M){
    T (*A)[K] = (T (*)[K])A_;
    T (*B)[M] = (T (*)[M])B_;
    T (*C)[M] = (T (*)[M])C_;

    for(int i = 0; i < N; i++)
        for(int k = 0; k < K; k++)
            for(int j = 0; j < M; j++)
                C[i][j] += A[i][k] * B[k][j];
}

int main(int argc, char const *argv[]){
    if(argc != 4){
        usage(argc, argv);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);
    int K = atoi(argv[2]);
    int M = atoi(argv[3]);

    using ElementType = float;

    void *A = malloc(sizeof(ElementType) * N * K);
    void *B = malloc(sizeof(ElementType) * K * M);
    void *C = calloc(N * M, sizeof(ElementType));

    struct timeval start, end;
    gettimeofday(&start, nullptr);

    gemm<ElementType>(A, B, C, N, K, M);

    gettimeofday(&end, nullptr);
    uint64_t delta = (end.tv_sec * 1000000 + end.tv_usec) 
        - (start.tv_sec * 1000000 + start.tv_usec);

    fprintf(stderr, "Elasped Time: %lu ms.\n",delta / 1000);

    free(A);
    free(B);
    free(C);
    return 0;
}
