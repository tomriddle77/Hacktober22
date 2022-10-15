import tkinter
from tkinter import Tk
from tkinter import *
import os
import sys
root = Tk()
root.title("PyIDE")

def run():
                code = editor.get('1.0', END)
                os.system("mkdir MyPythonProjects")
                f = open("MyPythonProjects\Main.py", "w")
                f.write(code)
                f.close()
                os.startfile("MyPythonProjects\Main.py")

menu_bar = Menu(root)
run_bar = Menu(menu_bar, tearoff=0)
run_bar.add_command(label='Run', command=run)
menu_bar.add_cascade(label='Run', menu=run_bar)
root.config(menu=menu_bar)

editor = Text()
editor.pack()
root.mainloop()
