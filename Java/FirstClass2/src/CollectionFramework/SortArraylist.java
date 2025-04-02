package CollectionFramework;

import java.util.Collections;
import java.util.List;
import java.util.ArrayList;

public class SortArraylist {
	public static void main(String[] args){
		List<String> a1 = new ArrayList<String>();
		a1.add("mango");
		a1.add("orange");
		a1.add("grapes");
		for(String fruit:a1){
			System.out.println(fruit);
		}
		System.out.println();
		
		Collections.sort(a1);
		for(String fruit:a1){
			System.out.println(fruit);
		}
		System.out.println();
		
		System.out.println("\nSearching for: "+ "mango");
		int result = Collections.binarySearch(a1, "mango"); //Collections.binarySearch(list, key);
		System.out.println((result >= 0 ? "Found at index "+result:"Not found ("+result+")"));
	}
}