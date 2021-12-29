'''
Shell sort 
best case complexity= O(n)
worst case complexity=O(n^2)
average complexity=O(nlogn)
'''

def shellSort(arr):
    gap=len(arr)//2

    while gap>0:
        i=0
        j=gap
        while j<len(arr):
            if arr[i]>arr[j]:
                arr[i],arr[j]=arr[j],arr[i]
            i+=1
            j+=1
            k=i
            while k-gap>-1:
                if arr[k-gap]>arr[k]:
                    arr[k-gap],arr[k]=arr[k],arr[k-gap]
                k-=1
        gap=gap//2

def display():
   print(arr)


arr=[]
n=int(input("Enter the number of elements in the array :"))

for i in range (n):
    value=int(input(f"Enter the element at index {i+1}: "))        
    arr.append(value) 
print(arr)
print("Sorted array")
shellSort(arr)
display()

