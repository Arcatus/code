# Descripción

Como proyecto de fin de semana te has propuesto simular un display de siete segmentos, solo que tú eres especial y no te gustan las rayitas así usaras algún otro caracter. Ve el ejemplo para que te quede más claro, como se dibujaran los números si el caracter dado fuera "#":

        ### # ### ### # # ### ### ### ### ### 
        # # #   #   # # # #   #     # # # # # 
        # # # ### ### ### ### ###   # ### ### 
        # # # #     #   #   # # #   # # #   # 
        ### # ### ###   # ### ###   # ### ###

# Entrada
Un entero n de a lo más 9 digitos, seguido de un caracter ascii. Los digitos estaran en el rango de 0-9.

# Salida

El número n dibujado únicamente con el caracter dado, cada dígito tendra un espacio de separación.

# Ejemplo

||input
12 #
||output
# ### 
#   # 
# ### 
# #   
# ### 

||input
76278 %
||output
%%% %%% %%% %%% %%% 
  % %     %   % % % 
  % %%% %%%   % %%% 
  % % % %     % % % 
  % %%% %%%   % %%% 
||end

# Límites
0 $\leq$ **n** $\leq$ 999999999