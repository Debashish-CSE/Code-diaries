package MyProject;

class sample1{
	void methodA(){
		System.out.println("MethodA-s1");
	}
}

class sample2 extends sample1{
	//override
	void methodA(){
		System.out.println("MethodA-s2");
	}
	void methodB(){
		System.out.println("MethodB");
	}
}
public class Miscellaneous2 {
	public static void main(String[] args){
		sample1 objS2 = new sample2();
		objS2.methodA();
		//objS2.methodB(); methodB can't be accessed because sample1 is referenced when creating object of sample2
		
		sample2 objS22 = new sample2();
		objS22.methodA();
		objS22.methodB(); //here the class reference is sample2, that's why we can access methodB
	}
}
