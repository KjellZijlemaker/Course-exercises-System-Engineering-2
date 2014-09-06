#!/usr/bin/python
import threading

def worker(num):
    file = open("file " + str(num), "w")
    i = 0
    while i < 11:
        table = i * num
        file.write(str(i) + " x " + str(num) + " = " + str(table) + "\n") 
        i = i + 1
    file.close()
    return

for i in range (1, 11):
    t = threading.Thread(target=worker, args=(i,))
    t.start()

