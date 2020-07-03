import calendar 
  
def findDay(day, month, year): 
    dayNumber = calendar.weekday(year, month, day) 
    days =["LUNES", "MARTES", "MIERCOLES", "JUEVES", 
                         "VIERNES", "SABADO", "DOMINGO"] 
    return (days[dayNumber]) 

date = input()
day, month, year = ( int(i) for i in date.split(' '))
#print(f"{day}, {month}, {year}")
#day = 1
month = 1
#year = 1970

print( findDay(day, month, year) )
        
