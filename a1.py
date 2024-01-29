#In second year computer engineering class, group A student’s
# play cricket, group B students play badminton and group C
# students play football. Write a Python program using functions
# to compute following:
# a) List of students who play both cricket and badminton
# b) List of students who play either cricket or badminton but not both
# c) Number of students who play neither cricket nor badminton
# d) Number of students who play cricket and football but not badminton.

def union(lst1,lst2):
    lst3 = lst1.copy()
    for var in lst2:
        if var not in lst3:
            lst3.append(var)
    return lst3

def intersection(lst1,lst2):
    lst3 = []
    for i in lst1:
        if i in lst2:
            lst3.append(i)
    return lst3

def diff(lst1,lst2):
    lst3 = []
    for val in lst1:
        if val not in lst2:
            lst3.append(val)
    return lst3

def sym_diff(lst1,lst2):
    lst3 = []
    d1 = diff(lst1,lst2)
    d2 = diff(lst2,lst1)
    lst3 = union(d1,d2)
    return lst3

cricket = []
badminton = []
football = []
print("---------------------  STUDENT SPORT INFO  -----------------------")
n = int(input("\n\nEnter number ofstudents who play cricket : "))
print("Enter the names of",n,"students who play cricket (Please press ENTER after entering each students name) :")
for i in range(n):
    a = input(" -->")
    cricket.append(a)

m = int(input("\n\nEnter number ofstudents who play badminton : "))
print("Enter the names of",m,"students who play badminton (Please press ENTER after entering each students name) :")
for i in range(m):
    a = input(" -->")
    badminton.append(a)

o = int(input("\n\nEnter number ofstudents who play football : "))
print("Enter the names of",o,"students who play football (Please press ENTER after entering each students name) :")
for i in range(o):
    a = input(" -->")
    football.append(a)

# a) List of students who play both cricket and badminton
print("List of students who play both cricket and badminton is ",intersection(cricket,badminton))

# b) List of students who play either cricket or badminton but not both
print("List of students who play either cricket or badminton but not both is ",sym_diff(cricket,badminton))

# c) Number of students who play neither cricket nor badminton
print("Number of students who play neither cricket nor badminton is ",diff(football,union(cricket,badminton)))

# d) Number of students who play cricket and football but not badminton.
print("Number of students who play cricket and football but not badminton is ",diff(union(cricket,football),badminton))
