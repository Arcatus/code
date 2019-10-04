% Programa para cálculo de raices con el método de bisección
function z=biseccion()
 disp('Calculo de raices con biseccion');
 f=input('Proporcione la ecuacion no lineal: ','s');
 funcion=inline(f);
 ezplot(funcion);
 grid on;
 xl=input('Proporcione el valor inferior del intervalo, xl = ');
 xu=input('Proporcionel el valor superior del intervalo, xu = ');
 Es=input('Proporcione el valor de error de tolerancia, Es = ');
 fxl=feval(funcion,xl);
 fxu=feval(funcion,xu);
 if fxl*fxu>0
  disp('Error. La función debe cambiar de signo en el intervalo!!');
 else
  xr=0;
  ni=0;
  do 
    xrant=xr; 
    xr=(xl+xu)/2;
    fxr=feval(funcion,xr)
    if fxl*fxr<0
     xu=xr;
    elseif fxl*fxr>0
      xl=xr;
    endif
    Ea=((xr-xrant)/xr)*100;
    ni++;
  until(abs(Ea)<Es);
 endif 
  z=double(xr);
  format long, z
  printf('Se alcanzo el resultado final en %d iteraciones',ni); 
 