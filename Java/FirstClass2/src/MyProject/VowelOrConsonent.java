package MyProject;

import java.util.Scanner;

public class VowelOrConsonent {
	public static void main(String args[]) {
		System.out.print("Enter a character: ");
		Scanner scan = new Scanner(System.in);
		//char ch = scan.next().charAt(0); //Character input
		String ch = scan.nextLine(); //string input
		int a = scan.nextInt(); //integer input
		
		if(ch == "a" || ch == "e" || ch == "i" || ch == "o" || ch == "u") {
			System.out.println(ch + " is a vowel");
		}
		else {
			System.out.println(ch + " is a consonent");
		}
		scan.close();
	}
}
