#Insertion Sort
'''
Worst case complexity o(n^2)
Best case complexity o(n)
'''
def insertionSort(arr):
    for i in range(1,len(arr)):
        key=arr[i]
        j=i-1
        while j>=0 and arr[j]>key:
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key    

def display(arr):
    print(arr)

arr=[]
n= int(input("Enter the number of element in an array :"))
for i in range(n):
    value=int(input(f"Enter the element at index {i+1} : "))
    arr.append(value)
print(arr)  
print("Sorted array")
insertionSort(arr)
display(arr)

