# Descripción 

Dada una secuencia de enteros **N**, encuentra el valor del subarreglo máximo, un subarreglo se define como un arreglo tal que sus intervalos cumplen: $ \[ a,b \]$ con $ x  
\space \leq \space a,\space b \leq y $, siempre respetando $ a \leq b $ con $x,y$ los limites del arreglo original, considerando esto un elemento puede ser visto como un subarreglo, por ejemplo para la secuencia de números $ [a_0,a_1,a_2] $ los intervalos de sus subarreglos serían $ [0,0], [0,1],[0,2]$,$[1,1],[1,2],[2,2]$ tu trabajo sera calcular el máximo $  \sum_{i=a}^\{b} arreglo[i] $.

# Entrada

Un número n seguido de n enteros, $a_0, a_1,...,a_{n-1}$.

# Salida

La suma más grande posible generada por los elementos de algún subarreglo.

# Ejemplo

||input
3
1 -2 3
||output
3
||description
El máximo subarreglo es $[2,2]$.
||input
6
4 -2 5 -1 5 -6
||output
11
||description
El máximo subarreglo es $[0,4]$.
||end

# Límites

* $ 1 \leq n \leq 10^3  $
* $ -100 \leq a_i \leq 100$