program antenas_h5;

var
   m, n, l, a, x, y, i, j, k, c : integer;

   antenasColocadasSol : integer;
   antenasColocadas : integer;
   nuevasAntenasSol : array [1..2,1..10000] of integer;
   nuevasAntenas : array [1..2,1..10000] of integer;

   mapa : array [0..100,0..100] of boolean;
   mapaOriginal : array [0..100,0..100] of boolean;

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

function buscaMejorPosicionParaAntena(x, y : integer; derecha : boolean) : integer;
var
   i, r, maxI, max : integer;

begin
     max:=0;
     for i:=x - (l div 2) to x + (l div 2) do begin
         r:=ponAntena(i,y + (l div 2),false);
         if (r > max) or ((r = max) and derecha) then begin
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

     // RESUELVE PONIENDO LA ANTENA HACIA LA DERECHA
     for i:=0 to n-1 do
         for j:=0 to m-1 do
             mapaOriginal[i,j]:=mapa[i,j];

     antenasColocadas:=0;
     for j:=0 to m-1 do begin
         for i:=0 to n-1 do begin
             if not(mapa[i,j]) then begin
                k:=buscaMejorPosicionParaAntena(i, j, true);
                Inc(antenasColocadas);
                nuevasAntenas[1,antenasColocadas]:=j + (l div 2);
                nuevasAntenas[2,antenasColocadas]:=k;
             end;
         end;
     end;

     // TOMA ESTA COMO PRIMERA MEJOR SOLUCION
     antenasColocadasSol:=antenasColocadas;
     for k:=1 to antenasColocadas do begin
         nuevasAntenasSol[1,k]:=nuevasAntenas[1,k];
         nuevasAntenasSol[2,k]:=nuevasAntenas[2,k];
     end;

     // RESUELVE AHORA PONIENDO LAS ANTENAS HACIA LA IZQUIERDA Y TOMA LA MEJOR
     for i:=0 to n-1 do
         for j:=0 to m-1 do
             mapa[i,j]:=mapaOriginal[i,j];

     antenasColocadas:=0;
     for j:=0 to m-1 do begin
         for i:=0 to n-1 do begin
             if not(mapa[i,j]) then begin
                k:=buscaMejorPosicionParaAntena(i, j, false);
                Inc(antenasColocadas);
                nuevasAntenas[1,antenasColocadas]:=j + (l div 2);
                nuevasAntenas[2,antenasColocadas]:=k;
             end;
         end;
     end;

     // SI ES MEJOR QUE LA ANTERIOR, ENTONCES TOMA LA NUEVA
     if antenasColocadas < antenasColocadasSol then begin
        antenasColocadasSol:=antenasColocadas;
        for k:=1 to antenasColocadas do begin
            nuevasAntenasSol[1,k]:=nuevasAntenas[1,k];
            nuevasAntenasSol[2,k]:=nuevasAntenas[2,k];
        end;
     end;

     // POR ULTIMO PRUEBA VARIAS DE MANERA ALEATORIA
     for c:=1810 to 2010 do begin
         randSeed:=c;

        // DECIDE LA POSICION DE ESA ANTENA DE MANERA ALEATORIA, CAMBIANDO LA SEMILLA DEL RANDOM PARA OBTENER SOLUCIONES DISTINTAS
         for i:=0 to n-1 do
             for j:=0 to m-1 do
                 mapa[i,j]:=mapaOriginal[i,j];

         antenasColocadas:=0;
         for j:=0 to m-1 do begin
             for i:=0 to n-1 do begin
                 if not(mapa[i,j]) then begin
                    k:=buscaMejorPosicionParaAntena(i, j, random(2) = 0);
                    Inc(antenasColocadas);
                    nuevasAntenas[1,antenasColocadas]:=j + (l div 2);
                    nuevasAntenas[2,antenasColocadas]:=k;
                 end;
             end;
         end;

         // SI ES MEJOR QUE LA ANTERIOR, ENTONCES TOMA LA NUEVA
         if antenasColocadas < antenasColocadasSol then begin
            antenasColocadasSol:=antenasColocadas;
            for k:=1 to antenasColocadas do begin
                nuevasAntenasSol[1,k]:=nuevasAntenas[1,k];
                nuevasAntenasSol[2,k]:=nuevasAntenas[2,k];
            end;
         end;

     end;

     writeln(antenasColocadasSol);
     for i:=1 to antenasColocadasSol do
         writeln(nuevasAntenasSol[1,i],' ',nuevasAntenasSol[2,i]);
end.
