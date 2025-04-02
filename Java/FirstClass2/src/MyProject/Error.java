package MyProject;

//import java.lang.Exception;

public class Error {
	public static void main(String args[]){
		int a[] = {7,9,45,63,10};
		int b = 7;
		
		try{
			for(int i=0; i<7; i++){
				int x = a[i]/(b-7);
				
				System.out.print(x+" ");
			}
		}
		/*if(b==7){
			throw new ArithmeticException();
		}
		else{
			for(int i=0; i<7; i++){
				int x = a[i]/(b-7);
				
				System.out.print(x+" ");
			}
		}*/
		
		catch(ArithmeticException e){
			System.out.println("Division by Zero");
			//System.out.println(e.getMessage());
			
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Array Index Error");
		}
		
		finally{
			System.out.println("This block is always executed");
		}
	}
}
