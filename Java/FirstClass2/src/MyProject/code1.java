package MyProject;

//m = sqrt[(6*t*t)/{sqrt(t)+x}]

class Class1{
	double methodA(double x, double t){
		double m = Math.sqrt((6*t*t)/(Math.sqrt(t)+x));
		return m;
	}
}
public class code1{
	public static void main(String[] args){
		Class1 obj1 = new Class1();
		System.out.println("Value of m : " + obj1.methodA(2.5, 3.5));
	}

}
