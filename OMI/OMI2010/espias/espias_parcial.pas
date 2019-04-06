program espias_50;

var
   n, i, j, maximo, total : integer;
   espias : array [1..1000000] of integer;
   leidos : array [1..1000000] of boolean;

begin
     readln(n);
     for i:=1 to n do
         readln(espias[i]);

     maximo:=0;
     for i:=1 to n do begin // DESDE CADA UNO DE LOS ESPIAS REVISA SU CAMINO DE MENTES
         for j:=1 to n do leidos[j]:=false; // MARCA A TODOS COMO NO VISITADOS
         total:=0; // TOTAL DE INICIAR EN EL ESPIA i
         j:=i;
         while not(leidos[j]) do begin // AVANZA EN EL CAMINO MIENTRAS NO LLEGUES A UNO VISITADO
               leidos[j]:=true; // MARCALO COMO VISITADO
               Inc(total); // INCREMENTA EL NUMERO DE MENTES LEIDAS
               j:=espias[j]; // AVANZA AL SIGUIENTE ESPIA
         end;

         if total > maximo then maximo:=total; // SI ENCONTRASTE ALGO MEJOR AL MAXIMO QUE LLEVABAS, ACTUALIZA EL MAXIMO

     end;

     write(maximo);
end.
