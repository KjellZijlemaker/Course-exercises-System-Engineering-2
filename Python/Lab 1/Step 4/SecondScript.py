#! /usr/bin/python

# Class for instantiating the SecondScript, without calling subprocesses
class SecondScript:

    # Method for making second file
    def run(self):
        file = open("File 2", "w")
        file.write("This is File 2")
        file.close()
