
#selection sort

def selsort(a):
    l = len(a)
    for i in range(l):
        m = i
        for j in range(i+1, l):
            if(a[j]<a[m]):
                m=j
        if(m!=i):
            a[i], a[m] = a[m], a[i]     #swaping with original i.e         note that here it is i not j
    return a

#bubble sort
    
def bubblesort(a):
    l = len(a)
    for i in range(l):
        flag = 0
        for j in range(l-1):            # here in bubble sort it compares with the next element who is bigger and the bigest gets shifted accordingly to the right 
            if(a[j]>a[j+1]):        # as bubble with every for loop(j) and new bubble in every main for loop (i)
                a[j], a[j+1] = a[j+1], a[j]
                flag = 1
        if(flag==0):                # this means that the list is sorted
            break
    return a


n = int(input("Enter no of students in first year: "))
lst = []
for i in range(n):
    print("Student", i+1, end = "")
    pt = float(input(", Enter percentage obtained: "))
    lst.append(pt)
print()

print("Sorted score of the students using selection sort , ")
print(selsort(lst))
print()
result = bubblesort(lst)
print("Sorted score of the students using bubblesort , ")
print(result)

print("\nTop 5 Scores are, ")
c=0
for _ in result[::-1]:          # -1 as the elements are assendingly sorted so to be printed reversely
    if(c==5):
        break
    else:
        c+=1
        print(_, end = " ")         #end = " " so that next next not to be in the next line but in the same line