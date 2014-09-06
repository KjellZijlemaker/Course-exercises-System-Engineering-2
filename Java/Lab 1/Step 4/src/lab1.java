/* 
* Author: Kjell Zijlemaker
* Version: 1.2
* Date: 6-9-2014
*/

import java.io.BufferedWriter;
import java.io.FileWriter;

public class lab1{
	
	public static void main(String[] args) {
		
		// Initializing SecondFile classes, with filenumber
		SecondFile thread1 = new SecondFile(1);
		SecondFile thread2 = new SecondFile(2);
		
		// Starting the threads
		thread1.start();
		thread2.start();
	}
}
