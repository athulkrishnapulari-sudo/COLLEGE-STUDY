import requests
from bs4 import BeautifulSoup
import re
from requests.exceptions import HTTPError
import pickle


def Scrape():
    details = []
    url="https://bookscape.com/"
    try:
        response = requests.get(url)
        if(response.status_code==200):
            print("Data Fetched Successfully")
    except HTTPError as http_err:
        print(f"HTTP error occurred: {http_err}")
    # print(response.content)
    soup  = BeautifulSoup(response.content,"html.parser")
    # print(soup)
    divs = soup.find_all('div',class_=['flex-1','min-w-[150px]'])
    for i in divs:
        name = i.find('div',class_='book_title_label')
        price = i.find('div',class_='offer_price')
        if(name!=None):
            # print(name.text)
            # print(price.text)
            price_digit = re.findall(r'[0-9]+',price.text)
            # print(price_digit[0])
            a={"Title":name.text,"Price":price_digit[0]}
            details.append(a)
    # print(details)
    return details

def Store(details):
    try:
        a=open('book.dat','wb')
        pickle.dump(details,a)
    except FileNotFoundError:
        print("File Not Found")
    except Exception as e:
        print("Error:",e)
    finally:
        print("data stored successfully")

def Display(details):
    try:
        a=open('book.dat','rb')
        data=pickle.load(a)
        for book in data:
                print("-" * 60)
                print(f"Title : {book['Title']}")
                print(f"Price : ₹{book['Price']}")
        print("-" * 60)
    except FileNotFoundError:
        print("File Not Found")
    except Exception as e:
        print("Error:",e)

details=Scrape()
Store(details)
Display(details)

