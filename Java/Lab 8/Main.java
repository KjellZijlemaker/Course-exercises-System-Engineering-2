/**
 * Main class for making the threads and execute them.
 * Note: No work is done here, only the starting of Threads!
 * @author kjellzijlemaker
 *
 */
public class Main {

	public static void main(String[] args) {
		
		// Setting the variables to print here
		String numbers = "123456789";
		String letters = "abcdefghijklmnopqrstuvwxyz";
		String upperCaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		// Making new message (from the javaBean)
		Message message = new Message(numbers);
		
		// Making new waiter and put the new message in there
        Waiter waiter = new Waiter(message);
        
        // Execute new thread with the name "waiter"
        new Thread(waiter,"waiter").start();
         
        // Same as above
        Message message2 = new Message(letters);
        Waiter waiter1 = new Waiter(message2);
        new Thread(waiter1, "waiter1").start();
        
        // Same as above
        Message message3 = new Message(upperCaseLetters);
        Waiter waiter3 = new Waiter(message3);
        new Thread(waiter3, "waiter3").start();
        
        // Making new monitor for message passing and put all messages in the monitor
        Notifier notifier = new Notifier(message, message2, message3);
   
        // Making new thread for this monitor
        new Thread(notifier, "Monitor").start();
        System.out.println("All the threads are started");

	}

}
