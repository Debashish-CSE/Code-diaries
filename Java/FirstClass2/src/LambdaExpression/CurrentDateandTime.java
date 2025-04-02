package LambdaExpression;

import javax.swing.Timer;
import java.util.Date;

public class CurrentDateandTime {

	public static void main(String[] args) {
		// Create a Timer that prints the current time every second
		Timer timer = new Timer(1000, event -> System.out.println("The time is: " + new Date()));
		timer.start();
	
		// Keep the program running for 10 seconds
		try {
			Thread.sleep(10000);  // Sleep for 10 seconds
		} 
		catch (InterruptedException e) {
			e.printStackTrace();
		}

    System.out.println("Program finished.");
}
}
