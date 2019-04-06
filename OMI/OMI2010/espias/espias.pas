program espias_100;

var
   n, i, j, k, espiaActual, apuntadorPila, largociclo, maximo : integer;
   esCiclo : boolean;
   espias : array [1..1000000] of integer;
   leidos : array [1..1000000] of integer;
   leidosDesdeEspia : array [1..1000000] of integer;
   pila : array [1..1000001] of  integer;

begin
     readln(n);
     for i:=1 to n do begin
         readln(espias[i]);
         leidos[i]:=0;
         leidosDesdeEspia[i]:=0;
     end;

     maximo:=0;
     apuntadorPila:=1;
     j:=1; // VAMOS A UTILIZAR j PARA IR NUMERANDO LOS CICLOS Y NO CONFUNDIRNOS ENTRE EL CICLO QUE ESTAMOS BUSCANDO Y ANTERIORES
     // OBTEN LOS MAXIMOS EMPEZANDO DESDE TODOS LOS ESPIAS
     for i:=1 to n do begin
         if leidos[i] = 0 then begin // NO SE HA PASADO POR ESTE ESPIA NUNCA
            espiaActual:=i;
            while leidos[espiaActual] = 0 do begin // RECORRE DESDE ESTE ESPIA HASTA ENCONRAR SU CICLO O CHOCAR CON UN CICLO ENCONTRADO PREVIAMENTE
                  leidos[espiaActual]:=j;
                  pila[apuntadorPila]:=espiaActual;
                  Inc(apuntadorPila);
                  espiaActual:=espias[espiaActual];
            end;

            if leidos[espiaActual] = j then begin // ENCONTRAMOS UN CICLO, HAY QUE MEDIR LA LONGITUD
               largoCiclo:=0;
               for k:=apuntadorPila - 1 downto 1 do begin // BUSCA EL LARGO DEL CICLO
                   if pila[k] = espiaActual then
                      break
                   else
                       Inc(largoCiclo);
               end;
               // ACTUALIZA LOS MAXIMOS, TODOS LOS ELEMENTOS DEL CICLO DEBEN TENER EL MISMO VALOR
               esCiclo:=true;
               while apuntadorPila > 1 do begin
                     Dec(apuntadorPila);
                     if esCiclo then
                        leidosDesdeEspia[pila[apuntadorPila]]:=largoCiclo
                     else
                         leidosDesdeEspia[pila[apuntadorPila]]:=leidosDesdeEspia[espias[pila[apuntadorPila]]] + 1;

                     if pila[apuntadorPila] = espiaActual then esCiclo:=false;
               end;
            end
            else begin // SOMOS UNA RAMA, LLEGAMOS A UN CICLO O RAMA PREVIA, HAY QUE ACTUALIZAR LAS LONGITUDES
                 while apuntadorPila > 1 do begin
                       Dec(apuntadorPila);
                       leidosDesdeEspia[pila[apuntadorPila]]:=leidosDesdeEspia[espias[pila[apuntadorPila]]] + 1;
                 end;
            end;
         end;
         Inc(j);
     end;

     // BUSCA EL MAXIMO
     for i:=1 to n do
         if leidosDesdeEspia[i] > maximo then
            maximo:=leidosDesdeEspia[i];

     write(maximo);
end.
