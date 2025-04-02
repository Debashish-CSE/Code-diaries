package MyProject;

class sample{
	static int mA = 0;
	void methodA(int mA){
		this.mA = mA;
	}
}

public class Miscellaneous {
	public static void main(String[] args){
		sample objS = new sample();
		objS.methodA(8);
		System.out.println("mA = " + sample.mA);
	}
}
