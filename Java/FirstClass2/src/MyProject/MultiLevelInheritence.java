package MyProject;

// m = sqrt[(6*t*t)/{sqrt(t)+x}]

class ClassA1{
	double methodA1(double t){
		double A = 6*t*t;
		return A;
	}
}

class ClassB1 extends ClassA1{
	double methodB1(double x, double t){
		double partB = Math.sqrt(t) + x;
		double PartA = super.methodA1(t);
		double m =(PartA/partB);
		return m;
	}
}

class ClassC1 extends ClassB1{
	double methodC1(double x,double t){
		double temp = Math.sqrt(super.methodB1(x,t));
		return temp;
	}
}

public class MultiLevelInheritence{
	public static void main(String[] args){
		ClassC1 objC = new ClassC1();
		System.out.println("m= "+ objC.methodC1(2.0,8.5));
		
	}
}
