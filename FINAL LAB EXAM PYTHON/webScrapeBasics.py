from bs4 import BeautifulSoup

file = open('index.html','r');
data=file.read()
print(data);

soup = BeautifulSoup(data,'html.parser');
div=soup.select("div");
for i in div:
    print(i.text)


# editing content 


data_part = data.split('<body>');
print(data_part)

new = "<body>\n    <h1>Hi I Am Athul krishna</h1>\n    <h2>This is a Sample Webpage</h2>\n</body>"

newdata=""
newdata+=data_part[0]
newdata+=new
newdata+=data_part[1].split('</body>')[1]

print(newdata)

file = open('index.html','w');

file.write(newdata)