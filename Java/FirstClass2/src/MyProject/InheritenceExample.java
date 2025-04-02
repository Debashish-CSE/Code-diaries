package MyProject;

// m = sqrt[(6*t*t)/{sqrt(t)+x}]

class ClassA{
	double methodA(double t){
		double A = 6*t*t;
		return A;
	}
	public static void print(Object obj){
		System.out.println(obj);
	}
}

class ClassB extends ClassA{
	double methodB(double x, double t){
		double partB = Math.sqrt(t) + x;
		double PartA = super.methodA(t);
		double m = Math.sqrt(PartA/partB);
		return m;
	}
}

public class InheritenceExample{
	public static void main(String[] args){
		ClassB objB = new ClassB();
		System.out.println("m= "+ objB.methodB(2.0,8.5));
		
		
		return;
	}
}


