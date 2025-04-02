package LambdaExpression;

import java.util.*;

public class SortingWithComparator {

	public static void main(String[] args) {
		//String[] planets = new String[] {"Mercury", "Venus", "Earth",
		//		"Mars", "Saturn", "Uranus", "Neptune"};
		
		List<String> planets = Arrays.asList("Mercury", "Venus", "Earth",
											"Mars", "Saturn", "Uranus", "Neptune");
		
		System.out.println("Sorted in dictionary order:");
		planets.sort((String first, String second) -> first.compareTo(second));
		System.out.println(planets);
		
		System.out.println("Sorted in length order:");
		planets.sort((String first, String second) -> first.length() - second.length());
		System.out.println(planets);
		
		
	}

}
