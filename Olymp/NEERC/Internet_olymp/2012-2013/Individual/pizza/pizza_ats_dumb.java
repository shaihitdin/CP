import java.util.*;
import java.io.*;

public class pizza_ats_dumb implements Runnable {
    StringTokenizer st;
    PrintWriter out;
    BufferedReader br;

    private String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public static void main(String[] args) {
        new pizza_ats_dumb().run();
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        long[] w = new long[n];
        String[] names = new String[n];
        for (int i = 0; i < n; i++) {
            names[i] = nextToken();
            w[i] = nextInt();
        }
        for (int i = 0; i < m; i++) {
            char c = nextToken().charAt(0);
            int a = nextInt() - 1;
            int b = nextInt();
            if (c == '!') {
                w[a] += (long) b;
            } else {
                long ans = 0;
                if (b <= names[a].length()) {
                    for (int j = 0; j < n; j++) {
                        if (names[j].length() >= b && names[j].length() <= names[a].length() &&
                                names[a].startsWith(names[j])) {
                            ans += w[j];
                        }
                    }
                }
                out.println(ans);
            }
        }
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("pizza.in"));
            out = new PrintWriter("pizza.out");

            solve();

            br.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
