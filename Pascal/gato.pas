program gato;

var
     fin, fout : text;
     Tablero : array [1..100,1..100] of smallint;
     x, y : integer;

     i, j : integer;

     L : integer; // TAMANIO DEL TABLERO
     N : integer; // NUMERO DE TIRADAS
     b, C : Char;


     Tiradas : array [1..100,1..2] of byte;
     NTiradas : integer;


function BuscaVertical(x,y : integer) : boolean;
var
     res : boolean;
     cuantos : integer;
     i : integer;
begin
     res:=false;
     cuantos:=0;

     i:=y-1;
     while (i >= 1) and (Tablero[x,i] = 1) and (cuantos < 4) do begin
          Inc(cuantos);
          Dec(i);
     end;

     i:=y+1;
     while (i <= L) and (Tablero[x,i] = 1) and (cuantos < 4) do begin
          Inc(Cuantos);
          Inc(i);
     end;

     if Cuantos >= 4 then begin
     	res:=true;
     end;

     result:=res;
end;

function BuscaHorizontal(x,y : integer) : boolean;
var
     res : boolean;
     cuantos : integer;
     i : integer;
begin
     res:=false;
     cuantos:=0;

     i:=x-1;
     while (i >= 1) and (Tablero[i,y] = 1) and (cuantos < 4) do begin
          Inc(cuantos);
          Dec(i);
     end;

     i:=x+1;
     while (i <= L) and (Tablero[i,y] = 1) and (cuantos < 4) do begin
          Inc(Cuantos);
          Inc(i);
     end;

     if Cuantos >= 4 then begin
     	res:=true;
     end;

     result:=res;
end;

function BuscaDiagonalPos(x,y : integer) : boolean;
var
     res : boolean;
     cuantos : integer;
     i, j : integer;
begin
     res:=false;
     cuantos:=0;

     i:=y-1; j:=x+1;
     while (i >= 1) and (j <= L) and (Tablero[j,i] = 1) and (cuantos < 4) do begin
          Inc(cuantos);
          Dec(i);
          Inc(j);
     end;

     i:=y+1; j:=x-1;
     while (i <= L) and (j >= 1) and (Tablero[j,i] = 1) and (cuantos < 4) do begin
          Inc(Cuantos);
          Inc(i);
          Dec(j);
     end;

     if Cuantos >= 4 then begin
     	res:=true;
     end;

     result:=res;
end;

function BuscaDiagonalNeg(x,y : integer) : boolean;
var
     res : boolean;
     cuantos : integer;
     i, j : integer;
begin
     res:=false;
     cuantos:=0;

     i:=y-1; j:=x-1;
     while (i >= 1) and (j >= 1) and (Tablero[j,i] = 1) and (cuantos < 4) do begin
          Inc(cuantos);
          Dec(i);
          Dec(j);
     end;

     i:=y+1; j:=x+1;
     while (i <= L) and (j <= L) and (Tablero[j,i] = 1) and (cuantos < 4) do begin
          Inc(Cuantos);
          Inc(i);
          Inc(j);
     end;

     if Cuantos >= 4 then begin
     	res:=true;
     end;

     result:=res;
end;

procedure InsertaTirada(x,y : integer);
begin
     Tiradas[NTiradas,1]:=x;
     Tiradas[NTiradas,2]:=y;
     Inc(NTiradas);
end;

begin

     // LEE LA ENTRADA
     Assign(fin,'GATO.ENT');
     Reset(fin);
     Readln(fin,L);

     // INICIALIZA EL TABLERO A CEROS
     for i:=1 to L do
          for j:=1 to L do
          	Tablero[i,j]:=0;

     Readln(fin,N);
     for i:=1 to N do begin
          readln(fin,x,y,b,c);

          if c = 'O' then
               Tablero[x,y]:=1
          else
          	Tablero[x,y]:=2;

     end;
     Close(fin);

     NTiradas:=1;
     // BUSCA LAS TIRADAS GANADORAS
     for i:=1 to L do begin
          for j:=1 to L do begin
               // SI LA CASILLA ESTA VACIA
               if Tablero[i,j] = 0 then begin
                    //BUSCA EN TODAS LAS DIRECCIONES
                    if BuscaVertical(i,j) then begin
                    	InsertaTirada(i,j);
                    end
                    else if BuscaHorizontal(i,j) then begin
                    	Insertatirada(i,j);
                    end
                    else if BuscaDiagonalPos(i,j) then begin
                    	InsertaTirada(i,j);
                    end
                    else if BuscaDiagonalNeg(i,j) then begin
                    	InsertaTirada(i,j);
                    end;
               end;
          end;
     end;


     // ESCRIBE LA SALIDA
     Assign(fout,'GATO.SAL');
     Rewrite(fout);
     for i:=1 to Pred(NTiradas) do begin
     	writeln(fout,Tiradas[i,1],' ',Tiradas[i,2]);
     end;
     Close(fout);
end.