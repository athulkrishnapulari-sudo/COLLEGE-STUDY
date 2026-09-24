import requests
from bs4 import BeautifulSoup 

url  = 'https://athulkrishnapulari-sudo.github.io/PORTFOLIO-2'

try:
    response = requests.get(url)
    if(response.status_code==200):
        soup = BeautifulSoup(response.text,'html.parser')
        para = soup.find_all('p')
        for i in para:
            print(i.text)
    else:
        print("Error")

except Exception as e:
    print(f'Error : {e}')