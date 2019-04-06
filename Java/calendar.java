
import java.io.*;

import java.util.*;

class calendar
{

	public static void main ( String args[] ) throws IOException
	{
		GregorianCalendar cal = new GregorianCalendar(110,8,9);

		System.out.println (cal.get(Calendar.DAY_OF_WEEK) == Calendar.MONDAY);
	}
	
}