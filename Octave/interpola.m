% Implementaci�n del m�todo de interpolaci�n de Newton para encontrar una 
% curva de ajuste, para un conjunto de datos discretos dados inicialmente en 
% forma de pares de valores (xi,yi). Debe proporcionar  como argumento el 
% conjunto de valores en dos vectores: X (el conjunto de valores xi) y Y (el
% conjunto de valores yi).
function f = interpola(X,Y)
DimDatos = size(X); % Determinamos el número de puntos dados inicialmente
n = DimDatos(2);
% Para poder generar el polinomio de interpolación debemos determinar primero
% el conjunto de coeficientes bi (b1, b2, ... , bn), para n puntos. Cada bi se
% calcula usando diferencias divididas finitas, aquí calculadas por la función
% DifDiv(). Observe que b1 depende de los valores x0, x1, y0 y y1; b2 depende 
% de los valores x0, x1, x2, y0, y1 y y2; b3 depende de los valores x0, x1, x2,
% x3, y0, y1, y2 y y3; y así sucesivamente. Los conjuntos necesarios  para cada 
% bi se generan en los vectores Xact y Yact a partir de los vectores originales 
% X y Y.
for i = 2:n
    for j = 1:i
        Xact(j) = X(j);
        Yact(j) = Y(j);
    end    
    b(i) = DifDiv(Xact,Yact);
end

% Construimos ahora el polinomio agregando miembros de forma iterativa, 
% dependiendo del número de puntos dados inicialmente. El polinomio debe 
% generarse en forma de una cadena de texto para poder utilizar la función 
% ezplot; por ello utilizamos la convesrsión de números a cadenas de texto
% usando la función num2str.
y = num2str(Y(1));  % Comenzamos con b0 = y0 (Aquí corresponde a Y(1))
for i = 1:n-1 % ciclo para generar cada miembro del polinomio (a partir del segundo)
    factor = ['(x-',num2str(X(1)),')']; % factor es inicialmente (x-x0)
    for j = 2:i % ciclo para añadir más elementos a factor: (x-x0)*(x-x1)*(x-x2)*...
        factor = [factor,'*(x-',num2str(X(j)),')'];
    end
    y = [y,'+(',num2str(b(i+1)),')*',factor]; % Generamos el polinomio completo
end    

% Graficamos finalmente el polinomio generado y desplegamos el resultado 
% obtenido
% Para poder graficar en un intervalo adecuado, debemos primero determinar
% el mínimo y máximo valores del conjunto de valores xi:
xmin = min(X);  % Determinamos cual es el mínimo valor de los xi
xmax = max(X);  % Determinamos cual es el máximo valor de los xi
scatter (X,Y,'r','filled'); % Graficamos los puntos dados inicialmente
hold on;
ezplot (y,[xmin-1,xmax+1]); % Graficamos el polinomio de ajuste
f=inline(y); % Asignamos el resultado final y desplegamos a pantalla.

%------------------------------------------------------------------------------
% Función recursiva que genera diferecnias divididas finitas (DDF) para un 
% conjunto de valores xi, yi proporcionados en los vectores de parámetro X y Y
function R = DifDiv(X,Y)
DimV = size(X);
n = DimV(2);

if n == 2 % Si tenemos solo dos datos, la DDF se obtiene directamente
    R = (Y(2) - Y(1)) / (X(2) - X(1));
else % Si tenemos más de dos datos, la DDF se construye en base a otras DDFs
    for i = 1:n-1
        XM(i) = X(i+1);
        YM(i) = Y(i+1);
        Xm(i) = X(i);
        Ym(i) = Y(i);
    end   
    R = (DifDiv(XM,YM) - DifDiv(Xm,Ym)) / (X(n) - X(1));
end


