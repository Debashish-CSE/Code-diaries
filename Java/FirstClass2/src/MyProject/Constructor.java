package MyProject;

class sample3{
	//there can be more than one constructor in the same class
	sample3(String A){
		System.out.println(A);
	}
	int x;
	sample3(int a){
		x = a;
	}
}

public class Constructor {
	public static void main(String[] args){
		sample3 objs4 = new sample3("Debashish");
		sample3 objs3 = new sample3(4);
		System.out.print("x: "+objs3.x);
	}
}
