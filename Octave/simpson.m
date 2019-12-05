% Cálculo de integral definida con Reglas de Simpson
clear;
clc;
%Ingreso de datos
disp('Cálculo de integral definida')
disp('Por el Método de Reglas de Simpson')
fx=input('Proporcione la función f(x) = ','s');
ezplot(fx);
grid on;
a=input('Proporcione el límite inferior = ');
b=input('Proporcione el límite superior = ');
tol=input('Proporcione el error de tolerancia = ');

%Condiciones iniciales
err(1)=100;
ns=0;
exito=0;
i=0;

%Cálculo de la integral
while exito==0
    ns=ns+2;
    i++;
    h=(b-a)/ns
    x=a:h:b
    y=eval(fx)
    Iaprox(i)=h/3*(y(1)+y(ns+1)+4*sum(y(2:2:ns))+2*sum(y(3:2:ns-1)))
    resp=input('Enter para continuar...');

% Cálculo del error
    if i>1 
        err(i)=abs((Iaprox(i)-Iaprox(i-1))/Iaprox(i))*100;
        if err(i)<tol
            exito=1;
        end
    end
end

%Presentacion de resultados
n=2:2:ns;
fprintf('\n');
disp([' Segmentos'   '   Integral'  '  error'])
disp([n' Iaprox' err' ]);
fprintf('Se alcanzó la solucion con %g segmentos\n',ns);
fprintf('La integral aproximada es: %g\n',Iaprox(i));