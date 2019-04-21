program hotcakes;

{$APPTYPE CONSOLE}

CONST

{$DEFINE DEBUG}
{$UNDEF DEBUG}

     {$IFDEF DEBUG}
     MAXNIVELES = 3;
     {$ELSE}
     MAXNIVELES = 20;
     {$ENDIF}
     MAXHOTCAKES = 1000001;
     DERECHA = 0;
     IZQUIERDA = 1;

type
    PNodo = ^TNodo;
    TNodo = record
      hizq, hder, habajo : PNodo;
      cizq, cder : integer;
      valor, nivel : integer;
    end;

var
   inicios, finales, camino, siguientes : array [0..MAXNIVELES] of PNodo;
   hijosTotales : array [0..MAXNIVELES] of integer;
   indiceVolteo : integer;
   clist, cant : PNodo;
   i, n, v : integer;

function actualizaCuentaDerecha(nodo : PNodo; numero : integer) : integer;
var
   cur : PNodo;
   c : integer;
begin
     cur:=nodo;
     while cur.habajo <> nil do cur:=cur.habajo;
     c:=0;
     while cur.hder.valor <> numero do begin
           Inc(c);
           cur:=cur.hder;
     end;
     nodo.cder:=c;
     result:=c;
end;

procedure agrega(numero, nivel : integer; hijo : PNodo);
var
   nodo : PNodo;
begin
     if nivel > MAXNIVELES then exit;
     New(nodo);
     nodo.valor:=numero;
     nodo.nivel:=nivel;
     nodo.cder:=0;
     nodo.hizq:=finales[nivel].hizq;
     nodo.hder:=finales[nivel];
     nodo.hizq.hder:=nodo;
     nodo.habajo:=hijo;
     finales[nivel].hizq:=nodo;

     nodo.cizq:=actualizaCuentaDerecha(nodo.hizq,numero);
     if random(3) = 0 then agrega(numero,nivel + 1,nodo);
end;

procedure imprimeNivel(unNivel :  integer);
var
   c, ca : PNodo;
begin
     {$IFDEF DEBUG}
     c:=inicios[unNivel].hder;
     ca:=inicios[unNivel];
     while c <> nil do begin
           if c.hizq = ca then begin
              write('(',c.cizq,',',c.valor,'-',c.nivel,',',c.cder,') ');
              ca:=c;
              c:=c.hder;
           end
           else begin
                write('(',c.cder,',',c.valor,'+',c.nivel,',',c.cizq,') ');
                ca:=c;
                c:=c.hizq;
           end;
     end;
     writeln;
     {$ENDIF}
end;

procedure hazVolteo(indice : integer);
var
   i, j, cuenta : integer;
   curr, anterior : PNodo;
   nodoFin, nodoSig : PNodo;
   hijosNodoFin, hijosRestantes : integer;
