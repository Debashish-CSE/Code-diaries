package MultithreadedProgramming;

class At extends Thread {
	public void run() {
		System.out.println("threadA started");
		for (int i = 1; i <= 4; i++) {
			System.out.println("\tFrom Thread A : i=" + i);
		}
		System.out.println("Exit from A");
	}
}

class Bt extends Thread {
	public void run() {
		System.out.println("threadB started");
		for (int i = 1; i <= 4; i++) {
			System.out.println("\tFrom Thread B : i=" + i);
		}
		System.out.println("Exit from B");
	}
}

class Ct extends Thread {
	public void run() {
		System.out.println("threadC started");
		for (int i = 1; i <= 4; i++) {
			System.out.println("\tFrom Thread C : i=" + i);
		}
		System.out.println("Exit from C");
	}
}

public class Priority {
	public static void main(String[] args) {
		At threadA = new At();
		Bt threadB = new Bt();
		Ct threadC = new Ct();
		
		//set priority
		threadA.setPriority(Thread.MIN_PRIORITY);        //MIN_PRIORITY = 1
		threadB.setPriority(threadA.getPriority() + 1);  //getPriority() = 5(default)
 		threadC.setPriority(Thread.MAX_PRIORITY);        //MAX_PRIORITY = 10
		
 		System.out.println("Start Thread A");
 		threadA.start();
 		System.out.println("Start Thread B");
 		threadB.start();
 		System.out.println("Start Thread C");
 		threadC.start();
 		System.out.println("End of main Thread "); 
	}

}
