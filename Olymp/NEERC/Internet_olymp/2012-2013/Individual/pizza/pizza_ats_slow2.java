import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class pizza_ats_slow2 implements Runnable {
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
        new pizza_ats_slow2().run();
    }

    private class Trie {
        public class Node {
            Node prev;
            int depth;
            int terminal;
            Node[] next;

            public Node() {
                next = new Node[26];
                terminal = -1;
            }

            public void setNext(char c, Node n) {
                next[(int) (c - 'a')] = n;
            }

            public Node getNext(char c) {
                return next[(int) (c - 'a')];
            }
        }

        Node root;

        public Trie() {
            root = new Node();
            root.depth = 0;
        }

        public void add(String s, int num) {
            Node cur = root;
            Node last = root;
            for (int i = 0; i < s.length(); i++) {
                if (cur.getNext(s.charAt(i)) == null) {
                    Node n = new Node();
                    n.depth = cur.depth + 1;
                    cur.setNext(s.charAt(i), n);
                }
                cur = cur.getNext(s.charAt(i));
            }
            cur.terminal = num;
            pos[num] = cur;
        }

        public void calcPrev(Node cur, Node last) {
            cur.prev = last;
            if (cur.terminal != -1) {
                last = cur;
            }
            for (int i = 0; i < cur.next.length; i++) {
                if (cur.next[i] != null) {
                    calcPrev(cur.next[i], last);
                }
            }
        }

        public long calc(Node v, int minLen) {
            long ans = 0;
            Node cur = v;
            while (cur.depth >= minLen) {
                ans += w[cur.terminal];
                cur = cur.prev;
            }
            return ans;
        }
    }

    Trie.Node[] pos;
    long[] w;

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        Trie t = new Trie();
        w = new long[n];
        pos = new Trie.Node[n];
        for (int i = 0; i < n; i++) {
            String name = nextToken();
            t.add(name, i);
            w[i] = nextInt();
        }
        t.calcPrev(t.root, t.root);
        for (int i = 0; i < m; i++) {
            char c = nextToken().charAt(0);
            int a = nextInt() - 1;
            int b = nextInt();
            if (c == '!') {
                w[a] += (long) b;
            } else {
                out.println(t.calc(pos[a], b));
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
