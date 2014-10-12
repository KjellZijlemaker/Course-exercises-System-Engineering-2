/**
 * Java bean for getters and setters, for the message passing
 * 
 * @author kjellzijlemaker
 *
 */
public class Message {
	private String msg;

	/**
	 * Constructor for giving message content
	 * 
	 * @param str
	 */
	public Message(String str) {
		this.msg = str;
	}

	/**
	 * Getting the message content
	 * 
	 * @return
	 */
	public String getMsg() {
		return this.msg;
	}

	/**
	 * Setting the message content
	 * 
	 * @param str
	 */
	public void setMsg(String str) {
		this.msg = str;
	}
}
