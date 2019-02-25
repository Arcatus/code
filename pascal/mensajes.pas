program Mensajes;

var
     fin, fout : text;
     mencod : string; // EL MENSAJE CODIFICADO
     mendecod : string; // EL MENSAJE DECODIFICADO
     // ESTE ARREGLO SE UTILIZA PARA GUARDAR EN DONDE SE ABREN
     // LOS PARENTESIS
     Parentesis : array [1..5000] of integer;
     Parejas : array [1..10000] of integer;
     SP : integer;

     i, j, Dir : integer;


procedure Push(v : integer);
begin
     Parentesis[SP]:=v;
     Inc(SP);
end;

function Pop : integer;
begin
     Dec(SP);
     Pop:=Parentesis[SP];
end;

begin
	// LEE EL MENSAJE DE ENTRADA
     readln(mencod);

     SP:=1;

     // RECORRE EL ARCHIVO PARA BUSCAR LAS PAREJAS DE PARENTESIS
     for i:=1 to Length(MenCod) do begin
          if MenCod[i] = '(' then begin
          	// ABRE PARENTESIS, ASI QUE LO METE EN LA PILA
          	Push(i);
          end
          else if MenCod[i] = ')' then begin
          	// CIERRA EL PARENTESIS, LO SACA DE LA PILA, Y PONE LA PAREJA
               j:=Pop;
               Parejas[i]:=j;
               Parejas[j]:=i;
          end;
     end;

     Dir:=1; // DE ARRANQUE HAY QUE INICIAR AVANZANDO HACIA ADELANTE

     // RECORRE EL MENSAJE EN EL ORDEN ADECUADO PARA LA DECODIFICACION
     i:=1;
     MenDecod:='';
     while i <= Length(MenCod) do begin
     	// SI ES PARENTESIS, VE A LA PAREJA Y CAMBIA DE DIRECCION
          if (MenCod[i] = '(') or (MenCod[i] = ')') then begin
               i:=Parejas[i];
               if Dir = 1 then
                    Dir:=0
               else
               	Dir:=1;
          end
          else begin
          	MenDecod:=MenDecod + MenCod[i];
          end;

          // AVANZA EL CURSOR DE ACUERDO CON LA DIRECCION
          If Dir = 1 then
               Inc(i)
          else
          	Dec(i);
     end;

     // ESCRIBE LA SALIDA
     writeln(mendecod);
end.
