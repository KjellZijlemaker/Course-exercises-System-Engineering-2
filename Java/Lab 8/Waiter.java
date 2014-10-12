/**
 * Waiter class for printing the message, only when a notify has been given from
 * the notifier.
 * 
 * @author kjellzijlemaker
 *
 */
public class Waiter implements Runnable {

	// Setting the message class variable
	private Message msg;

	/**
	 * Giving the message, made for the waiter, for using later on
	 * 
	 * @param m
	 */
	public Waiter(Message m) {
		this.msg = m;
	}

	@Override
	public void run() {

		/**
		 * While true, execute the waiter thread and try to print the message
		 */
		while (true) {
			// String name is for debugging purposes only
			// String name = Thread.currentThread().getName();
			
			/**
			 * When synchronized, wait until the thread is notified..
			 * See the commented line for explaination
			 */
			synchronized (msg) {
				try {
					// System.out.println(name+" waiting to get notified at time:"+System.currentTimeMillis());
					
					// Waiting until the message will be passed by the monitor
					msg.wait();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				/**
				 * When notified, the following message should appear.
				 * For debugging purposes only
				 */
				// System.out.println(name+" waiter thread got notified at time:"+System.currentTimeMillis());

				/**
				 * Process the message now Commented line is for debugging if
				 * thread is indeed executing
				 */
				// System.out.println(name+" processed: "+msg.getMsg());

				/**
				 * Printing the message that was given
				 */
				System.out.print(msg.getMsg());

			}

		}

	}
}
