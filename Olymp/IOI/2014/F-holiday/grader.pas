program grader;

uses holiday;

type
findMaxAttractionFunction = function (n, start, d: longint; attraction: array of longint): int64; cdecl;

{$L graderlib.o}
{$IFDEF MSWINDOWS}
{$linklib msvcrt}
{$ELSE}
{$linklib c}
{$ENDIF}

procedure _main(findMaxAttraction : findMaxAttractionFunction); cdecl; external;

begin
    _main(@findMaxAttraction);
end.
