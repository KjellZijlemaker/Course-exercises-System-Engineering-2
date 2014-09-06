import java.io.BufferedWriter;
import java.io.FileWriter;

public class SecondFile implements Runnable{

	// Setting incrementor for the number given by main class
	private int incrementor;
	
	// Constructor for initializing the incrementor
	public SecondFile(int incrementor) {
		this.incrementor = incrementor;
	}
	
	// Implementing the Run method from the Runnable class
	@Override
	public void run() {
		try{
			
			// Making new stream and filename, with the incrementor
			FileWriter fstream = new FileWriter("File " + incrementor);
			
			// Making a stream for the file so the program can write to it
			BufferedWriter out = new BufferedWriter(fstream);
			
			// Making text for the file
			out.write("This is file: " + incrementor);
			
			// Closing the file
			out.close();
		}
		
		// If something went wrong, send message:
		catch (Exception e){
			System.out.println("Something went wrong :*( \n"
					+ e.getMessage());
		}
	}
}
