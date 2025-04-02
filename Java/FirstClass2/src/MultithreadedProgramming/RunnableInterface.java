package MultithreadedProgramming;

class X implements Runnable{ // Step 1
	public void run(){ // Step 2
		for (int i=1;i<=10;i++){
			System.out.println("\tThreadX:"+i);
		}
	System.out.println("End of ThreadX");
	}
}


public class RunnableInterface {
	public static void main(String[] args) {
		X runnable=new X();
		Thread threadX=new Thread(runnable); // Step 3
		//Thread threadY=new Thread(new X());
		threadX.start(); // Step 4
		System.out.println("End of main Thread");
	}
}
