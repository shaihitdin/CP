import java.io.*;
import java.util.*;

public class pizza_pk {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;

	public String nextToken() throws IOException {
		while ((st == null) || (!st.hasMoreTokens()))
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	class Node {
		int first, last;
		Node[] go;
		long w;

		Node() {
			go = new Node[26];
			first = -1;
			last = -1;
			w = 0;
		}

		void add(String s, int t, long w2, Node[] wh) {
			wh[t] = this;
			if (t == s.length()) {
				this.w = w2;
				return;
			}
			if (go[s.charAt(t) - 'a'] == null)
				go[s.charAt(t) - 'a'] = new Node();
			go[s.charAt(t) - 'a'].add(s, t + 1, w2, wh);
		}

		public void dfs(ArrayList<Long> search) {
			first = search.size();
			search.add(w);
			for (int i = 0; i < 26; i++) {
				if (go[i] != null)
					go[i].dfs(search);
			}
			last = search.size();
			search.add(-w);
		}
	}

	public void solve() throws IOException {
		int n = nextInt();
		int m = nextInt();
		Node root = new Node();
		long[] w = new long[n];
		Node[][] wh = new Node[n][];
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			wh[i] = new Node[s.length() + 1];
			w[i] = nextInt();
			root.add(s, 0, w[i], wh[i]);
		}

		ArrayList<Long> search = new ArrayList<Long>();

		root.dfs(search);

		long[] fenv = new long[search.size() + 1];
		for (int i = 0; i < search.size(); i++) {
			add(fenv, i, search.get(i));
		}

		for (int i = 0; i < m; i++) {
			String q = nextToken();
			int x = nextInt() - 1;
			int y = nextInt();
			if (q.equals("?")) {
				if (y >= wh[x].length) {
					out.println(0);
				} else {
					out.println(get(fenv, wh[x][y].first,
							wh[x][wh[x].length - 1].first));
				}
			} else {
				add(fenv, wh[x][wh[x].length - 1].first, y);
				add(fenv, wh[x][wh[x].length - 1].last, -y);
				w[x] += y;
			}
		}
	}

	private long get(long[] fenv, int l, int r) {
		r++;
		return get(fenv, r) - get(fenv, l);
	}

	private long get(long[] fenv, int l) {
		long ans = 0;
		while (l > 0) {
			ans += fenv[l];
			l = l - f(l);
		}
		return ans;
	}

	private int f(int l) {
		return l - (l & (l - 1));
	}

	private void add(long[] fenv, int i, long add) {
		i++;
		while (i < fenv.length) {
			fenv[i] += add;
			i = i + f(i);
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
		new pizza_pk().run();
	}
}