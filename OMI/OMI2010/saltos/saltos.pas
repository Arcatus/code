program saltos_100;


var
   m, n, a, d, repHor, repVer, saltos : Int64;

function mcd(v, w : Int64) : Int64;
var
   q, r : Int64;
begin
     q:=v div w;
     r:=v - (w * q);
     if r = 0 then
        result:=w
     else
         result:=mcd(w,r);
end;

begin
     readln(m,n);
     readln(a,d);

     repHor:=n div mcd(n,d);
     repVer:=m div mcd(m,a);

     if repVer > repHor then
        saltos:=repVer * repHor div mcd(repVer,repHor)
     else
         saltos:=repVer * repHor div mcd(repHor,repVer);

     write(saltos);
end.
