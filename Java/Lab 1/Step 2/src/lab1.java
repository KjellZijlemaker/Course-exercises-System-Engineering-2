
public class lab1 {

	public static void main(String[] args) {
		
		// Instantiating the Thread class for making new Thread
		// Instanting SecondFile withing the Thread instantiating and giving file number
		Thread thread1 = new Thread(new SecondFile(1));
		Thread thread2 = new Thread(new SecondFile(2));

		// Starting the threads
		thread1.start();
		thread2.start();
	}

}
