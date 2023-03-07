from typing import List

def binary_search(arr: List[int], target: int) -> int:
    # WRITE YOUR BRILLIANT CODE HERE
    left=arr[0]
    right=arr[-1]
    mid=len(arr)//2 #get average position of list
    while(left <= right):
        mid= (left + right)//2
        if (arr[mid]==target):
            return mid
        if(arr[mid] > target):
            left=mid+1
        else:
            right= mid-1
    return -1 #we didnt find the target
