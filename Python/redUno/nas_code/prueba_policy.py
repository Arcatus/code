from jnpr.junos import Device
import jnpr.junos.exception
from jnpr.junos.utils.sw import SW
from jnpr.junos.utils.config import Config

configuracion_list = ['delete interfaces ge-1/3/1 unit 14 bandwidth','delete class-of-service interfaces ge-1/3/1  unit 14 output-traffic-control-profile']
configuracion = "\n".join(configuracion_list)
print(configuracion)
dev = Device(host='201.154.95.80',user='jcpelcas',password='IG76Cmr5')
dev.open()
with Config(dev, mode='exclusive') as cu:
    cu.load(configuracion)
    cu.commit_check()
    cu.commit(sync=True, ignore_warning=True)

    

    
   