import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ThreadPool {

	public static void main(String[] args) {

		// Making a new Threadpool from the ExecutorService class
		ExecutorService executor = Executors.newFixedThreadPool(10);

		// Going through loop for making new Threads and execute them
		for (int i = 1; i < 11; i++) {

			// Giving the command (Thread Number) to the Worker class + the
			// incrementor
			Runnable worker = new Worker("" + i, i);
			executor.execute(worker);
		}

		// Shutdown the pool when done
		executor.shutdown();

		while (!executor.isTerminated()) {
		}

		// When done:
		System.out.println("FInished all threads");
	}

}
