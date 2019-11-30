% Programa para cálculo de raices con el método de falsa posición
function z=falsapos()
 disp('Calculo de raices con falsa posicion');
 f=input('Proporcione la ecuacion no lineal y = ','s');
 funcion=inline(f);
 ezplot(funcion);
 grid on;
 xl=input('Proporcione el valor inferior del intervalo, xl = ');
 xu=input('Proporcione el valor superior del intervalo, xu = ');
 %Es=input('Proporcione el valor de error de tolerancia, Es = ');
 n=input('Proporcione el numero de digitos significativos de precision del resultado, n = ')
 fxl=feval(funcion,xl);
 fxu=feval(funcion,xu);
 if fxl*fxu>0
  disp('Error. La función debe cambiar de signo en el intervalo!!');
 else
  xr=0;
  ni=0;
  Es = 0.5*10.^(2-n);
  Ea = 100;
  do 
    xrant=xr; 
    xr=xu-(fxu*(xl-xu)/(fxl-fxu));
    fxr=feval(funcion,xr)
    if fxl*fxr<0
     xu=xr;
     fxu=fxr;
    elseif fxl*fxr>0
      xl=xr;
      fxl=fxr;
    endif
    if ni > 1
      Ea=((xr-xrant)/xr)*100;
    endif
    ni++;
  until(abs(Ea)<Es);
 endif 
  z=double(xr);
  format long, z
  %printf('Se alcanzo el resultado final en %d iteraciones',ni); 
  printf('El valor de la raiz es, %f\n',xr);
  printf('El valor de la funcion en la raiz es: %f\n', fxr);
  printf('El valor del error aproximado es %f\n', Ea);
  printf('El numero de iteraciones es: %d\n', ni);
 