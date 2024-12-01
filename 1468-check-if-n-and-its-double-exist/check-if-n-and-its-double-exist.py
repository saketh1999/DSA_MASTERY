class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        #using binary search

        #first sort the array
        arr.sort()
        elements_so_far =[]
        curr=0
        
        while curr<len(arr):
            left,right=curr+1,len(arr)-1
            
            target = 2*arr[curr]
            if target in elements_so_far:
                return True
            while left<=right:
                mid = (left+right)//2

                if arr[mid]==target:
                    return True
                
                elif arr[mid]>target:
                    right=mid-1
                else:
                    left=mid+1
            elements_so_far.append(arr[curr])
            curr+=1
        return False
            
