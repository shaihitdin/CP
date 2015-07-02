{$APPTYPE CONSOLE}
uses
  SysUtils;
type tyu = ^nya;
  nya = record
  a : array['a'..'z'] of tyu;
  k : int64;
  end;
var
  i, j:integer;
  n, m, k, b : int64;
  root, pt : tyu;
  w : string;
  e : char;
  s : array[1..1000000] of string;
  q : array[1..1000000] of int64;

procedure add(u : integer);
var
  p : tyu;
  r : integer;
  o : char;
begin
  p := root;
  for r := 1 to (length(s[u]) + 1) do
    if r > length(s[u]) then
      p^.k := p^.k + q[i]
    else
      if p^.a[s[i][r]] <> nil then
        p := p^.a[s[i][r]]
      else
      begin
        new(p^.a[s[i][r]]);
        p := p^.a[s[i][r]];
        for o := 'a' to 'z' do
          p^.a[o] := nil;
        p^.k := 0;
      end;
end;

begin
  assign(input, 'pizza.in');
  reset(input);
  assign(output, 'pizza.out');
  rewrite(output);
  new(root);
  root^.k := 0;
  for e := 'a' to 'z' do
    root^.a[e] := nil;
  readln(n, m);
  for i := 1 to n do
  begin
    readln(w);
    s[i] := '';
    j := 1;
    while (w[j] <> ' ') do
    begin
      s[i] := s[i] + w[j];
      inc(j);
    end;
    q[i] := strtoint(copy(w, j + 1, length(w)));
    add(i);
  end;
  for i := 1 to m do
  begin
    readln(e, j, k);
    if e = '!' then
    begin
      pt := root;
      n := 1;
      while (n <= length(s[j])) do
      begin
        pt := pt^.a[s[j][n]];
        inc(n);
      end;
      pt^.k := pt^.k + k;
    end
    else
    begin
      n := 0;
      pt := root;
      b := 1;
      while (b <= length(s[j])) do
      begin
        pt := pt^.a[s[j][b]];
        if b >= k then
          n := n + pt^.k;
        inc(b);
      end;
      writeln(n);
    end;
  end;
end.
 
