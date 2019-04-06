program saltos_50;

var
   m, n, a, d, f, c, x, y, saltos : Int64;

begin
     readln(m,n);
     readln(a,d);
     readln(f,c);

     x:=c;
     y:=f;
     saltos:=0;
     repeat
           x:=x + d;
           if x > n then x:=x - n;

           y:=y + a;
           if y > m then y:=y - m;

           Inc(saltos);
     until (x = c) and (y = f);
     write(saltos);
end.
