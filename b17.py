# Write a Python program to store 12th class percentage of students in array. Write function for sorting array of floating point numbers 
# in ascending order using bucket sort and display top five scores

    
def selsort(a):               #selection sort
    l = len(a)
    for i in range(l):
        m = i           #i not t be lose so m=i
        for j in range(i+1, l):
            if(a[j]<a[m]):
                m=j
        if(m!=i):           # if swaped positions do this, in above position
            a[i], a[m] = a[m], a[i]
    return a  

def bucketsort(a):
    bucket = []
    for _ in range(10):             # _ used for only purpose of that amny times
        bucket.append([])           #making 10 buckets in main bucket          
    l = len(a)
    for i in range(l):          
        b_i = int(a[i]*10) #bucket index        number will go in the respective bucket with that index
        bucket[b_i].append(a[i])    #will append the elemnt of a the arey to its respective index of bucket 's []
    a=[] #overwritting list                     now there is need to sort the the bucket's [] if they have two or more element in it 
    for j in bucket:
        j = selsort(j) #sorting individual [] (this is the inside bucket of the main bucket)using selection sort
        a+=j            #appending the sorted arrey one after another which finally gives us the output result
    return a


n = int(input("Enter no of students in first year: "))
lst = []
for i in range(n):
    print("Student", i+1, end = "")
    pt = float(input(", Enter percentage obtained(Eg. 98% = 0.98): "))          #pt refers percentage variable 
    lst.append(pt)


result = bucketsort(lst)
print("the list after sorting is :")
print(result)

print("\nTop 5 Scores are, ")
c=0
for _ in result[::-1]:          #as the elements are in assending order in the arrey result so we need to print it in a reverse manner to get its top 5
    if(c==5):
        break
    else:
        c+=1        # counting how many element done ones it reaches 5 if condition gets satisfied and breakes
        print(_, end = " ")     # printing the result


# for _ in result[::-1] means , for elements in result each one by one stored in _ arnd the operation is done
#for _ in result[::-1] were _ is he element of the arrey