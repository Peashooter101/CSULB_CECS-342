# CSULB_CECS-342

Programming Assignments from California State University Long Beach (CSULB).

CECS 342 - Principles of Programming Languages

## Assignment 1 (C, Haskell)

Recreate Quick Sort and Merge Sort in C and Haskell.

<details>
  <summary>Assignment Details</summary>
  In this assignment you will compare the imperative with the functional programming paradim.
  
  1. Remember the sorting algorithms quick sort (Tony Hoare, 1959) and merge sort (John von Neumann, 1945).
  2. Write each sorting algorithm in C and in Haskell by implementing the following functions:
  
  ```c
  void qsort2(int *a, int n);  // quick sort array a with n elements in place in C
  void msort(int *a, int n);   // merge sort array a with n elements in place in C
  ```
  
  ```haskell
  qsort :: Ord a => [a] -> [a]  -- quick sort a list in Haskell
  msort :: Ord a => [a] -> [a]  -- merge sort a list in Haskell
  ```
  
  3. The implementation of merge sort in C will require a temporary array. This array has to be allocated on the heap (and not the stack).
  Make sure to do this correctly and try to understand why this is necessary.
  4. Write a simple main function (one in C and one in Haskell) with a few test cases.
  Make sure to cover edge cases like empty or invalid input.
  5. Please submit you .c and .hs files to Canvas. Don't submit anythings else (like make files or project files).
</details>

## Assignment 2 (C, C++, C#, Python, Haskell)

Generic Programming: C, C++, C#, Python, Haskell

<details>
  <summary>Assignment Details</summary>
  The objective of this assignment is to research how generic programing works in different programing languages.

  The general idea of generics (or polymorphism as it is sometimes called in a functional programing context) is to reuse the same source code with different data types.
  
  1. In this assignment, you will use 5 different programming languages to solve the same problem: Use a generic sort function to sort values of different types. The values to sort could be integers, ﬂoating point numbers, strings, pairs of values (say a string and a number), or any other type of values that can be compared.
  
  2. Write a console application in each of these 5 languages: C, C++, C#, Python and Haskell.
  
  3. Each application has to use the following data:
     - The following sequence of ﬂoating point numbers:
     
     ```
     645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25
     ```
      
     - The following sequence of people with name and age of each person. The name is a string and the age an integer:
     
     ```
     Hal, 20; Susann, 31; Dwight, 19; Kassandra, 21; Lawrence, 25; Cindy, 22; Cory, 27; Mac, 19; Romana, 27; Doretha, 32;
     Danna, 20; Zara, 23; Rosalyn, 26; Risa, 24; Benny, 28; Juan, 33; Natalie, 25
     ```
      
     - Use appropriate data structures to represent the data above in each of the 5 languages and deﬁne the variables `numbers` and `people`, respectively.
     
  4. Find generic sort functions for each of the 5 languages.
     - The objective of this assignment is to understand generics (not sorting). You can use the sort functions from Lab Assignment 1 or just use a sort function provided in some standard library for the respective language.
     - C doesn’t really provide generics. However, a `void*` can be used to point to any value.
     - One way to specify an order on a type is to deﬁne a comparison function that compares two values. This comparison function could be an argument to your sort function. Some languages might provide predeﬁned comparison functions.
     - Try to use everything we learned about these different programing languages, e.g., Python uses duck-typing, Haskell uses the type-class `Ord` to express order on a type, LINQ in C# includes the `orderby` operator, etc.
     
  5. Use the generic sort functions of each language to
     - sort `numbers` ascending by numerical value,
     - sort `people` alphabetically (lexicographically) by name, and to
     - sort `people` descending by age, where people of the same age should be sorted alphabetically (lexicographically).
  
  6. The point here is to reuse as much code as possible to perform all 3 different sort operations. Try to isolate the speciﬁc code that is needed for each of the three tasks.
  
  7. Write a main function in each of the 5 languages to test your code by writing the sort results to the console.
</details>

## Assignment 3 (C#, LINQ)

C# and LINQ Queries

<details>
  <summary>Assignment Details</summary>
  In this lab, you will use C# and LINQ to iterate files, to query, group and order data, and to create an XML document based on that data.

  The general idea of generics (or polymorphism as it is sometimes called in a functional programing context) is to reuse the same source code with different data types.
  
  1. Create a C# console application.
     - This application has two command line arguments: A path to a folder and a path to an HTML report output file.
     - The application collects all files with the same extension (converted to lower case) and determines for each extension, i.e. file type, the number of files and the total size of all files of this type.
  
  2. Implement a class with the following 4 static functions:
     ```c#
     static IEnumerable<string> EnumerateFilesRecursively(string path)
     ```
     - Enumerate all files in a given folder recursively including the entire sub-folder hierarchy.
     - You can use `System.IO.Directory`. You could use the generator pattern (`yield` keyword) to implement the iterator.
     
     ```c#
     static string FormatByteSize(long byteSize)
     ```
     - Format a byte size in human readable form. Use the following units: B, kB, MB, GB, TB, PB, EB, and ZB where 1kB = 1000B, etc.
     - The numerical value should be greater or equal to 0, less than 1000, and rounded to 2 digits after the decimal point, e.g. "1.30kB".
     
     ```c#
     static XDocument CreateReport(IEnumerable<string> files)
     ```
     - Create a HTML document containing a table with three columns: “Type”, “Count”, and “Size” for the file name extension (converted to lower case), the number of files with this type, and the total size of all files with this type, respectively.
     - You can use `System.IO.FileInfo` to get the size of a file with a given path.
     - Sort the table by the byte size value of the “Size” column in descending order.
     - Use your `FormatByteSize` function to format the value printed in the “Size” column.
     - Implement this function using LINQ queries making use of `group by` and `orderby`.
     - Use the `System.Xml.Linq.XElement` constructor to functionally construct the XML/HTML document.
     
     ```c#
     public static void Main(string[] args)
     ```
     - Take two command line arguments. The first value is the path of the input folder and the second the path (inluding file name and extension) of the HTML report output file. Call the functions above to create the report file.
     
  3. ***Do not*** store the intermediate data. Instead you should use iterators/generators to process the sequences of data element by element without storing the entire collection.
</details>

## Assignment 4 (Prolog)

Prolog: Solving a Logic Puzzle

<details>
  <summary>Assignment Details</summary>
  Write a Prolog program to solve the logic puzzle below.

  You will need a way of writing statements about events that occurred earlier in the week than other events. Define a predicate `earlier/2` to express this, e.g. `earlier(tuesday, wednesday)`.
  
  ### Logic Puzzle
  Last week, four UFO enthusiasts made sightings of unidentified flying objects in their neighborhood. Each of the four reported his or her sighting on a different day, and soon the neighborhood was abuzz with rumors of little green men. By the weekend, though, the government stepped in and was able to give each person a different, plausible explanation of what he or she had “really" seen. Can you determine the day (Tuesday through Friday) each person sighted a UFO, as well as the object that it turned out to be?
    1. Mr. Klaatu made his sighting at some point earlier in the week than the one who saw the balloon, but at some point later in the week than the one who spotted the Frisbee (who isn't Ms. Gort).
    2. Friday'a sighting was made by either Ms. Barada or the one who saw a clothesline (or both).
    3. Mr. Nikto did not make his sighting on Tuesday.
    4. Mr. Klaatu isn't the one whose object turned out to be a water tower.
</details>
