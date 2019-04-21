
import java.io.*;
import java.util.*;
import java.lang.*;

class Main
{
	public static void main ( String args[] )
	{
		Scanner reader = new Scanner(System.in);

		int day = reader.nextInt();
		int month = reader.nextInt();
		int year = reader.nextInt();

		String[] names = new String[]
		{"","DOMINGO","LUNES","MARTES","MIERCOLES","JUEVES","VIERNES","SABADO"};

		
		Calendar calendar = new GregorianCalendar(year,month-1,day);
		calendar.set(Calendar.ERA, GregorianCalendar.BC);
		System.out.println( names[calendar.get(Calendar.DAY_OF_WEEK)] );
		
	}	
}