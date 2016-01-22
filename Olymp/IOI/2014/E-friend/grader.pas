program grader;

uses friend;

type
findSampleFunction = function (n: Longint; confidence: array of Longint; host: array of Longint; protocol: array of Longint): Longint; cdecl;

{$L graderlib.o}
{$IFDEF MSWINDOWS}
{$linklib msvcrt}
{$ELSE}
{$linklib c}
{$ENDIF}

procedure _main(findSample : findSampleFunction); cdecl; external;

begin
    _main(@findSample);
end.
