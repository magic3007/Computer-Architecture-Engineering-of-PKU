import java.util.*;

public class gemm{

    
    public static void multiply(float[][] A, float[][] B, float[][] C,
        int N, int K, int M){
            for(int i = 0; i < N; i++){
                for(int k = 0; k < K; k++){
                    for(int j = 0; j < M; j++){
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }

    public static void main(String[] args) {
        if (args.length != 3) {
            System.err.println("Lack of Parameters!");
            System.exit(-1);
        }
        int N = Integer.parseInt(args[0]);
        int K = Integer.parseInt(args[1]);
        int M = Integer.parseInt(args[2]);

        float [][] A = new float[N][K];
        float [][] B = new float[K][M];
        float [][] C = new float[N][M];

        for(int i = 0; i < N; i++)
            for(int j  = 0; j < M; j++)
                C[i][j] = 0;
            
        long startTimestemp = System.currentTimeMillis();

        multiply(A, B, C, N, K, M);

        long endTimestemp = System.currentTimeMillis();

        System.out.println("Elapsed time: " + (endTimestemp - startTimestemp) + " ms.");

    }
}