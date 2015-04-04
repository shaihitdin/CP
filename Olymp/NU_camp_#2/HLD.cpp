
<!-- saved from url=(0057)http://acm.math.spbu.ru/~sk1/kz/src/2014-03-30/a.cpp.html -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
   

  <!-- link rel="stylesheet" href="http://acm.math.spbu.ru/~sk1/colorer1/xcode.css">
  <script src="http://acm.math.spbu.ru/~sk1/colorer1/highlight.pack.js"></script>
  <script>hljs.initHighlightingOnLoad();</script -->

  <link rel="stylesheet" title="Default" href="http://acm.math.spbu.ru/~sk1/colorer/my.css">
  <script src="./HLD_files/highlight.js"></script>
  <script src="./HLD_files/cpp.js"></script><style type="text/css"></style>
  <script>hljs.initHighlightingOnLoad();</script>
</head>

<body>

<pre><code class=" cpp">
<span class="comment">/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.03.30
 */</span>

<span class="preprocessor">#include &lt;cstdio&gt;</span>
<span class="preprocessor">#include &lt;cassert&gt;</span>
<span class="preprocessor">#include &lt;algorithm&gt;</span>
<span class="preprocessor">#include &lt;vector&gt;</span>

<span class="keyword">using</span> <span class="keyword">namespace</span> <span class="built_in">std</span>;

<span class="preprocessor">#define forn(i, n) for (int i = 0; i &lt; (int)(n); i++)</span>
<span class="preprocessor">#define pb push_back</span>

<span class="keyword">typedef</span> <span class="stl_container"><span class="built_in">vector</span> &lt;<span class="keyword">int</span>&gt;</span> vi;

<span class="keyword">const</span> <span class="keyword">int</span> N = <span class="number">1</span>e5;

<span class="keyword">int</span> qn, n, parent[N], dep[N], size[N], w[N];
<span class="keyword">int</span> T, t_in[N], t_out[N];
vi c[N];

<span class="keyword">struct</span> SegTree {
  <span class="keyword">int</span> top, n;
  vi ind, t;

  <span class="keyword">void</span> build() {
    n = ind.size();
    t.resize(<span class="number">2</span> * n);
  }

  <span class="keyword">void</span> change( <span class="keyword">int</span> i ) {
    t[n + i] = w[ind[i]];
    <span class="keyword">for</span> (i += n, i /= <span class="number">2</span>; i &gt; <span class="number">0</span>; i /= <span class="number">2</span>)
      t[i] = max(t[<span class="number">2</span> * i], t[<span class="number">2</span> * i + <span class="number">1</span>]);
  }

  <span class="keyword">int</span> get( <span class="keyword">int</span> l, <span class="keyword">int</span> r ) {
    <span class="keyword">int</span> ma = <span class="number">0</span>;
    <span class="keyword">for</span> (l += n, r += n; l &lt;= r; l &gt;&gt;= <span class="number">1</span>, r &gt;&gt;= <span class="number">1</span>) {
      <span class="keyword">if</span> (l % <span class="number">2</span> == <span class="number">1</span>) ma = max(ma, t[l++]);
      <span class="keyword">if</span> (r % <span class="number">2</span> == <span class="number">0</span>) ma = max(ma, t[r--]);
    }
    <span class="keyword">return</span> ma;
  }
};

<span class="keyword">int</span> tn = <span class="number">0</span>;
SegTree t[N], *ti[N];

<span class="keyword">void</span> go( <span class="keyword">int</span> v, <span class="keyword">int</span> pr = -<span class="number">1</span>, <span class="keyword">int</span> d = <span class="number">0</span> ) {
  parent[v] = pr, dep[v] = d, size[v] = <span class="number">1</span>;
  t_in[v] = T++;
  forn(i, c[v].size())
    <span class="keyword">if</span> (c[v][i] != pr)
      go(c[v][i], v, d + <span class="number">1</span>), size[v] += size[c[v][i]];
  t_out[v] = T++;
}

