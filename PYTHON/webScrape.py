# Response--

import requests

url = 'https://athulkrishnapulari-sudo.github.io/PORTFOLIO-2'

response = requests.get(url)

content = response.content

# To Parse this content 

from bs4 import BeautifulSoup

parsed_content = BeautifulSoup(content,'html.parser')

#print the parsed content

print(parsed_content)

#print the parsed content more prettier

print(parsed_content.prettify())

#Getting the title tag

print(parsed_content.title)

#Getting the span tag

print(parsed_content.span)

# to get the tag name of a tag

print(parsed_content.title.name)

#to get the tag name of a tags parent ------ and use the child attribute to get the tag name of child of that tag

print(parsed_content.title.parent.name)

# Loop through direct children of the body tag
for child in parsed_content.body.children:
    # Check if it's a tag (ignoring raw text/whitespace strings)
    if child.name:
        print(child.name)

#To find elements


# =======Direct Tag Access=========

# If you know the specific child tag you are looking for, you can access it directly by name or use .find() / .find_all():


# Get the name of a specific child tag inside an element

print(parsed_content.body.div.name)

# using find

print(parsed_content.find('div')) #fint the first occurance

print(parsed_content.find_all('div')) #find all occurance

# select a tag with respect to class 

print(parsed_content.find('div',class_='resume-item')) 
print(parsed_content.find_all('div',class_='resume-item'))

# select tag with class only

print(parsed_content.find(class_='resume-item'))
print(parsed_content.find_all(class_='resume-item'))

# Using class_ with a string (matches exact class string)
element = parsed_content.find(class_='sidebar active')

# Or using CSS selector via .select_one() for the first match, or .select() for all
first_match = parsed_content.select_one('.sidebar.active')

# finding element by id
print(parsed_content.find('section', id= 'hero'))

# .text to extract the text only without the tags

print("==============lines============")

lines = parsed_content.find_all('p')
print(lines)
for line in lines:
    print(line.text)