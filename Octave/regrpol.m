function f=regrpol()
% Aplica el método de regresión polinomial 
% Se le solicitará un vector de valores X y un vector de valores
% Y, que corresponden a los puntos generados experimentalmente.

% Solicitamos el vector de valores X
X = input('Proporcione el vector de valores X [x1,x2,...,xn]: ');
% Solicitamos el vector de valores Y
Y = input('Proporcione el vector de valores Y [y1,y2,...,yn]: ');
% Solicitamos el grado del polinomio
grado = input('Proporcione el grado del polinomio de regresion a construir: ');

% Determinamos cuantos puntos tenemos, calculando el tamaño del vector X
n = size(X);
% Obtenemos las sumatorias de valores que corresponden a los coeficientes  
% y términos independientes del SEL que debe resolverse para obtener el valor 
% de a0, a1 y a2, etc. del polinomio de ajuste.
A=[0,0;0,0];
B=[0;0]
for i=1:grado+1
  for j=1:grado+1
    if i==1 && j==1
     A(i,j)=n(2);
    else
     A(i,j)=sum(X.^(i+j-2));
    endif
  end
  B(i)=sum(X.^(i-1).*Y);  
 end

R=gaussp(A,B)

% Construimos el polinomio de regresión como cadena de texto, agregando
% términos mediante una estructura iterativa.
y = [num2str(R(1)),'+',num2str(R(2)),'*x'];
if grado>1
 for i = 2:grado
    y = [y,'+',num2str(R(i+1)),'*x^',num2str(i)];
 end   
endif
f=inline(y);

% Graficamos tanto el polinomio, como el conjunto de puntos
% proporcionados mediante los vectores X y Y
Xmax = max(X)+5;
Xmin = min(X)-5;
Ymax = max(Y)+5;
Ymin = min(Y)-5;
scatter(X,Y);	% Grafica el conjunto de puntos
hold on;
ezplot(y,[Xmin Xmax Ymin Ymax]);	% Grafica el polinomio de ajuste