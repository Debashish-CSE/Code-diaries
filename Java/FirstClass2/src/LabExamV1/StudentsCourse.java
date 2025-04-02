package LabExamV1;

import java.io.*;
import java.lang.Exception;
import java.util.*;

public class StudentsCourse {
	public static void main(String[] args) {
		Map<String, Integer> map = new HashMap<>();
		try(BufferedReader reader = new BufferedReader(new FileReader("D:/Programming/Java/salary.txt"))){
			String line;
			while((line = reader.readLine()) != null) {
				String[] parts = line.split("\t");
				if(parts.length == 2) {
					String key = parts[0].trim();
					String value = parts[1].trim();
					Integer value1;
					if(value.equals("Null")) {
						value1 = null;
					}
					else {
						value1 = Integer.parseInt(value);
					}
					map.put(key, value1);
				}
			}
			reader.close();
			for(Map.Entry<String, Integer> entry: map.entrySet()) {
				System.out.println(entry.getKey() + "\t" +entry.getValue());
			}
			
			/*if (map.containsKey("Player B")) {
			    Integer currentSalary = map.get("Player B");
			    if (currentSalary == null) {
			        currentSalary = 0; // Assign a default value for null salaries
			    }
			    map.put("Player B", currentSalary + 50000);
			}*/

			if(map.containsKey("Player A") && map.get("Player A") != null) {
				map.put("Player A", map.get("Player A")+50000);
			
			
				BufferedWriter writer = new BufferedWriter(new FileWriter("D:/Programming/Java/salary.txt"));
				for(Map.Entry<String, Integer> entry : map.entrySet()) {
					writer.write(entry.getKey() + "\t" + (entry.getValue()== null ? "Null" : entry.getValue()));
					writer.newLine();
				}
				writer.close();
				System.out.println("Successfully updated");
			}
			else {
				System.out.println("Player not found");
			}
		
		}
		
		catch(IOException e) {
			System.out.println("An error occured");
			e.printStackTrace();
		}
		catch(NumberFormatException e) {
			System.out.println("Cannot convert string to integer");
			e.printStackTrace();
		}
		
	}

}