begin
     cuenta:=0;
     anterior:=nil;
     curr:=inicios[MAXNIVELES];

     for i:=0 to MAXNIVELES do begin
         hijosTotales[i]:=0;
     end;

     for i:=MAXNIVELES downto 0 do begin
         while cuenta < indice do begin
               if anterior = curr.hder then begin // avanza por la izquierda
                  if cuenta + 1 + curr.cizq < indice then begin
                     cuenta:=cuenta + 1 + curr.cizq;
                     anterior:=curr;
                     curr:=curr.hizq;
                     for j:=i + 1 to MAXNIVELES do hijosTotales[j]:=hijosTotales[j] + curr.cizq + 1;
                  end
                  else begin
                       camino[i]:=curr;
                       siguientes[i]:=curr.hizq;
                       if i <> 0 then begin
                          curr:=curr.habajo;
                          anterior:=curr.hder;
                       end;
                       break;
                  end;
               end
               else begin // avanza por la derecha
                    if cuenta + 1 + curr.cder < indice then begin
                       cuenta:=cuenta + 1 + curr.cder;
                       anterior:=curr;
                       curr:=curr.hder;
                       for j:=i + 1 to MAXNIVELES do hijosTotales[j]:=hijosTotales[j] + curr.cder + 1;
                    end
                    else begin
                         camino[i]:=curr;
                         siguientes[i]:=curr.hder;
                         if i <> 0 then begin
                            curr:=curr.habajo;
                            anterior:=curr.hizq;
                         end;
                         break;
                    end;
               end;
         end;
     end;

     for i:=0 to MAXNIVELES do begin
         nodoFin:=finales[i].hizq;
         if camino[i].hder = siguientes[i] then begin // avanza por la izquierda

            finales[i].hizq:=siguientes[i];
            if siguientes[i].hizq = camino[i] then siguientes[i].hizq:=finales[i]
            else siguientes[i].hder:=finales[i];

            camino[i].hder:=nodoFin;
            if nodoFin.hizq = finales[i] then begin
               nodoFin.hizq:=camino[i];
               hijosNodoFin:=nodoFin.cizq;
            end
            else begin
                 nodoFin.hder:=camino[i];
                 hijosNodoFin:=nodoFin.cder;
            end;

            hijosRestantes:=camino[i].cder - hijosTotales[i];
            camino[i].cder:=hijosTotales[i] + hijosNodoFin;

            if nodoFin.hizq = camino[i] then nodoFin.cizq:=camino[i].cder
            else nodoFin.cder:=camino[i].cder;

            if siguientes[i].hizq = finales[i] then siguientes[i].cizq:=hijosRestantes
            else siguientes[i].cder:=hijosRestantes;

         end
         else begin // avanza por la derecha

            finales[i].hizq:=camino[i].hizq;
            if camino[i].hizq.hizq = camino[i] then camino[i].hizq.hizq:=finales[i]
            else camino[i].hizq.hder:=finales[i];

            camino[i].hizq:=nodoFin;
            if nodoFin.hizq = finales[i] then begin
               nodoFin.hizq:=camino[i];
               hijosNodoFin:=nodoFin.cizq;
            end
            else begin
                 nodoFin.hder:=camino[i];
                 hijosNodoFin:=nodoFin.cder;
            end;

            hijosRestantes:=camino[i].cizq - hijosTotales[i];
            camino[i].cizq:=hijosTotales[i] + hijosNodoFin;

            if nodoFin.hizq = camino[i] then nodoFin.cizq:=camino[i].cizq
            else nodoFin.cder:=camino[i].cizq;

            if siguientes[i].hizq = finales[i] then siguientes[i].cizq:=hijosRestantes
            else siguientes[i].cder:=hijosRestantes;

         end;

         imprimeNivel(i);
     end;
end;

begin
     for i:=0 to MAXNIVELES do begin
         New(inicios[i]);
         inicios[i].nivel:=i;
         New(finales[i]);
         finales[i].nivel:=i;
     end;

     for i:=0 to MAXNIVELES do begin
         inicios[i].hizq:=nil;
         inicios[i].hder:=finales[i];
         finales[i].hizq:=inicios[i];
         finales[i].hder:=nil;
         inicios[i].cizq:=0;
         inicios[i].cder:=0;
         finales[i].cizq:=0;
         finales[i].cder:=0;
         inicios[i].valor:=-1;
         finales[i].valor:=MAXHOTCAKES;
         if i <> 0 then begin
            inicios[i].habajo:=inicios[i-1];
            finales[i].habajo:=finales[i-1];
         end
         else begin
              inicios[i].habajo:=nil;
              finales[i].habajo:=nil;
         end;
     end;

     randomize;
     readln(n,v);
     for i:=1 to n do begin
         agrega(i,0,nil);
     end;

     for i:=0 to MAXNIVELES do begin
         if finales[i].hizq = inicios[i] then inicios[i].cder:=n
         else finales[i].hizq.cder:=n - finales[i].hizq.valor;
     end;

     for i:=MAXNIVELES downto 0 do begin
         imprimeNivel(i);
     end;


     for i:=1 to v do begin
         readln(indiceVolteo);
         hazVolteo(indiceVolteo);
     end;

     clist:=inicios[0].hder;
     cant:=inicios[0];
     while clist <> finales[0] do begin
           write(clist.valor,' ');
           if clist.hizq = cant then begin
              cant:=clist;
              clist:=clist.hder;
           end
           else begin
                cant:=clist;
                clist:=clist.hizq;
           end;
     end;
     {$IFDEF DEBUG}
     readln;
     readln;
     readln;
     {$ENDIF}
end.

