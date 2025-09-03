# Data Structures Study Guide 📚  
**Lectures 01–05: Comprehensive Notes**  

---

## **Lecture 01: Introduction to Data Structures & Algorithm Analysis**  

### **1.1 What is a Data Structure?**  
- A **data structure** is a way of organizing and storing data in a computer so that it can be accessed and modified efficiently.  
- **Types of Data Structures**:  
  - **Primitive**: Basic data types like `int`, `float`, `char`.  
  - **Non-Primitive**: Derived structures like arrays, linked lists, stacks, queues, trees, and graphs.  

### **1.2 Characteristics of a Good Program**  
- A good program should:  
  - Run efficiently and correctly.  
  - Be easy to read, debug, and modify.  
  - Consist of well-designed **data structures** and **algorithms**.  

### **1.3 Algorithm Analysis**  
- **Time Complexity**: Measures the number of operations an algorithm performs as a function of input size.  
  - Example: Linear search has a time complexity of `O(n)`.  
- **Space Complexity**: Measures the amount of memory an algorithm uses.  
- **Worst-Case Analysis**: Focuses on the maximum time/space required for any input of size `n`.  

### **1.4 Why Data Structures?**  
- To solve complex problems efficiently.  
- To optimize **space** and **time** usage.  
- Example: Google uses advanced data structures to provide search results in milliseconds.  

---

## **Lecture 02: String Operations & Pattern Matching**  

### **2.1 String Storage**  
- **Fixed-Length Storage**:  
  - All records have the same length.  
  - Pros: Easy to access.  
  - Cons: Wastes space if strings are shorter than the fixed length.  
- **Variable-Length Storage**:  
  - Uses markers (e.g., `$$`) or length prefixes.  
  - Pros: Efficient use of space.  
  - Cons: Slower access due to variable lengths.  
- **Linked Storage**:  
  - Uses linked lists to store strings.  
  - Pros: Dynamic and flexible.  
  - Cons: Slower access due to pointer traversal.  

### **2.2 String Operations**  
- **LENGTH**: Returns the number of characters in a string.  
- **SUBSTRING**: Extracts a portion of a string.  
  - Example: `SUBSTRING("HELLOWORLD", 4, 5) → "LOWOR"`.  
- **CONCATENATION**: Combines two strings.  
  - Example: `"HELLO" + "WORLD" → "HELLOWORLD"`.  
- **INSERT**: Inserts a substring into a string.  
  - Example: `INSERT("ABCDEF", 3, "XYZ") → "ABXYZCDEF"`.  
- **DELETE**: Removes a substring from a string.  
  - Example: `DELETE("ABCDEF", 2, 3) → "AEF"`.  
- **REPLACE**: Replaces a substring with another.  
  - Example: `REPLACE("ABXYEFGH", "XY", "CD") → "ABCDEFGH"`.  

### **2.3 Pattern Matching**  
- **Naive Algorithm**:  
  - Compares the pattern with every substring of the text.  
  - Time Complexity: `O(nm)`, where `n` is the text length and `m` is the pattern length.  
- **Optimized Algorithm (KMP)**:  
  - Uses a failure function table to skip unnecessary comparisons.  
  - Time Complexity: `O(n + m)`.  

---

## **Lecture 03: Arrays & Basic Algorithms**  

### **3.1 Linear Arrays**  
- A **linear array** is a list of elements stored in contiguous memory locations.  
- **Address Calculation**:  
  - `LOC(A[k]) = Base(A) + w * (k - LB)`, where:  
    - `Base(A)`: Starting address.  
    - `w`: Size of each element.  
    - `LB`: Lower bound of the index.  
  - Example: Base=200, w=4, LB=5 → `A[15]` address = `300 + 4*(15-5) = 340`.  

### **3.2 Array Operations**  
- **Traversal**: Process each element (e.g., print, count).  
- **Insertion**: Add an element at a specific position.  
  - Example: Insert `27` at position 4 in `[10, 12, 5, 7, 15] → [10, 12, 5, 27, 7, 15]`.  
- **Deletion**: Remove an element from a specific position.  
  - Example: Delete element at position 4 in `[10, 12, 5, 7, 15] → [10, 12, 5, 15]`.  

