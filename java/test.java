
import java.io.*;

import java.text.*;

class test
{
	public static void main ( String args[] ) throws IOException
	{
	    BufferedReader input 
	    	= new BufferedReader ( new InputStreamReader ( System.in ) );

	    String inputString = input.readLine();

    	double n = Double.parseDouble ( inputString );

    	DecimalFormat formater = new DecimalFormat("#.##");

	    System.out.println ("Double is " + formater.format(n) );
	}
}