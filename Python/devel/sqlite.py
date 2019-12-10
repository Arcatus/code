import sqlite3
from persona import Persona

conn = sqlite3.connect('persona.db')
#conn = sqlite3.connect(':memory:') lives in ram

c = conn.cursor()

# c.execute("""CREATE TABLE personas (
#             nombre text,
#             edad integer
#             )""")

# c.execute("INSERT INTO personas VALUES ('ana',11)")
# conn.commit()

# persona1 = Persona('juan', 18)
# persona2 = Persona('Abril', 23)

# print( persona1.imprimir() )
# print( persona2.imprimir() )

# c.execute(f"INSERT INTO personas VALUES ('{persona1.nombre}',{persona1.edad})")
# conn.commit()

#c.execute("SELECT * FROM personas")

#Prepared statements

# c.execute("INSERT INTO personas VALUES (:nombre,:edad)",
# {'nombre':persona2.nombre,'edad':persona2.edad})
# conn.commit()

# c.execute("SELECT * FROM personas WHERE edad=?", (23,))
# c.execute("SELECT * FROM personas WHERE edad=:edad", {'edad':23})

# c.fetchall()
# c.fetchmany(5)
# print(c.fetchall())

def insert_persona(p):
    with conn:
        c.execute("INSERT INTO personas VALUES (:nombre,:edad)",{'nombre':p.nombre,'edad':p.edad})

def get_all():
    c.execute("SELECT * FROM personas")
    return c.fetchall()

def get_persona_by_name(name):
    c.execute("SELECT * FROM personas WHERE nombre=:nombre", {'nombre':name})
    return c.fetchall()

def update_edad_by_name(name, edad):
    with conn:
        c.execute("""UPDATE personas 
            SET edad=:edad WHERE nombre=:nombre""",{'nombre':name, 'edad':edad})

def delete_by_name(name):
    with conn:
        c.execute("DELETE from personas WHERE nombre=:nombre",{'nombre':name})

print( get_all() )

# print( get_persona_by_name('Abril') )

# p = Persona('Ulises', 38)

# insert_persona(p)

# print( get_all() )

# update_edad_by_name('Abril',24)

delete_by_name('carlos')

print( get_all() )