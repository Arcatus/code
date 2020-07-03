import java.io.*; 
import java.time.*; 
import java.time.DayOfWeek;
import java.util.Scanner; 
  
class Ddd { 
    public static void main(String[] args) 
    {        
		Scanner reader = new Scanner(System.in);

		int day = reader.nextInt();
		int month = reader.nextInt();
		int year = reader.nextInt();

		reader.close();

		try {
			LocalDate localDate = LocalDate.of(year, month, day); 
	
			DayOfWeek dayOfWeek = DayOfWeek.from(localDate);
			
			String[] names = new String[]{"","LUNES","MARTES","MIERCOLES","JUEVES","VIERNES","SABADO","DOMINGO"};
	  
			int val = dayOfWeek.getValue();
	
			System.out.println(names[val]);
		} catch( Exception e ) {
			System.out.println("SABADO");
		}
    } 
} 