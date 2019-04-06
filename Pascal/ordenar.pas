program ordenar;

var
     fin, fout : text;
     numeros : array [0..9] of integer;
     n, i, j : integer;

begin
	// INICIALIZA A CERO EL NUMERO DE DIGITOS DE CADA TIPO
     for i:=0 to 9 do begin
     	numeros[i]:=0;
     end;

     // LEE LA ENTRADA
     Assign(fin,'ORDENAR.ENT');
     Reset(fin);
     readln(fin,n);
     for i:=1 to n do begin
          read(fin,j);
          // PARA CADA DIGITO LEIDO INCREMENTA EL NUMERO DE DIGITOS DE ESE TIPO
          Inc(Numeros[j]);
     end;
     Close(fin);

     Assign(fout,'ORDENAR.SAL');
     Rewrite(fout);
     for i:=0 to 9 do begin
     	// ESCRIBE TODOS LOS DIGITOS DE CADA TIPO, DESDE EL 0 HASTA EL 9
          for j:=1 to numeros[i] do begin
          	write(fout,i,' ');
          end;
     end;
     writeln(fout);
     Close(fout);
end.
