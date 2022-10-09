import sys
# response = "something: "
response = ""
for line in sys.stdin: # get input strings one by one
    # do something

    new_list = line.split()
    for l in new_list:

    response = response + line
print(response) # print the answer to stdout