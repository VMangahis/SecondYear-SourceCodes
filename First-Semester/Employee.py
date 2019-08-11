find = ""
getindex = 0
dictionary = {}

for i in range(0, 10):
    info = {}
    print("---------------------")
    print("Employee Input # " + str(i+1) + " of " + str(10))
    info[0] = (input("Input first name"))
    info[1] = (input("Input family name"))
    info[2] = (int(input("Input your age")))
    info[3] = (input("Input your gender"))
    info[4] = (int(input("Input ID Number")))
    dictionary[i] = info

print("Employee Records\n----------------------------")
print(dictionary)

# for ( int x = 0 ; x < 10 ; x++_


while find != 99:
    find = int(input("Input employee record number to display info (99 to Exit)"))
    if find == 99:
        break

    if find in dictionary:
        templist = dictionary.get(find)
        print("Employee Number: " + str(find))
        print("First Name : " + templist[0])
        print("Family Name: " + templist[1])
        print("Age: " + str(templist[2]))
        print("Gender: " + templist[3])
        print("Id Number: " + str(templist[4]))

    else:
        print("Employee not found")