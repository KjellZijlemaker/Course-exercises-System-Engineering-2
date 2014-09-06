import java.io.BufferedWriter;
import java.io.FileWriter;

public class lab1{
	
	public static void main(String[] args) {
		SecondFile thread1 = new SecondFile(1);
		SecondFile thread2 = new SecondFile(2);
		
		thread1.start();
		thread2.start();
	}

	

}