### **3.3 Searching Algorithms**  
- **Linear Search**:  
  - Checks each element sequentially.  
  - Time Complexity: `O(n)`.  
- **Binary Search**:  
  - Works on sorted arrays by repeatedly dividing the search interval in half.  
  - Time Complexity: `O(log n)`.  

### **3.4 Sorting Algorithms**  
- **Bubble Sort**:  
  - Repeatedly swaps adjacent elements if they are in the wrong order.  
  - Time Complexity: `O(n²)`.  
  - Example: `[5, 3, 8, 1] → [1, 3, 5, 8]` after 3 passes.  

---

## **Lecture 04: 2D Arrays & Longest Common Subsequence (LCS)**  

### **4.1 2D Arrays**  
- A **2D array** is a matrix with rows and columns.  
- **Address Calculation**:  
  - **Row-Major Order**: `LOC(A[i][j]) = Base(A) + w * (cols * (i-1) + (j-1))`.  
  - **Column-Major Order**: `LOC(A[i][j]) = Base(A) + w * (rows * (j-1) + (i-1))`.  

### **4.2 Longest Common Subsequence (LCS)**  
- **Definition**: The longest sequence that appears in the same order in two strings.  
- **Dynamic Programming Approach**:  
  - Build a table to track common subsequences.  
  - Example: LCS of "ABCBDAB" and "BDCAB" is "BCAB" (length=4).  
  - Steps:  
    1. Initialize a table with zeros.  
    2. If characters match: `c[i][j] = c[i-1][j-1] + 1`.  
    3. If no match: `c[i][j] = max(c[i-1][j], c[i][j-1])`.  

---

## **Lecture 05: Advanced Sorting Algorithms**  

### **5.1 Merge Sort**  
- **Divide & Conquer**:  
  - Split the array into two halves, sort each half, and merge them.  
  - Time Complexity: `O(n log n)`.  
  - Example: `[18, 3, 12, 9] → [3, 9, 12, 18]`.  

### **5.2 Insertion Sort**  
- Builds the sorted array one element at a time.  
- Time Complexity: `O(n²)` (best: `O(n)` for sorted data).  

### **5.3 Radix Sort**  
- Sorts numbers by their digits (LSD or MSD).  
- Time Complexity: `O(d(n+k))`, where `d` is the number of digits and `k` is the base.  
- Example: `[329, 457, 657] → sorted by units → tens → hundreds`.  

### **5.4 Bucket Sort**  
- Distributes elements into buckets, sorts each bucket, and concatenates.  
- Example: `[0.78, 0.17, 0.39] → buckets [0.1-0.3, 0.3-0.5, ...]`.  

### **5.5 Counting Sort**  
- Non-comparative; counts occurrences of each element.  
- Time Complexity: `O(n + k)`, where `k` is the range of input.  
- Example: `[4, 2, 2, 8] → count array [0, 0, 2, 0, 1, ..., 1] → sorted`.  

---

## **Key Formulas & Tables**  

### **Time Complexities**  
| Algorithm         | Best       | Average    | Worst      |  
|--------------------|------------|------------|------------|  
| Bubble Sort       | O(n)       | O(n²)      | O(n²)      |  
| Merge Sort        | O(n log n) | O(n log n) | O(n log n) |  
| Binary Search     | O(1)       | O(log n)   | O(log n)   |  
| LCS               | -          | -          | O(nm)      |  

### **Memory Calculation (Row-Major)**  
For `A[i][j]` in a 2D array with `cols` columns:  
`Address = Base(A) + w * (cols * (i-1) + (j-1))`  

---

## **Real-World Applications**  
- **LCS**: DNA sequencing, plagiarism detection.  
- **Radix Sort**: Sorting large integers or fixed-length strings.  
- **Bucket Sort**: Sorting floating-point numbers uniformly distributed in [0,1).  

---

## **Key Takeaways**  
- **Data Structures**: Organize data for efficient access and manipulation.  
- **Algorithms**: Step-by-step procedures to solve problems.  
- **Sorting & Searching**: Essential for optimizing performance in real-world applications.  

---