<span class="keyword">void</span> build( <span class="keyword">int</span> v, <span class="keyword">int</span> pr = -<span class="number">1</span>, <span class="keyword">int</span> tree = -<span class="number">1</span> ) {
  <span class="keyword">int</span> x, ma = <span class="number">0</span>, ma_i = -<span class="number">1</span>;
  <span class="keyword">if</span> (tree == -<span class="number">1</span>)
    t[tn].top = v, tree = tn++;
  ti[v] = &amp;t[tree];
  t[tree].ind.pb(v);
  forn(i, c[v].size())
    <span class="keyword">if</span> ((x = c[v][i]) != pr &amp;&amp; size[x] &gt; ma)
      ma = size[x], ma_i = i;
  forn(i, c[v].size())
    <span class="keyword">if</span> ((x = c[v][i]) != pr)
      build(x, v, i == ma_i ? tree : -<span class="number">1</span>);
}

<span class="keyword">int</span> ind( <span class="keyword">int</span> v ) {
  <span class="keyword">return</span> dep[v] - dep[ti[v]-&gt;top];
}

<span class="keyword">void</span> change( <span class="keyword">int</span> v ) {
  ti[v]-&gt;change(ind(v));
}

<span class="keyword">inline</span> <span class="keyword">bool</span> is_ancestor( <span class="keyword">int</span> a, <span class="keyword">int</span> b ) { 
  <span class="keyword">return</span> t_in[a] &lt;= t_in[b] &amp;&amp; t_out[b] &lt;= t_out[a];
}

<span class="keyword">int</span> get( <span class="keyword">int</span> a, <span class="keyword">int</span> b ) {
  <span class="keyword">int</span> ma = <span class="number">0</span>;
  forn(_, <span class="number">2</span>) {
    <span class="keyword">while</span> (!is_ancestor(ti[a]-&gt;top, b)) { <span class="comment">// a -&gt; ti[a]-&gt;top</span>
      ma = max(ma, ti[a]-&gt;get(<span class="number">0</span>, ind(a)));
      a = parent[ti[a]-&gt;top];
    }  
    swap(a, b);
  }
  <span class="keyword">return</span> max(ma, ti[a]-&gt;get(min(ind(a), ind(b)), max(ind(a), ind(b))));
}

<span class="keyword">int</span> main() {
  <span class="preprocessor">#define NAME "caves"</span>
  assert(freopen(NAME <span class="string">".in"</span>, <span class="string">"r"</span>, stdin));
  assert(freopen(NAME <span class="string">".out"</span>, <span class="string">"w"</span>, stdout));

  scanf(<span class="string">"%d"</span>, &amp;n);
  forn(i, n - <span class="number">1</span>) {
    <span class="keyword">int</span> a, b;
    scanf(<span class="string">"%d%d"</span>, &amp;a, &amp;b), a--, b--;
    c[a].pb(b), c[b].pb(a);
  }
  go(<span class="number">0</span>); <span class="comment">// root = 0</span>
  build(<span class="number">0</span>);
  forn(i, tn)
    t[i].build();

  scanf(<span class="string">"%d"</span>, &amp;qn);
  <span class="keyword">while</span> (qn--) {
    <span class="keyword">char</span> com;
    <span class="keyword">int</span> x, y;
    scanf(<span class="string">" %c%d%d"</span>, &amp;com, &amp;x, &amp;y);
    <span class="keyword">if</span> (com == <span class="string">'I'</span>) { <span class="comment">// w[x-1] += y</span>
      w[--x] += y;
      change(x);
    } <span class="keyword">else</span> {
      printf(<span class="string">"%d\n"</span>, get(x - <span class="number">1</span>, y - <span class="number">1</span>));
    }
  }
  <span class="keyword">return</span> <span class="number">0</span>;
}

</code></pre>




<font style="visibility:hidden">
</font></body></html>