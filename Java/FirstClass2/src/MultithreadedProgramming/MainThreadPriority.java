package MultithreadedProgramming;

//Write a java program to change the name and priority of main thread

public class MainThreadPriority {
	public static void main(String[] args){
		Thread t = Thread.currentThread();
		System.out.println("Current Thread: "+t);
		
		t.setName("CSE");
		System.out.println("After name changes: "+t);
		
		t.setPriority(t.getPriority()-2);
		System.out.println("After priority changes: "+t.getPriority());
		
		//priority cannot be less than 1, more than 10. then IllegalArgumentException arises
		try{
			t.setPriority(t.getPriority()-5);
			System.out.println("After priority changes: "+t.getPriority());
		}
		catch(IllegalArgumentException e){
			System.out.println("Illegal argument");
			
		
		}
	}
}
