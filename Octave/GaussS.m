function R=GaussS(A,B,Es)
 format rat;
 [F,C]=size(A); % Determinamos el tamaño de la matriz A
 Ea=100;
 X=[0;0]; % Para almacenar las aproximaciones actuales
 Xant=[0;0]; % Para almacenar las aproximaciones anteriores
 Eaprox=[0;0]; % Para almacenar los errores aproximados de cada incógnita
 n=0; % Para contabilizar el número de iteraciones
 for i=1:F % Ciclo para incializar los vectores de datos
  X(i)=0;
  Xant(i)=0;
  Eaprox(i)=100;
 endfor
 do % Para realizar proceso iterativo de cálculo
  for i=1:F % Permite generar cada ecuación iterátiva para Xi
   numerador=0;
   for j=1:C % Permite crear la sumatoria en el numerador de cada ecuación iterativa
    if (i~=j)
     numerador=numerador-A(i,j)*X(j);
    endif
   endfor
   X(i)=(B(i)-numerador)/A(i,i)
   if n>0 
    if X(i)==0 && Xant(i)==0
     Eaprox(i)=0;
    else  
     Eaprox(i)=abs(((X(i)-Xant(i))/X(i))*100);
    endif
   endif 
  endfor
  Xant=X;
  Ea=norm(Eaprox);
  n++;
 until(Ea<Es); 
 n
 R=X
  