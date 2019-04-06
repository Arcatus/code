program antenas_h2;

var
   m, n, l, a, x, y, i, j : integer;
   antenasColocadas : integer;
   nuevasAntenas : array [1..2,1..10000] of integer;
   mapa : array [0..100,0..100] of boolean;

procedure ponAntena(x, y : integer);
var
   i, j : integer;
begin
     for i:=x - (l div 2) to x + (l div 2) do begin
         if (i < 0) or (i >= n) then continue; // SI SE SALE DEL MAPA NO TE MOLESTES EN SEGUIR

         for j:=y - (l div 2) to y + (l div 2) do begin
             if (j < 0) or (j >= m) then continue;

             mapa[i,j]:=true;
         end;
     end;
end;

begin
     for i:=0 to 100 do
         for j:=0 to 100 do
             mapa[i,j]:=false;

     readln(m,n,l,a);
     for i:=1 to a do begin
         readln(y,x);
         ponAntena(x,y);
     end;

     // RESUELVE
     for j:=0 to m-1 do begin
         for i:=0 to n-1 do begin
             if not(mapa[i,j]) then begin
                ponAntena(i + (l div 2), j + (l div 2));
                Inc(antenasColocadas);
                nuevasAntenas[1,antenasColocadas]:=j + (l div 2);
                nuevasAntenas[2,antenasColocadas]:=i + (l div 2);
             end;
         end;
     end;

     writeln(antenasColocadas);
     for i:=1 to antenasColocadas do
         writeln(nuevasAntenas[1,i],' ',nuevasAntenas[2,i]);
end.
