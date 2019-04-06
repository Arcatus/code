program vueltas_50;

var
   tablero : array [1..1000,1..1000] of integer;
   m, n, v, i, j, t : integer;
   vuelta : char;

procedure vueltaVertical;
begin
     for j:=1 to m div 2 do begin
         for i:=1 to n do begin
             t:=tablero[i,j];
             tablero[i,j]:=tablero[i,m-j+1];
             tablero[i,m-j+1]:=t;
         end;
     end;
end;

procedure vueltaHorizontal;
begin
     for i:=1 to n div 2 do begin
         for j:=1 to m do begin
             t:=tablero[i,j];
             tablero[i,j]:=tablero[n-i+1,j];
             tablero[n-i+1,j]:=t;
         end;
     end;
end;

begin
     readln(m,n);
     for j:=1 to m do begin
         for i:=1 to n do
             read(tablero[i,j]);
         readln;
     end;

     readln(v);
     for i:=1 to v do begin
         readln(vuelta);
         if vuelta = 'V' then begin
            vueltaVertical;
         end
         else begin
              vueltaHorizontal;
         end;
     end;

     for j:=1 to m do begin
         for i:=1 to n do begin
             write(tablero[i,j],' ');
         end;
         writeln;
     end;

end.
