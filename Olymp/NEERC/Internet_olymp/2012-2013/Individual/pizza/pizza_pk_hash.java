import java.io.*;
import java.util.*;

public class pizza_pk_hash {

	PrintWriter out;
	BufferedReader br;
	StringTokenizer st;

	String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		String[] s = new String[n];
		long[] w = new long[n];
		long[][] hash = new long[n][];
		for (int i = 0; i < n; i++) {
			s[i] = nextToken();
			w[i] = nextInt();
			hash[i] = new long[s[i].length()];
			hash[i][0] = s[i].charAt(0);
			for (int j = 1; j < s[i].length(); j++) {
				hash[i][j] = hash[i][j - 1] * 259 + s[i].charAt(j);
			}
		}
		for (int i = 0; i < m; i++) {
			String q = nextToken();
			int x = nextInt() - 1;
			int y = nextInt();
			if (q.equals("!")) {
				w[x] = w[x] + y;
			} else {
				long ans = 0;
				for (int j = 0; j < n; j++) {
					if (s[j].length() > s[x].length() || s[j].length() < y)
						continue;
					if (hash[j][s[j].length() - 1] == hash[x][s[j].length() - 1])
						ans = ans + w[j];
				}
				out.println(ans);
			}
		}

	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader("pizza.in"));
			out = new PrintWriter("pizza.out");

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new pizza_pk_hash().run();
	}
}
