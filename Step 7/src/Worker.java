import java.io.BufferedWriter;
import java.io.FileWriter;

public class Worker implements Runnable {

	// Setting private variables for only THIS class
	private String command;
	private int incrementor;

	// Setting constructor for giving command and incrementor
	public Worker(String s, int incrementor) {
		this.command = s;
		this.incrementor = incrementor;
	}

	@Override
	public void run() {

		// Printing the name of the current Thread with the command name
		System.out.println(Thread.currentThread().getName()
				+ " Start. Command = " + command);

		// Executing Thread code
		readWriteFile();

		// Printing the ending of the Thread
		System.out.println(Thread.currentThread().getName() + " End.");
	}

	// Method for writing to new files
	private void readWriteFile() {
		try {

			// With each new Thread, Thread will sleep for 2 seconds
			Thread.sleep(2000);

			// Making new file, with the filename + number
			FileWriter fstream = new FileWriter("File " + incrementor);

			// Making the outStream (output) to the file
			BufferedWriter out = new BufferedWriter(fstream);

			// For every file, make the table from 1 through 10
			for (int i = 0; i < 11; i++) {

				// Setting the table
				int table = i * incrementor;

				// Write the result to the file
				out.write(i + " x " + incrementor + " = " + table + "\n");
			}

			// Close the file
			out.close();

			// Catch if something went wrong with making file
		} catch (Exception e) {
			System.out.println("Something went wrong :*( \n" + e.getMessage());
		}
	}

	// Setting the command to a String (the number of Thread)
	@Override
	public String toString() {
		return this.command;
	}
}
