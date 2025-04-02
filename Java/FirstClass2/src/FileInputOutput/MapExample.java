package FileInputOutput;

import java.util.HashMap;
import java.util.Map;

public class MapExample {
	public static void main(String[] args){
		Map<String,Integer> sampleMap = new HashMap<String,Integer>(); //random ordered elements
		sampleMap.put("Std1", 60);
		sampleMap.put("Std2", 70);
		sampleMap.put("Std3", 80);
		sampleMap.put("Std4", 90);
		
		System.out.println(sampleMap); //print the map
		
		System.out.println(sampleMap.get("Std1"));
		
		for(String mapKey:sampleMap.keySet()){
			System.out.println(mapKey);
		}
		for(String mapKey:sampleMap.keySet()){
			System.out.println(sampleMap.get(mapKey));
		}
	
	}
}
