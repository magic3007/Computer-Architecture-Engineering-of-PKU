#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <sys/time.h>

void usage(int argc, char const *argv[]){
    fprintf(stderr,
        "C Benchmark: Ackermann Function.\n"
        "Usage:\n" 
        "   %s <m> <n>\n"
        "Description:\n"
        "   Calculate the Ackermann Function ack(m,n).\n",
        argv[0]
    );
}


int ackermann(int m, int n){
  if (m == 0) return n+1;
  if (n == 0) return ackermann( m - 1, 1 );
  return ackermann( m - 1, ackermann( m, n - 1 ) );
}

int main(int argc, const char** argv) {
    if(argc != 3){
        usage(argc, argv);
        exit(EXIT_FAILURE);
    }
    int m = atoi(argv[1]);
    int n = atoi(argv[2]); 

    struct timeval start, end;
    gettimeofday(&start, nullptr);
    
    printf("%d\n", ackermann(m, n));
    
    gettimeofday(&end, nullptr);
    uint64_t delta = (end.tv_sec * 1000000 + end.tv_usec) 
        - (start.tv_sec * 1000000 + start.tv_usec);

    fprintf(stderr, "Elasped Time: %lu ms.\n",delta / 1000);

    return 0;
}