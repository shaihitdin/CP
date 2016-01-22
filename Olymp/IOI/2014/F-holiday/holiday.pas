unit holiday;

interface

function findMaxAttraction(n, start, d: longint; attraction: array of longint): int64; cdecl;

implementation

    function findMaxAttraction(n, start, d: longint; attraction: array of longint): int64; cdecl;

    begin
	FindMaxAttraction := 0;
    end;
end.
