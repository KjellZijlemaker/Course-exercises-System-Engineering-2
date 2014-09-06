#!/usr/bin/python
import threading

def main():

	# For loop for the work pool
	for i in range (1, 11):
		
		# Making new threading target with arguments
		t = threading.Thread(target=worker, args=(i,))
		
		# Starting the thread one by one
		t.start()

# Method for the worker pool
def worker(num):

	# Open file to write (with num for file number)
    file = open("file " + str(num), "w")
    
	# initializing i to 0 for loop
	i = 0
	
	# While i is smaller then 11 (10), the loop will execute
    while i < 11:
	
		# computing the table with the incrementor and filenumber
        table = i * num
		
		# Writing the table and result to the file
        file.write(str(i) + " x " + str(num) + " = " + str(table) + "\n")

		# Incrementing the integer for while loop
        i = i + 1
	
	# Closing the file
    file.close()
	
	# Return nothing
    return

# Starting the main method
if __name__ == "__main__":
	main()

