package MyProject;

class ClassV{
	static int var = 9; //class variable
	int var1 = 5;  //instance variable
	int methodV(int a){
		int temp = a; //local variable
		return temp;
	}
}

public class variable {
	public static void main(String[] args){
		System.out.println("Class variable = "+ ClassV.var);
		ClassV objV = new ClassV();
		//System.out.println(objV instanceof ClassV);
		System.out.println("Instance variable = "+ objV.var1);
		System.out.println("local variable = "+ objV.methodV(6));
	}
}
