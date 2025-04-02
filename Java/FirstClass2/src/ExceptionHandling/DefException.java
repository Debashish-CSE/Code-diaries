package ExceptionHandling;

import java.lang.Exception;
import java.util.Scanner;

class NoMatchException extends Exception{
	NoMatchException(String message){
		super(message);
	}
}

public class DefException {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		String s1 = "Bangladesh";
		String s2 = scan.next();
		try{
			if(s2.equals(s1))
				System.out.println("Match");
			else
				throw new NoMatchException("Not Match");
			}
		catch(NoMatchException e){
				System.out.println(e.getMessage());
			}
		finally{
				System.out.println("Finally Block");
			}
		scan.close();
	}
	
}
