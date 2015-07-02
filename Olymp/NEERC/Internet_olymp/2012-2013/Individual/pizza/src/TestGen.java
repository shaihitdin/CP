import java.util.*;
import java.io.*;

public class TestGen implements Runnable {
    private ArrayList<String> data;
    private int done;

    private Random rnd;

    private void print() throws IOException {
        String filename = "" + (done + 1);
        if (done < 9) {
            filename = "0" + filename;
        }
        PrintWriter out = new PrintWriter(new File(curOut + "\\" + filename));
        for (int i = 0; i < data.size(); i++) {
            out.println(data.get(i));
        }
        out.close();
        done++;
        System.out.println(done);
        data.clear();
    }

    private int nextInt(int low, int high) {
        return Math.abs(rnd.nextInt()) % (high - low + 1) + low;
    }

    String curOut;

    public void initOut(String folderName) {
        done = 0;
        curOut = folderName;
        File testDir = new File(curOut);
        if (!testDir.exists()) {
            testDir.mkdir();
        }
    }

    private final int SMALLLEN = (int) 1e4;

    private final int SMALLQ = 100;
    private final int MEDQ = 10000;
    private final int MAXQ = (int) 1e6;

    private final int SMALLLEFT = (int) 1e5;
    private final int MAXLEFT = (int) 1e6;

    private final int MAXCOST = (int) 1e9;

