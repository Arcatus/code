% Proposito: Calculo de ecuaciones lineales por el metodo de Gauss con
%            pivoteo parcial escalonado
% Funciones:    -gaussp (funcion principal)
%               -IntercambioF (funcion declarada localmente)
% Comentarios: El codigo fuente esta comentado, lo unico a resaltar es el uso
%              de la funcion 'cputime', cuya funcion en este modulo es la obtencion del
%              tiempo transcurrido durante la ejecucion del programa {tiempo_inicial -
%              tiempo_final.}
function R = gaussp(A,B)
t = cputime; %Obtenemos los segundos actuales
format rat; %Pedimos al programa que use fracciones en vez de numeros {con esto el error sera menor}
if ((nargin < 2) | (nargin > 2)) %si el numero de argumentos no es el pedido...
    fprintf('El numero de argumentos difiere del necesario.\n');
    A = input('Por favor escriba a continuacion la matriz de coeficientes A:\n');
    B = input('A continuacion escriba la matriz de terminos independientes B:\n');
end    
[F,C] = size(A); %Obtenemos el orden de la matriz -> F = numero de filas C = numero de columnas
[FB,CB] = size(B); %Obtenemos el orden de la matriz -> FB = numero de filas CB = numero de columnas
if ((F ~= C) | (CB > 1) | (FB ~= F))
    fprintf('Error: El orden de la matriz A y/o la matriz B, no es/son el/los correcto/s. \n Por favor reviselo');
    return; %Mostramos un mensaje y salimos
end
S = [0;0]; %La matriz S
AB = [A,B]; %La matriz resultado de concatenar A y B
for i = 1:F %Para cada fila...
    M = abs(A(i,1)); %Tomamos el primer elemento
    for j = 2:C %Para cada elemento de la fila... {el primero ya lo hemos tomado}
        if abs(A(i,j)) > M %Si el elemento actual es mayor que el maximo registrado...
            M = abs(A(i,j)); %Este pasa a ser el maximo
        end
    end
    S(i) = M; %El elemento de la fila i de S es el maximo registrado
    if S(i) == 0 %Si algun elemento de S es 0...
        fprintf('No existe solucion unica para el sistema. Finalizado SIN exito'); %No existe solucion unica
        return; %Paramos el proceso de creacion de la matriz S y salimos
    end
end
for i = 1:(C-1)% Para cada columna...
    for q = i:(F)%Ordenamos la columna t. q. a(1,i)/S(1)>a(2,i)/S(2)>...>a(q,i)/S(q)
        MaxF = q; %La fila con el maximo {asignamos la primera fila al inicio}
        Max = abs(AB(q,i))/S(q); %El maximo {asignamos el primero al inicio}
        for j = (q+1):F %Recorremos la columna en busca de otro posible maximo
            if AB(j,i)/S(j) > Max %Si el elemento actual es mayor que el maximo registrado..
                Max = abs(AB(j,i))/S(j); %Asignamos el valor de este maximo
                MaxF = j; %Asignamos la nueva fila maxima a su variable
            end
        end
        if (MaxF ~= q) %Si el maximo no se encuantra en la fila de inicio
            AB = IntercambioF(AB,MaxF,q); %Intercambiamos la fila de AB para q coincida
            S = IntercambioF(S,MaxF,q); % Tambien se debe cambiar en S, puesto q el orden ha cambiado
        end
    end %Columna ya ordenada
    if (AB(i,i) == 0) %El elemento de la diagonal NO puede ser 0, si es cero no existe solucion unica
        fprintf('No existe solucion unica para el sistema. Finalizado SIN exito'); %No existe solucion unica
        return;% Salimos
    end
    for j = (i+1):F %Modificamos las filas para hacer 0's
        m = (AB(j,i)/AB(i,i)); %m sera el multiplicando, es necesario declararlo
        %antes de intercambiar las filas porque el valor de los elementos
        %de las mismas variara cuando hagamos 0's, y por consiguiente el
        %valor de m
        for q = 1:(C+1) %Para cada elemento de la fila...
             AB(j,q) = AB(j,q) - m*AB(i,q); %Realizamos el cambio
        end
    end
end
for i = 1:F
    if (AB(i,i) == 0) %Ningun elemento de la diagonal puede ser 0, si es cero no existe solucion unica
        fprintf('No existe solucion unica para el sistema. Finalizado SIN exito'); %No existe solucion unica
        return; %Salimos
    end
end
X = [0;0]; %matriz con los resultados
X(F) = AB(F,F+1)/AB(F,F); %Asignamos el ultimo elemento
for i = (F-1):-1:1 %Y vamos calculando los demas
    Sum = 0; %inicializacion de la variable Sum {para calcular el sumatorio}
    for j = (i+1):F %bucle para el sumatorio, para cada fila...
       Sum = Sum + AB(i,j)*X(j); %Calculamos el resultado actual y lo a�adimos al conocido
    end
    X(i) = (AB(i,F+1)-Sum)/AB(i,i); %Obtenemos X(i)
end
fprintf('Resolucion del sistema concluida en: %d segundos. El resultado: \n',(cputime - t));
R = X; %El resultado es X


%A continuacion se encuentra la funcion IntercambioF, cuya funcion es
%intercambiar filas de una matriz. En principio esta operacion se puede
%realizar de dos formas, la expuesta y sabiendo q A(n,:) devuelve la fila
%completa n de la matriz A. Yo he escogido la primera forma porque es un
%metodo mas grafico y menos abstracto.

function Z = IntercambioF(V,f1,f2) %Funcion interna para intercambiar filas
[FV,CV] = size(V); %Obtenemos el numero de filas y columnas {F y C respectivamente}
CV1 = 0; %Aqui se almacena temporalmente un valor 
for n = 1:CV %Bucle para recorrer las columnas
    CV1 = V(f1,n); %CV1 = fila 1
    V(f1,n) = V(f2,n); %Asignamos a 
    V(f2,n) = CV1; %Asignamos a la fila n� f2 la fila CV1
end
Z = V; %el resultado es la nueva matriz V
