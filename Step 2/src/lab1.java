
public class lab1 {

	public static void main(String[] args) {
		Thread thread1 = new Thread(new SecondFile(1));
		Thread thread2 = new Thread(new SecondFile(2));

		thread1.start();
		thread2.start();
	}

}
