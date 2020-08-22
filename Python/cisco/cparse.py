from ciscoconfparse import CiscoConfParse

rutaResp = "/home/carlosrm/Documents/Red Uno/Overlaps/070820/"
hostname = "dsl-bcs-lapazbcs-9"
readFile = "/home/carlosrm/Documents/Red Uno/Overlaps/DirMezDUp/InputFilesD/Equipos_dsl_all.txt"
try:
    cnti = 0
    cntio = 0
    cntxr = 0
    cntj = 0
    cntu = 0
    for router in open(readFile):
        router = router.rstrip("\n")
        print router,
        routerSP = router#nombre del equipo sin ruta
        router = rutaResp + router
        existe = 1
        try:
            cisco = CiscoConfParse(router)
        except:
            existe = 0
        if existe == 1:
            iversion = cisco.find_lines('^version\s.+[0-9]$')
            ioversion = cisco.find_lines('^! Version:\s')
            xrversion = cisco.find_lines('^!! IOS XR\s')
            jversion = cisco.find_lines('^version\s.+;$')
        if iversion:
            cnti += 1
            print " iversion " + str(iversion)
        elif ioversion:
            cntio += 1
            print " ioversion " + str(ioversion)
        elif xrversion:
            cntxr += 1
            print " xrversion " + str(xrversion)
        elif jversion:
            cntj += 1
            print " jversion " + str(jversion)
        else :
            cntu += 1
            print " " + "unknown"
    print "i ", cnti, " io ", cntio, " xr ", cntxr, " j ", cntj, " u ", cntu, "\n"

except:
    print "fallo al cargar la configuracion"