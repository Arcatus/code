
def k():
    acti=(lambda x, y: x+''+y)
    return acti

def main():
    a = lambda x=0, y=1, z=2: x+y+z
    print( a(1,1) )

    fun = k()
    msg = fun('a','b')
    print( msg )

if __name__ == "__main__":
    main()