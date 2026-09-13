import pickle
import os


def add_rec():
	book_no=int(input("Enter the Book Number : "))
	book_name =input("Enter the name of the book : ")
	Author = input("Enter the Author name : ")
	Price = int(input("Enter the price of Book : "))
	arr = [book_no,book_name,Author,Price]
	f=open("book.dat","ab")
	pickle.dump(arr,f)
	f.close()

def disp_rec():
	f=open("book.dat","rb")
	count=0
	try:
		while(True):
			records=pickle.load(f)
			print("===================")
			print("      BOOK ",records[0])
			print("===================")
			print("Book Name : ",records[1])
			print("Author Name : ",records[2])
			print("Book Price : ",records[3])
			print("===================")
			count=count+1
	except EOFError:
			pass
	except FileNotFoundError:
		print("File Not Found")	
	if(count==0):
		print("No Records Found")
def book_auth(auth):
	f=open("book.dat","rb")
	flag=0
	try:
		while True:
			records=pickle.load(f)
			if records[2]==auth:
				print("===================")
				print("      BOOK ",records[0])
				print("===================")
				print("Book Name : ",records[1])
				print("Author Name : ",records[2])
				print("Book Price : ",records[3])
				print("===================")
				flag=1
			if(flag==0):
				print("No record Found")

	except EOFError:
			pass
	except FileNotFoundError:
		print("File Not Found")

def book_price(max_price):
	f=open("book.dat","rb")
	flag=0
	try:
		while True:
			record=pickle.load(f)
			if record[3]<max_price:
				print(record)
				flag=1
			if(flag==0):
				print("No record Found")
	except EOFError:
			pass
	except FileNotFoundError:
		print("File Not Found")

def copy_book(price):
	count=0
	f=open("book.dat","rb")
	c=open("costly_book.dat","wb")
	try:
		while True:
			record=pickle.load(f)
			if(record[3]>price):
				pickle.dump(record,c)
				count=count+1
		print("Count =",count)
		
	except EOFError:
		pass
	f.close()
	c.close()
	if(count!=0):
		print("New File Data")
		f=open("costly_book.dat","rb")
		try:
			while(True):
				records=pickle.load(f)
				print("===================")
				print("      BOOK ",records[0])
				print("===================")
				print("Book Name : ",records[1])
				print("Author Name : ",records[2])
				print("Book Price : ",records[3])
				print("===================")
		except EOFError:
				pass


def del_rec(book_no):
	f=open("book.dat","rb")
	t=open("temp.dat","ab")	
	found=0
	try:
		while True:
			records=pickle.load(f)
			if(records[0]==book_no):
				found=1
				continue
			else:
				pickle.dump(records,t)

	except EOFError:
		pass
	except FileNotFoundError:
		print("File Not Found")
	if(found==1):
		os.remove("book.dat")
		os.rename("temp.dat","book.dat")
	else:
		print("No Records Found")
		os.remove("temp.dat")

def update_record(book_no):
	f=open("book.dat","rb")
	t=open("temp.dat","wb")	
	found=0
	try:
		while True:
			records=pickle.load(f)
			if(records[0]==book_no):
				found=1
				book_no=int(input("Enter the Book Number : "))
				book_name =input("Enter the name of the book : ")
				Author = input("Enter the Author name : ")
				Price = int(input("Enter the price of Book : "))
				arr = [book_no,book_name,Author,Price]
				pickle.dump(arr,t)
			else:
				pickle.dump(records,t)
		
	except EOFError:
		pass
	except FileNotFoundError:
		print("File Not Found")
	if(found==1):
		os.remove("book.dat")
		os.rename("temp.dat","book.dat")
	else:
		print("No Records Found")
		os.remove("temp.dat")

def main():
	while True:
		print("===============================")
		print("           MAIN MENU          ")
		print("===============================")
		print("1.ADD RECORD")
		print("2.DISPLAY RECORD")
		print("3.SEARCH BOOK USING AUTHOR NAME")
		print("4.SEARCH BOOKS BY MAXIMUM PRICE ")
		print("5.COPY BOOKS HAVING PRICE MORE\n  THAN A PRICE TO ANOTHER FILE")
		print("6.DELETE A BOOK")
		print("7.UPDATE BOOK DETAILS")
		print("8.EXIT")
		print("===============================")
		choice = int(input("Enter the Choice : "))
		if(choice==1):
			add_rec()
		elif(choice==2):
			disp_rec()
		elif(choice==3):
			auth = input("Enter the Name of the Author : ")
			book_auth(auth)	
		elif(choice==4):
			price = int(input("Enter the Maximum Price : "))
			book_price(price)
		elif(choice==5):
			price = int(input("Enter the Price : "))
			copy_book(price)
		elif(choice==6):
			no=int(input("Enter the Book Number"))
			del_rec(no)
		elif(choice==7):
			no=int(input("Enter the Book Number which you want to update"))
			update_record(no)	
		elif(choice==8):
			print("Exiting")
			break
		else:
			print("Invalid Choice")


main()
