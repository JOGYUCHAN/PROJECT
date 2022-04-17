from tkinter import*
from tkinter import ttk
##2019038055조규찬

window = Tk()

baseTab = ttk.Notebook(window)

tabDog = ttk.Frame(baseTab)
baseTab.add(tabDog, text='강아지')
tabCat = ttk.Frame(baseTab)
baseTab.add(tabCat, text='고양이')

baseTab.pack(expand=1, fill='both')

photoDog = PhotoImage(file = "C:\Python\Python310\gif\dog.gif")
labelDog = Label(tabDog, image = photoDog)
labelDog.pack()

photoCat = PhotoImage(file = "C:\Python\Python310\gif\Cat.gif")
labelCat = Label(tabCat, image = photoCat)
labelCat.pack()

window.mainloop()
