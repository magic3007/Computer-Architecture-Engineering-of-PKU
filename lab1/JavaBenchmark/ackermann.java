import java.util.*;

public class ackermann {

    static int ack(int m, int n) {
        if (m == 0) return n + 1;
        if (n == 0) return ack(m - 1, 1);
        return ack(m -1, ack(m, n -1));
    }

    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Lack of Parameters!");
            System.exit(-1);
        }
        int m = Integer.parseInt(args[0]);
        int n = Integer.parseInt(args[1]);

        long startTimestemp = System.currentTimeMillis();

        System.out.println(ack(m, n));

        long endTimestemp = System.currentTimeMillis();

        System.out.println("Elapsed time: " + (endTimestemp - startTimestemp) + " ms.");

    }
}