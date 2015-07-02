import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class pizza_ats implements Runnable {
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
        new pizza_ats().run();
    }

    private class Trie {
        public class Node {
            Node prev;
            int id;
            int depth;
            int terminal;
            int[] next;
            int[] up;

            public Node() {
                next = new int[26];
                Arrays.fill(next, -1);
                up = new int[30];
                Arrays.fill(up, 0);
                terminal = -1;
            }

            public void setNext(char c, int n) {
                next[(int) (c - 'a')] = n;
            }

            public int getNext(char c) {
                return next[(int) (c - 'a')];
            }
        }

        ArrayList<Node> nodes;
        Node root;
        int cnt;

        public Trie() {
            nodes = new ArrayList<Node>();
            root = new Node();
            root.depth = 0;
            root.id = 0;
            cnt = 0;
            nodes.add(root);
        }

        public void add(String s, int num) {
            Node cur = root;
            for (int i = 0; i < s.length(); i++) {
                if (cur.getNext(s.charAt(i)) == -1) {
                    Node n = new Node();
                    cnt++;
                    n.id = cnt;
                    nodes.add(n);
                    n.depth = cur.depth + 1;
                    cur.setNext(s.charAt(i), n.id);
                    n.up[0] = cur.id;
                    for (int j = 1; j < n.up.length; j++) {
                        n.up[j] = nodes.get(n.up[j - 1]).up[j - 1];
                    }
                    n.prev = cur;
                }
                cur = nodes.get(cur.getNext(s.charAt(i)));
            }
            cur.terminal = num;
            pos[num] = cur;
        }

        public void makeEuler(Node v) {
            euler.add(v.id);
            last[v.id] = euler.size();
            first[v.id] = euler.size();
            for (int i = 0; i < v.next.length; i++) {
                if (v.next[i] != -1) {
                    way.add(1);
                    makeEuler(nodes.get(v.next[i]));
                    way.add(-1);
                    euler.add(v.id);
                    last[v.id] = euler.size();
                }
            }
        }
    }

    Trie.Node[] pos;
    long[] w;
    int[] first;
    int[] last;
    ArrayList<Integer> euler;
    ArrayList<Integer> way;

    private class SegTree {
        private final int SIZE = 2 * 1048576;
        long[] t;

        public SegTree() {
            t = new long[SIZE * 2];
        }

        public void set(int pos, long val) {
            int cur = SIZE + pos;
            t[cur] = val;
            while (cur > 1) {
                cur /= 2;
                t[cur] = t[cur * 2] + t[cur * 2 + 1];
            }
        }

        public void change(int pos, long delta) {
            long newVal = t[SIZE + pos] + delta;
            set(pos, newVal);
        }

        public long get(int l, int r) {
            int i = l + SIZE;
            int j = r + SIZE;
            long ans = 0;
            while (i <= j) {
                if (i % 2 != 0) {
                    ans += t[i];
                    i++;
                }
                if (j % 2 == 0) {
                    ans += t[j];
                    j--;
                }
                i /= 2;
                j /= 2;
            }
            return ans;
        }
    }

    public int getUp(Trie.Node v, int targetDepth) {
        int last = v.up.length - 1;
        Trie.Node cur = v;
        while (cur.depth != targetDepth) {
            if (t.nodes.get(cur.up[last]).depth < targetDepth) {
                last--;
            } else {
                cur = t.nodes.get(cur.up[last]);
            }
        }
        return cur.id;
    }

    Trie t;

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        t = new Trie();
        w = new long[n];

        pos = new Trie.Node[n];
        for (int i = 0; i < n; i++) {
            String name = nextToken();
            t.add(name, i);
            w[i] = nextInt();
        }
        first = new int[t.cnt + 10];
        last = new int[first.length];
        euler = new ArrayList<Integer>();
        way = new ArrayList<Integer>();
        way.add(0);
        t.makeEuler(t.root);
//        out.println(euler.toString());
//        out.println(way.toString());
//        System.err.println(euler.size());
        SegTree tree = new SegTree();
        for (int i = 0; i < n; i++) {
            tree.set(first[pos[i].id], w[i]);
            tree.set(last[pos[i].id] + 1, -w[i]);
        }
        for (int i = 0; i < m; i++) {
            char c = nextToken().charAt(0);
            int a = nextInt() - 1;
            int b = nextInt();
            if (c == '!') {
//                System.err.println(a);
                tree.change(first[pos[a].id], b);
                tree.change(last[pos[a].id] + 1, -b);
            } else {
                if (b > pos[a].depth) {
                    out.println(0);
                    continue;
                }
                if (b == pos[a].depth) {
                    out.println(tree.get(first[pos[a].id], first[pos[a].id]));
                    continue;
                }
                int r = first[pos[a].id];
                int l = first[getUp(pos[a], b)];
                out.println(tree.get(l, r));
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
