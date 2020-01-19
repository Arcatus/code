# -*- coding: utf-8 -*-
__author__ = 'Jair Paredes, Arturo Herrera, Arturo Sánchez'
__copyright__ = 'Copyright 2019, UniNet'
__version__ = '2.0.0'
__email__ = 'jparedes@reduno.com.mx, arturohv@reduno.com.mx,' \
                                                    'arturosm@reduno.com.mx'
__status__ = 'Production'

from utilidades.xpath import Xpath
import datetime
import time
import re

def probe_tarjeta(connection_obj, proveedor, tiempo_espera, comando , 
                                                                    validacion):
        """
        Valida que las tarjeta se encuentre activa despues de un reinicio

        Args:
            connection_obj: Conexion del equipo.
            tiempo_espera: Tiempo de espera a que levante la tarjeta
            comando: Comando para verificar tarjeta
            validacion: Validacion de tarjeta

        Returns:
            Respuesta, Indica si la tarjeta esta activa en el equipo.
        """
        
        start = datetime.datetime.now()
        end = start + datetime.timedelta(minutes= tiempo_espera)
        probe_ok = False
        val_xpath = Xpath()
        
        while datetime.datetime.now() < end:
            try:
                output_xml = connection_obj.execute_command(comando, 'xml')

                res_xpath = val_xpath.get_data(output_xml,
                                        validacion, proveedor, comando)
                
                if res_xpath == True:
                    probe_ok = True
                    break
                else:
                    time.sleep(2)

            except Exception as err:
                raise Exception(err)

        return probe_ok

#def verify_ports(connection_obj, proveedor, comando, validacion):
def verify_ports(proveedor, lista):

    """
    Método utilizado para realizar pruebas hasta que las tarjeta se
    encuentre activa

    Args:
        connection_obj: Conexion del equipo.
        tiempo_espera: Tiempo de espera a que levante la tarjeta
        comando: Comando para verificar tarjeta
        validacion: Validacion de tarjeta

    Returns:
        Respuesta, Indica si la tarjeta esta activa en el equipo.
    """

    print("verify_ports")
    interfaces = ""
    for each_element in lista:
        if re.search("et", each_element):
            interfaces = interfaces + each_element + "%"
            interfaces = interfaces + "100g" + ","
        elif re.search("ge|xe|xle|fte", each_element):
            interfaces = interfaces + each_element + "%"
            interfaces = interfaces + "10g" + ","
    return interfaces

"""def get_interface_speed(self, ports): #, conexion, ports):

    ports_speed = ""
    for each_element in ports:

        if re.search("et", each_element):
            ports_speed = ports_speed + each_element + "%"
            ports_speed = ports_speed + "100g" + ","

        elif re.search("ge|xe|xle|fte", each_element):
            ports_speed = ports_speed + each_element + "%"
            ports_speed = ports_speed + "10g" + ","

    return ports_speed"""