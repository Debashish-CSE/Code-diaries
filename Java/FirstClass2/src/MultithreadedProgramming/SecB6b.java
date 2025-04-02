package MultithreadedProgramming;

class MyThread extends Thread{
	MyThread(){
		System.out.println("MyThread");
	}
	public void run(){
		for(int i=0; i<4; i++){
			System.out.println(" running");
			try{sleep(1000);}
			catch(InterruptedException e){}
		}
	}
	public void run(String s){
		System.out.print(s + " is running again");
	}
}

public class SecB6b {
	public static void main(String[] args) {
		Thread t = new MyThread(){
			public void run(){
				System.out.println(" are you running?");
			}
		};
		((MyThread)t).run("MyThread");
		t.start();
	}

}
