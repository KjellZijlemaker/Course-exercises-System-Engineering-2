#! /usr/bin/python

import _thread as thread

# Importing SecondScript class
import SecondScript

# Main method for calling the main writing to file and instantiate object
def main():
    readWrite()

    # Instantiating object from the SecondScript
    runSecondScript = SecondScript.SecondScript()
    runSecondScript.run()

# Method for making a new thread
def makeThread():
    try:

        # Starting new thread with readWrite function as target
        thread.start_new_thread( readWrite)
    except:
        print ("Error: Unable to start thread")
    while 1:
        pass

# Method for writing the file
def readWrite():
    file = open("File 1", "w")
    file.write("This is file 1")
    file.close()

# Executing the mail
if __name__ == "__main__":
    main()
