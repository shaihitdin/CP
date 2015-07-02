/* 2015 Spring Algorithms Programming Homework #4
   [Order Statistics] Selection in worst-case linear time
   Given an unordered number, find ith smallest number in linear (worst case) time
   Reference, 
(1) CLRS, Selection in worst-case linear time, Introduction to Algorithm (CLRS book), 215-222 pages
(2) Lars Vogel, Quicksort in Java - Tutorial, http://w...content-available-to-author-only...a.com/tutorials/JavaAlgorithmsQuicksort/article.html
 
   Written by Jaesik Choi (May 13th, 2015), jaesik@unist.ac.kr	
   Note: If you do not have a JAVA IDE or compiler installed, you can use online IDE such as ideone.com. Just copying and pasting the code will work. 
 
Input will be given in the standard input of JAVA as follow
26 <- number or elements
5 2 3 4 1 6 7 8 4 2 3 4 5 5 2 3 4 1 6 7 8 4 2 3 4 5 <- data
10 <- ith order to be chosen
*/
 
/* Name: [Write your name in English. First name + space + last name (e.g., Jaesik Choi)]
   ID: [Write your UNIST ID]
   E-mail: [e.g., Jaesik Choi]
   
   Brief Explanation: [My implementat is based on blah blah blah.. use blah blah data structure.]
 
   Reference and/or Collaborations: [I refer to blah blah material when writing this code. I also discussed with A, B, and C. However, I write the code my own.]
*/
 
import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.Arrays;
import java.math.*;
import java.util.Random;
 
public class Main
{
	public int select(int[] values, int order) {
		if (values == null || values.length==0 ) {
			return -1;
		}
 
		int[] numbers;		
		numbers = values;
 
		return linearsearch(numbers, 0, values.length-1, order-1);
	}
	private int min( int x, int y ) {
		if ( x > y ) {
			return y;
		} else {
			return x;
		}
	}
 
	private int find_median_of_5( int[] numbers, int idx ) {
		if ( idx+5 > numbers.length ) return numbers[idx];
 
		// [Your task 1] Please write your code here
		return numbers[idx]; // <- this code should be changed		
	}
 
	private int median_of_median( int[] numbers, int low, int high ) {
 
		// [Your task 2] Please write your code here
		return numbers[low]; // <- this code should be changed
	}
 
	private int linearsearch(int[] numbers, int low, int high, int order) {
		int i = low, j = high;
		if ( low == high ) return numbers[low];
		int pivot = median_of_median( numbers, low, high );
 
		while ( i <= j ) {
			while ( numbers[i] < pivot) {
				i++;
			}
 
			while ( numbers[j] > pivot ) {
				j--;
			}
 
			if ( i <= j ) {
				exchange( numbers, i, j );
				i++;
				j--;
 
			}
		}
  
		if ( order <  i ) {
			return linearsearch( numbers, low, i-1, order);
		} else {
			return linearsearch( numbers, i, high, order );
		}
 
	}
 
	private void exchange(int[] numbers, int i, int j ) {
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}
 
	public static void main (String[] args) throws java.lang.Exception
	{
		Main selecter = new Main();
		Random randomGenerator = new Random();
		int order;
		int[] test;
 
		test = new int[]{5, 2, 3, 4, 1, 6, 7, 8, 4, 2, 3, 4, 5, 5, 2, 3, 4, 1, 6, 7, 8, 4, 2, 3, 4, 5};
		order = randomGenerator.nextInt( test.length );  					
 
		System.out.println( Integer.toString( order ) + ":" + Integer.toString( selecter.select( test, order) ) );
 
	}
}