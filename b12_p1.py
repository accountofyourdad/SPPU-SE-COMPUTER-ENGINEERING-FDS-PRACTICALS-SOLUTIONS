def binary_search_recursive(phonebook,name, left, right):
    phonebook.sort()        #sort works absolutely  fine
    if left > right:
        return None
    mid = (left + right) // 2
    if phonebook[mid][0] == name:
        return phonebook[mid]
    elif phonebook[mid][0] > name:
        return binary_search_recursive(phonebook, name, left, mid - 1)
    else:
        return binary_search_recursive(phonebook, name, mid + 1, right)

def binary_search_non_recursive(phonebook, name):
    phonebook.sort()
    left, right = 0, len(phonebook) - 1
    while left <= right:
        mid = (left + right) // 2
        if phonebook[mid][0] == name:
            return phonebook[mid]
        elif phonebook[mid][0] > name:
            right = mid - 1
        else:
            left = mid + 1
        return None


def fibsearch(list_of_names, item):
    list_of_names.sort()
    length = len(list_of_names)
    f0 = 0
    f1 = 1
    f2 = 1
    while(f2<length):
        f0 = f1             # we are geting fibonaci series until f2<length
        f1 = f2
        f2 = f0 + f1
        
    offset = -1
    while(f2>0):
        index = min(offset + f0, length-1)          #decrementing the length by one every loop
        if(item == list_of_names[index]):           # sees if finding element at index = min(offset +f0, length -1)
            return list_of_names[index]
        elif(item > list_of_names[index]):
            f2 = f1     #                   ----|---> above we transverse left to right until f2<length
            f1 = f0     #                       0   1   1   2   3   5   ...
            f0 = f2 - f1#          here we do right to left <-------|--- reverse of what we do above
            offset = index 
        else:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
    return None

def insertnewperson(phonebook,name,n):
    newsmallbook = [name , n]       #make a small arrey than insert it in the bigger on 
    left = 0
    phonebook.insert(left,newsmallbook)         #alway remember insert takes two arguments first index and other as value at that index
    left +=1
    print("inserted successfully !!")
    phonebook.sort()
    print(phonebook)

def main():
    phonebook = [["bob", "9876543210"],["alice",     "1234567890"],  ["charlie", "5678901234"]]
    while True:
        print("\nOptions:")
        print("1. Search for a friend (Binar Search - Recursive)")
        print("2. Search for a friend (Binary Search - Non-Recursive)")
        print("3. Search for a friend (fibonaci Search)")
        print("4. Quit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            name = input("Enter the name to search for: ")
            result =binary_search_recursive(phonebook,name, 0, len(phonebook) - 1)
            if result:
                print(f" {result[0]}'s number is : {result[1]}.")
            else:
                print(f"{name} not found in the phonebook.")
                n=(input(f"enter {name}'s mobile no : "))
                insertnewperson(phonebook,name,n)

        elif choice == 2:
            name = input("Enter the name to search for: ")
            result =binary_search_non_recursive(phonebook, name)
            if result:
                print(f"{result[0]}'s number is{result[1]}.")
            else:
                print(f"{name} not found in the phonebook.")
                n=(input(f"enter {name}'s mobile no to add him in the phonebook : "))
                insertnewperson(phonebook,name,n)
        
        elif choice == 3:
            name = input("Enter the name to search for: ")
            result = fibsearch(phonebook, name)
            if result:
                print(f"{result[0]}'s number is{result[1]}.")
            else:
                print(f"{name} not found in the phonebook.")
                n=(input(f"enter {name}'s mobile no to add him in the phonebook : "))
                insertnewperson(phonebook,name,n)
        elif choice == 4:
            break
        else:
            print("Invalid choice. Please enter a valid option.")
if __name__ == "__main__":
    main()
