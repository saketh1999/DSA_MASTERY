class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        def nextGreatestNumber(arr):
            res = []
            stack = []
            n=len(arr)

            for i in range(n-1,-1,-1):

                if not stack:
                    res.append(-1)
                
                elif len(stack)!=0 and stack[-1] > arr[i]:
                    res.append(stack[-1])
                
                elif len(stack)!=0 and stack[-1] <= arr[i]:
                    while len(stack)!=0 and stack[-1] <= arr[i]:
                        stack.pop(-1)
                    
                    if len(stack)==0:
                        res.append(-1)
                    else:
                        res.append(stack[-1])
                stack.append(arr[i])

            return res[::-1]

        res =[]
        nge = nextGreatestNumber(nums2)
        print(nge)
        myDict = {}
        for i in range(len(nums2)):
            myDict[nums2[i]] = nge[i]
        
        for i in range(len(nums1)):
            res.append(myDict[nums1[i]])
        
        return res
