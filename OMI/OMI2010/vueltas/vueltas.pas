program vueltas;

var
   tablero : array [1..1000,1..1000] of integer;
   m, n, v, i, j, t, vert, hor : integer;
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

     vert:=0; hor:=0;
     readln(v);
     for i:=1 to v do begin
         readln(vuelta);
         if vuelta = 'V' then begin
            Inc(vert);
         end
         else begin
              Inc(hor);
         end;
     end;

     // DADO QUE DAR DOS VUELTAS EN EL MISMO SENTIDO ES LO MISMO QUE NO HACER NINGUNA VUELTA
     // BASTA CON VER SI EL NUMERO DE VUELTAS VERTICAL U HORIZONTAL FUE IMPAR PARA SABER
     // SI ES NECESARIO APLICAR DICHA VUELTA.
     if vert mod 2 = 1 then vueltaVertical;
     if hor mod 2 = 1 then vueltaHorizontal;

     for j:=1 to m do begin
         for i:=1 to n do begin
             write(tablero[i,j],' ');
         end;
         writeln;
     end;

end.
