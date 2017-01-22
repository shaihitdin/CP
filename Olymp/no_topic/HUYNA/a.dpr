var sum_main, sum_aux, i, j : integer;
	a : array[1..5, 1..5] of integer;
function Edit : Integer;
begin
	
	for i := 1 to 5 do
		sum_main := sum_main + a[i, i];
	for i := 1 to 5 do
		sum_aux := sum_aux + a[i, 5 - i + 1];
	
	Result := sum_main + sum_aux;
end;

begin
	for i := 1 to 5 do
		for j := 1 to 5 do
			a[i][j] := 1 + random(10);
	writeln(Edit);
end.