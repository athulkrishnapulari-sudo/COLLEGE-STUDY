import sqlite3
import re

con = sqlite3.connect('customer.db')

cur = con.cursor()

# create Table if not exists 

cur.execute('CREATE TABLE IF NOT EXISTS Customer (CustomerID TEXT NOT NULL , CustomerName TEXT NOT NULL , Email TEXT NOT NULL , ProductPurchased TEXT NOT NULL,Price INT NOT NULL)')


def Add_Record():
    cid = input("Enter Customer Id : ")
    if not re.match('[C][0-9]+',cid):
        print("Customer Id Should Start with 'C' followed by Number")
        return
    cName = input("Enter the Customer Name : ")
    mail = input("Enter the mail ID : ")
    if not re.match(r'^[a-zA-z0-9._%+-]+@(gmail|yahoo|outlook|hotmail)\.(com|in)$',mail):
        print("Invalid Email")
        return
    product = input("Enter the Product : ")
    price = int(input("Enter the Price : "))
    cur.execute('INSERT INTO Customer (CustomerID,CustomerName,Email,ProductPurchased,Price) VALUES(?,?,?,?,?)',(cid,cName,mail,product,price))
    con.commit()
    print("Record Added Successfully!!!")


def Cust_By_Price(Price):
    cur.execute("SELECT * FROM Customer")
    data = cur.fetchall()
    print("\n========== CUSTOMERS DETAILS ==========")
    for i in data:
        if(i[4]<Price):
            print(f"Customer ID: {i[0]} | Name: {i[1]} | Email: {i[2]} | Product: {i[3]} | Price: {i[4]}")


def Cust_By_Product(product):
    cur.execute("SELECT * FROM Customer")
    data = cur.fetchall()
    print("\n========== CUSTOMERS DETAILS ==========")
    for i in data:
        if(i[3]==product):
            print(f"Customer ID: {i[0]} | Name: {i[1]} | Email: {i[2]} | Product: {i[3]} | Price: {i[4]}")

def DeleteRecord():
    cid = input("Enter the Customer Id of the Record Which you want to delete : ")
    if not re.match('[C][0-9]+',cid):
        print("Customer Id Should Start with 'C' followed by Number")
        return
    cur.execute("DELETE FROM Customer WHERE CustomerID = ?",(cid,))
    con.commit()
    if cur.rowcount > 0:
        print("Customer Deleted Successfully")
    else:
        print("Customer ID Not Found")

def Update(cid):
    product = input("Enter the New Product : ")
    mail = input("Enter the New mail ID : ")
    if not re.fullmatch(r'^[a-zA-z0-9._%+-]+@(gmail|yahoo|outlook|hotmail)\.(com|in)$',mail):
        print("Invalid Email")
        return
    price = int(input("Enter the new Price : "))
    cur.execute("UPDATE Customer Set ProductPurchased = ?,Price = ?,Email = ? WHERE CustomerID = ?",(product,price,mail,cid))
    con.commit()
    if cur.rowcount>0:
        print("Customer Updated Successfully")
    else:
        print("Customer ID Not Found")


# Cust_By_Price(1000)
# Cust_By_Product('Umberlla')
# Add_Record()
# DeleteRecord()
Update('C01')
