function z=secante()
f=input('Proporcione la funcion, f(x) = ','s');
funcion=inline(f);
ezplot(funcion);
Xn=input('Proporcione el valor inicial cercano a la raiz, Xn = ');
Xnm1=Xn-0.05;
%Es=input('Proporcione el valor de error de tolerancia, Es = ');
imax=input('Proporcione el numero maximo de iteraciones, imax = ');
n=input('Proporcione el numero de digitos significativos de precision del resultado, n = ')
i=0;
Es=0.5*10.^(2-n);
Ea=100;
do
 fxn=feval(funcion,Xn);
 fxnm1=feval(funcion,Xnm1);
 XnM1=Xn-fxn*((Xn-Xnm1)/(fxn-fxnm1));
 if i > 1
   Ea=((XnM1-Xn)/XnM1)*100;
 endif
 Xnm1=Xn;
 Xn=XnM1;
 i++;
until(abs(Ea)<Es || i==imax);
if (i==imax)
 disp('No se encontro una solución!!');
else
 z=XnM1;
 format long,z
 fxnM1=feval(funcion,XnM1)
 printf('El valor de la raiz es, %f\n',XnM1);
 printf('El valor de la funcion en la raiz es: %f\n', fxnM1);
 printf('El valor del error aproximado es %f\n', Ea);
 printf('El numero de iteraciones es: %d\n', i);
endif
 
 
 
