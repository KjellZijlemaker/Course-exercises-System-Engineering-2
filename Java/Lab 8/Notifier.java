/**
 * The notifier (aka monitor) is being maintainted here. All the hard work is
 * done here to keep the threads in sync.
 * Note: It is also possible to change the message it was receiving by the main thread
 * 
 * @author kjellzijlemaker
 *
 */
public class Notifier implements Runnable {

	// Setting messages here
	private Message msg;
	private Message msg2;
	private Message msg3;

	/**
	 * Messages are given through the main class here, so they can work
	 * 
	 * @param msg
	 * @param msg2
	 * @param msg3
	 */
	public Notifier(Message msg, Message msg2, Message msg3) {
		this.msg = msg;
		this.msg2 = msg2;
		this.msg3 = msg3;
	}

	/**
	 * Running the method
	 */
	@Override
	public void run() {

		/**
		 * While true, the monitor thread will execute and pass the massage, so
		 * the Waiter can execute
		 */
		while (true) {

			// Getting current name of the thread
			String name = Thread.currentThread().getName();
			
			// When the notifier has started to execute, the following message will be printed
			System.out.println("\n\n  " + name + " Has passed the message");
			
			// Now try to set the first message and notify the waiter thread
			try {
				Thread.sleep(1000);
				synchronized (msg) {
					msg.setMsg(msg.getMsg());
					msg.notify();
					// msg.notifyAll();
				}
				
				// Do the same for the second message
				Thread.sleep(1000);
				synchronized (msg2) {
					msg2.setMsg(msg2.getMsg());
					msg2.notify();

				}
				
				// And the third message
				Thread.sleep(1000);
				synchronized (msg3) {
					msg3.setMsg(msg3.getMsg());
					msg3.notify();

				}
				
				// When all messages passed, wait for one second to cool off...
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
