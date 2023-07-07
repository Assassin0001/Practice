# # WebScraping Basics

#Step0: Setting Up Environment
# Import requests library for fetching content 
import requests
from bs4 import BeautifulSoup
url = "https://www.codewithharry.com/"

# Step1: Get the HTML
r = requests.get(url)
htmlContent = r.content

# Step2: Parse the HTML
soup = BeautifulSoup(htmlContent, 'html.parser')
# print(soup.prettify)

# Step3: HTML Tree Traversal
# Type of Objects

# 1. BeautifulSoup print(type(soup))
# 2. Element print(type(title)) 
# 3. Navigable String print(type(title.string))
# 4. Comment | Example below :- 

# markup = "<p><!--This is a comment --></p>"
# soup2 = BeautifulSoup(markup)
# print(type(soup2.p.string))

# To exit program ->exit()

# Get the title of HTML Page
title = soup.title

# Get all paragraphs from page
paras = soup.find_all('p')
#print(paras)

# Get first element in HTML page
print(soup.find('p'))
 
# Get classes of any element in the HTML page
print(soup.find('p')['class'])

# Find all elements with class lead
print(soup.find_all('p',class_="lead"))

# Get the text from the tags/soup
print(soup.find('p').get_text())

# Get all anchor tags from page
anchors = soup.find_all('a')
all_links = set()
# Get all the links on page
for link in anchors:
    if(link != '#'): 
        linkText = ("https://codewithharry.com" + link.get('href'))
        all_links.add(link)
        print(linkText)

# Find tags with ID
navBarSupportedContent = soup.find(id='navBarSupportedContent')

# Parent, children, contents, strings/stripped_strings, next_sibling, previous_sibling
# .contents - A tag's contents are available as list 
# .children - A tag's children ar available as generator , faster

for elem in navBarSupportedContent.contents:
   print(elem)

# stripped_strings remove trailing spaces and formats string
# string doesnt format content.

for item in navBarSupportedContent.stripped_strings:
   print(item)

# Parent

# Single parent - print(navBarSupportedContent.parent)
#  List all parents - 
for item in navBarSupportedContent.parents:
    print(item.name)

# Siblings - next and previous
print(navBarSupportedContent.next_sibling)
print(navBarSupportedContent.previous_sibling)

# CSS Selector
elem = soup.select('#loginModal')
print(elem)


