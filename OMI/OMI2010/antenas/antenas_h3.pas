program antenas_h3;

var
   m, n, l, a, x, y, i, j, k : integer;
   antenasColocadas : integer;
   nuevasAntenas : array [1..2,1..10000] of integer;
   mapa : array [0..100,0..100] of boolean;

function ponAntena(x, y : integer; marca : boolean) : integer;
var
   i, j : integer;
   r : integer;
begin
     r:=0;
     for i:=x - (l div 2) to x + (l div 2) do begin
         if (i < 0) or (i >= n) then continue; // SI SE SALE DEL MAPA NO TE MOLESTES EN SEGUIR

         for j:=y - (l div 2) to y + (l div 2) do begin
             if (j < 0) or (j >= m) then continue;

             if not(mapa[i,j]) then r:=r + 1; // AUMENTA EL NUMERO DE CUADROS CUBIERTOS POR ESTA COLOCACION

             if marca then
                mapa[i,j]:=true;
         end;
     end;
     ponAntena:=r;
end;

function buscaMejorPosicionParaAntena(x, y : integer) : integer;
var
   i, r, maxI, max : integer;

begin
     max:=0;
     for i:=x - (l div 2) to x + (l div 2) do begin
         r:=ponAntena(i,y + (l div 2),false);
         if r >= max then begin
            max:=r;
            maxI:=i;
         end;
     end;

     ponAntena(maxI,y + (l div 2),true);
     buscaMejorPosicionParaAntena:=maxI;
end;

begin
     for i:=0 to 100 do
         for j:=0 to 100 do
             mapa[i,j]:=false;

     readln(m,n,l,a);
     for i:=1 to a do begin
         readln(y,x);
         ponAntena(x,y,true);
     end;

     // RESUELVE
     for j:=0 to m-1 do begin
         for i:=0 to n-1 do begin
             if not(mapa[i,j]) then begin
                k:=buscaMejorPosicionParaAntena(i, j);
                Inc(antenasColocadas);
                nuevasAntenas[1,antenasColocadas]:=j + (l div 2);
                nuevasAntenas[2,antenasColocadas]:=k;
             end;
         end;
     end;

     writeln(antenasColocadas);
     for i:=1 to antenasColocadas do
         writeln(nuevasAntenas[1,i],' ',nuevasAntenas[2,i]);
end.
