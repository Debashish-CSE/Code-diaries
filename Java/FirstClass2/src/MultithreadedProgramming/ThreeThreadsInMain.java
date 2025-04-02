package MultithreadedProgramming;

//Write a Java program which creates three threads in the main method.

class NewThread implements Runnable{
	String name;
	Thread t;
	NewThread(String Threadname){
		//synchronized(this){
			name = Threadname;
			t = new Thread(this, name);
			t.start();
		//}
	}
	
	public void run(){
		for(int i=1; i<=10; i++){
			System.out.print(name+ ": " +i+ "\n");
		}
		System.out.println("End of "+name);
		}
}

public class ThreeThreadsInMain {
	public static void main(String[] args){
		
		new NewThread("A1");
		new NewThread("A2");
		new NewThread("A3");
		System.out.println("End of main Thread:");
	}
}
