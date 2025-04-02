package MyProject;

//Polymorphism -> method overriding/overloading

class TestDemo{
	//overloading
	void test(){
		System.out.println("No parameters");
	}
	void test(int a, double b){
		System.out.println("a=" +a + " b="+b);
	}
}

public class polymorphism {
	public static void main(String args[]){
		 TestDemo my1 = new TestDemo();
		 my1.test();
		 my1.test(6, 8.5);
	}
}