    public void run() {
        try {
            data = new ArrayList<String>();
            rnd = new Random(94756);

            initOut("..\\preliminary");
            genSample1();
            genSample2();

            initOut("..\\tests");


            // 6 tests, m <= 100, S <= 10^5
            genMask(false, SMALLQ, SMALLLEFT, SMALLLEN);
            genMask(true, SMALLQ, SMALLLEFT, SMALLLEN);
            genLetters(1, SMALLQ, SMALLLEFT, SMALLLEN, false);
            genLetters(2, SMALLQ, SMALLLEFT, SMALLLEN, false);
            genLetters(10, SMALLQ, SMALLLEFT, SMALLLEN, false);
            genGrey(SMALLQ, SMALLLEFT, SMALLLEN);

            // 6 tests, m <= 10000, maxLen <= 10^4
            genTueMorse('a', 'z', MEDQ, MAXLEFT, SMALLLEN);
            genTueMorse('b', 'y', MEDQ, MAXLEFT, SMALLLEN);
            genLetters(1, MEDQ, MAXLEFT, SMALLLEN, false);
            genLetters(2, MEDQ, MAXLEFT, SMALLLEN, false);
            genLetters(1, MEDQ, MAXLEFT, SMALLLEN, true);
            genTueMorse('a', 'b', MEDQ, MAXLEFT, SMALLLEN);

            // other

            genMask(false, MAXQ, MAXLEFT, MAXLEFT);
            genMask(true, MAXQ, MAXLEFT, MAXLEFT);
            genMask(true, MAXQ, MAXLEFT, MAXLEFT);
            genLetters(1, MAXQ, MAXLEFT, MAXLEFT, false);
            genLetters(2, MAXQ, MAXLEFT, SMALLLEN, false);
            genLetters(1, MAXQ, MAXLEFT, SMALLLEN, true);
            genLetters(2, MAXQ, MAXLEFT, SMALLLEN, true);
            genGrey(MAXQ, MAXLEFT, MAXLEFT);

        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public void genTueMorse(char c1, char c2, int queries, int total, int maxLen) throws IOException {
        int n = 0;
        data.add("");
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        sb1.append(c1);
        sb2.append(c2);
        while (total > 0) {
            if ((total < sb1.toString().length() + sb2.toString().length()) || sb1.length() * 2 >= maxLen) {
                break;
            }
            total -= sb1.toString().length() + sb2.toString().length();
            data.add(sb1.toString() + " " + nextInt(1, MAXCOST));
            data.add(sb2.toString() + " " + nextInt(1, MAXCOST));
            n += 2;
            String t1 = sb1.toString();
            String t2 = sb2.toString();
            sb1.append(t2);
            sb2.append(t1);
        }
        int last = n;
        while (total > 0) {
            sb1.append('a');
            if (total > sb1.toString().length()) {
                data.add(sb1.toString() + " " + nextInt(1, MAXCOST));
                n++;
                total -= sb1.toString().length();
            } else {
                break;
            }
        }
        data.set(0, n + " " + queries);
        for (int i = 0; i < 10; i++) {
            data.add("? " + last + " " + 1);
            data.add("? " + (last - 1) + " " + 1);
        }
        for (int i = 0; i < (queries - 20); i++) {
            data.add("? " + n + " " + 1);
        }
        print();
    }

    public String compile(char[] c) {
        StringBuilder sb = new StringBuilder();
        for (char cc : c) {
            sb.append(cc);
        }
        return sb.toString();
    }

    public String getString(int num, int len) {
        int nn = num;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
            sb.append((char) ('a' + nn % 26));
            nn /= 26;
        }
//        sb.reverse();
        return sb.toString();
    }

    public void genMask(boolean takeSmaller, int queries, int totalLen, int maxLen) throws IOException {
        ArrayList<Integer> lengths = new ArrayList<Integer>();
        data.add("");
        if (takeSmaller) {
            for (int i = 1; i <= 25; i++) {
                lengths.add(i);
            }
        }
        lengths.add(26);
        ArrayList<Integer> len = new ArrayList<Integer>();
        int leftLen = 0;
        int leftQ = 0;
        if (queries > SMALLQ) {
            leftLen = totalLen / 4;
            totalLen -= leftLen;
        }
        int n = 0;
        for (int curLen : lengths) {
            char[] c = new char[curLen];
            for (int i = 0; i < c.length; i++) {
                c[i] = 'a';
            }
            if (totalLen < curLen) {
                break;
            }
            data.add(compile(c) + " " + nextInt(1, MAXCOST));
            len.add(curLen);
            n++;
            totalLen -= curLen;
            int val = 1;
            for (int i = 0; i < curLen && val <= totalLen; i++) {
                val *= 26;
            }
            for (int i = 1; i < val && totalLen >= curLen; i++) {
                n++;
                data.add(getString(i, curLen) + " " + nextInt(1, MAXCOST));
                len.add(curLen);
                totalLen -= curLen;
            }
        }
        if (leftLen != 0) {
            n++;
        }
        data.set(0, n + " " + queries);
        if (queries > SMALLQ) {
            leftQ = queries / 2;
            queries -= leftQ;
        }
        if (leftLen != 0) {
            String s = getString(0, leftLen);
            data.add(s + " " + nextInt(1, MAXCOST));
            for (int i = 0; i < leftQ; i++) {
                data.add("? " + n + " " + 1);
            }
        }
        int left = queries;
        while (left > 0) {
            if (nextInt(0, 2) == 0 || left < 3) {
                int pos = nextInt(1, n - 1);
                int minLen = nextInt(1, len.get(pos - 1));
                if (nextInt(0, 10) == 0) {
                    minLen = len.get(pos - 1) + 1;
                }
                data.add("? " + pos + " " + minLen);
                left--;
            } else {
                int pos = nextInt(1, n);
                int delta = nextInt(-MAXCOST, MAXCOST);
                data.add("! " + pos + " " + delta);
                data.add("? " + pos + " " + pos);
                data.add("? " + pos + " " + 1);
                left -= 3;
            }
        }
        print();
    }

    public void genGrey(int queries, int totalLen, int maxLen) throws IOException {
        StringBuilder cur = new StringBuilder();
        cur.append('a');
        char last = 'a';
        data.add("");
        data.add(cur.toString() + " " + nextInt(1, MAXCOST));
        int n = 1;
        totalLen--;
        ArrayList<Integer> len = new ArrayList<Integer>();
        len.add(1);
        while (true) {
            last++;
            String now = cur.toString();
            cur.append(last);
            cur.append(now);
            if (totalLen >= cur.toString().length() && cur.toString().length() <= maxLen) {
                n++;
                totalLen -= cur.toString().length();
                len.add(cur.toString().length());
                data.add(cur + " " + nextInt(1, MAXCOST));
            } else {
                break;
            }
        }
        data.set(0, n + " " + queries);
        int left = queries;
        while (left > 0) {
            if (nextInt(0, 2) == 0 || left < 3) {
                int pos = nextInt(1, n);
                int minLen = nextInt(1, len.get(pos - 1));
                if (nextInt(0, 10) == 0) {
                    minLen = len.get(pos - 1) + 1;
                }
                data.add("? " + pos + " " + minLen);
                left--;
            } else {
                int pos = nextInt(1, n);
                int delta = nextInt(-MAXCOST, MAXCOST);
                data.add("! " + pos + " " + delta);
                data.add("? " + pos + " " + pos);
                data.add("? " + n + " " + 1);
                left -= 3;
            }
        }
        print();
    }

    public void genLetters(int numberOfLetters, int queries, int totalLen, int singleMaxLen, boolean noChange) throws IOException {
        int offset = nextInt(0, 26 - numberOfLetters - 1);
        int oneLetter = totalLen / numberOfLetters;
        int maxC = Math.min(singleMaxLen, (int) Math.sqrt((double) oneLetter * 2)) - 1;
        int n = numberOfLetters * maxC;
        data.add(n + " " + queries);
        for (int i = offset; i < offset + numberOfLetters; i++) {
            char c = (char) ('a' + i);
            StringBuilder cur = new StringBuilder();
            for (int j = 1; j <= maxC; j++) {
                cur.append(c);
                data.add(cur.toString() + " " + nextInt(1, MAXCOST));
            }
        }
        int left = queries;
        if (noChange) {
            while (left > 0) {
                int charNum = nextInt(0, numberOfLetters - 1);
                data.add("? " + (maxC + maxC * charNum) + " " + 1);
                left--;
            }
        } else {
            int leftQ = 0;
            if (queries == MAXQ) {
                left = queries - 9 * (int) 1e5;
            }
            if (queries == MEDQ) {
                left = queries - 9 * (MEDQ / 10);
            }
            leftQ = queries - left;
            while (left > 0) {
                int charNum = nextInt(0, numberOfLetters - 1);
                if (nextInt(0, 2) == 0 || left < 3) {
                    int pos = nextInt(1, maxC);
                    int minLen = nextInt(1, pos);
                    if (nextInt(0, 10) == 0) {
                        minLen = pos + 1;
                    }
                    data.add("? " + (pos + maxC * charNum) + " " + minLen);
                    left--;
                } else {
                    int pos = nextInt(1, maxC);
                    int delta = nextInt(-MAXCOST, MAXCOST);
                    data.add("! " + (pos + maxC * charNum) + " " + delta);
                    data.add("? " + (pos + maxC * charNum) + " " + pos);
                    data.add("? " + (maxC * (charNum + 1)) + " " + 1);
                    left -= 3;
                }
            }
            for (int i = 0; i < leftQ; i++) {
                data.add("? " + maxC + " " + 1);

            }

        }
        print();
    }


    public void genSample1() throws IOException {
        data.add("2 4");
        data.add("margarita 20");
        data.add("marga 10");
        data.add("? 1 5");
        data.add("? 1 6");
        data.add("? 2 5");
        data.add("? 2 6");
        print();
    }

    public void genSample2() throws IOException {
        data.add("2 2");
        data.add("supreme 20");
        data.add("supremesuper 30");
        data.add("! 2 20");
        data.add("? 2 2");
        print();
    }

    public static void main(String[] args) {
        new TestGen().run();
    }
}













