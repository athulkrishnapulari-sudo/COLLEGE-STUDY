import requests

url = 'https://www.google.com'

response = requests.get(url)

print(f"Status Code : {response.status_code}")

print(f"Data : {response.content}")

