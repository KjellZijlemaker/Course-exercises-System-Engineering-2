import java.io.BufferedWriter;
import java.io.FileWriter;


public class SecondFile extends Thread {

	private int incrementor;
	
	public SecondFile(int incrementor){
		this.incrementor = incrementor;
	}
	
	public void run() {
		try {
			FileWriter fstream = new FileWriter("File " + incrementor);
			BufferedWriter out = new BufferedWriter(fstream);
			out.write("This is file: " + incrementor);
			out.close();
		} catch (Exception e) {
			System.out.println("Something went wrong :*( \n" + e.getMessage());
		}

	}
}
