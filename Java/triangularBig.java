
import java.io.*;
import java.text.*;
import java.math.*;

class Main
{
	public static void main ( String args[] ) throws IOException
	{
	    BufferedReader input 
	    	= new BufferedReader ( new InputStreamReader ( System.in ) );

	    String inputString = input.readLine();

    	BigInteger n = new BigInteger( inputString );

  		BigInteger np = n.add( new BigInteger("1") );

  		np = np.multiply( n );

  		np = np.divide( new BigInteger("2") );

	    System.out.println ( np.toString() );
	}
}