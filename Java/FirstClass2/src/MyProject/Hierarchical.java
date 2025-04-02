package MyProject;

class root{
	double method1(double a){
		double t = Math.sqrt(a);
		return t;
	}
}

class class2 extends root{
	double method2(double x, double t){
		double div = (6*t*t)/(super.method1(t)+x);
		double m = super.method1(div);
		return m;
	}
}


public class Hierarchical{
	public static void main(String[] args){
		class2 obj2 = new class2();
		System.out.println("m = "+obj2.method2(2.0,8.5));
		
	}
}
