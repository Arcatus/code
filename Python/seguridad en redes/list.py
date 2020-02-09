
def main():
    a = [1,2,3]
    b = {'aa':1,'bb':2,'cc':[ 'x','y','z' ]}

    print( *a )
    print (a) 
    print (type(a))
    print ( b['cc'][1] ) 
    print (type(b))

if __name__ == "__main__":
    main()