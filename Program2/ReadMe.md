In this program, I have :

* Worked with pointers
* Worked with binary values

## Part A: String Manipulations

In the second program I have created a library file containing 4 functions. The driver code runs and tests the library code. I have created a second file that can be included in the driver code so the compiler can link them into an executable.

For this part of the program I have implemented my own version of the library function [strstr()](http://www.cplusplus.com/reference/cstring/strstr/), with the following function interface:
int myStrStr (char  * haystack, char * needle, char * buffer);
   * The function will take 3 strings, a 'haystack' string, a 'needle' string, and a buffer string. It will search the haystack string for a sequence matching the needle string, and copy the found result (the entire substring) from the haystack string into the buffer (do not copy the needle string).
   * It will return a 1 if the matching sequence in the haystack is found and a 0 if the needle is not found.
   * The library strstr() function is not used in my implementation. It is only for reference.  
   
## Part B: Bits and Bytes

I have written a function that counts the number of 1's in the binary representation of an integer passed as a parameter to a function called `countOnes()`. 
Next I have written a looping binary interpreter that creates an array representation of a binary value.
* Written a function that uses **bit shifting** to store the binary representation of an integer in an array passed as a parameter. The size of the array is provided and I have made sure to fill out all elements in the array. To generate the array of values, I have used a bit mask and bitwise right shift.
    * 8 would store the following value in my array
        * 0000 0000 0000 0000 0000 0000 0000 1000
* The provided driver code (main) which calls the binaryArray function with each of the below values and an array buffer to print the binary representation (from right to left) for each one:
    * 2
    * 255
    * -1
    * INT_MAX
    * INT_MIN
