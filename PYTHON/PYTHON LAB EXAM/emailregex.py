import re

email = 'athulkrishnapulari@gmail.com'

pattern = r"[a-zA-Z0-9]+@[a-zA-Z]+\.(com|edu|net)"

if re.search(pattern,email):
    print("Valid email")

else:
    print("invalid")