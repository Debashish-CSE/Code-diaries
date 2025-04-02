package ExceptionHandling;

public class MethodThrowsException {
	static void play() throws Exception{
		System.out.println("before");
		throw new IllegalAccessException("demo");
		//System.out.println("after");
	}
	public static void main(String args[]){
		try{
		play();
		}
		catch(Exception e){
		System.out.println("caught me: " +e);
		}
	}
		
}
