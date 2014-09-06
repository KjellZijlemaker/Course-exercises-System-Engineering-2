#! /usr/bin/python

""" 
* Author: Kjell Zijlemaker
* Version: 1.2
* Date: 6-9-2014
"""

# Importing the subprocess module
import subprocess

# Main function for executing functions
def main():
    readWrite()
    makeCall()

# Make new file and writing to it
def readWrite():
    file = open("File 1", "w")
    file.write("This is File 1")
    file.close

# Make the subprocess call to the second script
def makeCall():
    subprocess.call(["python", "SecondFile.py"])

if __name__ == "__main__":
    main()
