from playwright.sync_api import sync_playwright
from bs4 import BeautifulSoup

url = "https://in.bookmyshow.com/explore/movies"

movie_name=[]

with sync_playwright() as p:

    browser = p.chromium.launch(headless=False)

    page = browser.new_page()

    page.goto(url, wait_until="domcontentloaded")

    page.wait_for_timeout(10000)

    html = page.content()

    soup = BeautifulSoup(html, "html.parser")

    elements = soup.select('a[href*="/movies/"]')

    for element in elements:
        title = element.find('h3')
        link = element.get('href')
        movie_name.append(title);
    browser.close()

for i in movie_name:
    if(i!=None):
     print(i.get_text(strip=True))