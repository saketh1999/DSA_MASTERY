class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        #using binary search

        #first sort the array
        arr.sort()

        curr=0
        
        while curr<len(arr):
            left,right=0,len(arr)-1
            
            target = 2*arr[curr]
        
            while left<=right:
                mid = (left+right)//2

                if arr[mid]==target and curr!=mid:
                    return True
                
                elif arr[mid]>target:
                    right=mid-1
                else:
                    left=mid+1

            curr+=1
        return False
            
