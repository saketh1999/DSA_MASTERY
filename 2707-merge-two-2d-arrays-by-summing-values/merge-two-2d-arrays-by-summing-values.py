class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        ptr1,ptr2=0,0
        res = []

        while ptr1<len(nums1) and ptr2<len(nums2):
            id1,v1 = nums1[ptr1]
            id2,v2 = nums2[ptr2]

            if id1==id2:
                res.append([id1,v1+v2])
                ptr1+=1
                ptr2+=1
            
            elif id1<id2:
                res.append([id1,v1])
                ptr1+=1
            else:
                res.append([id2,v2])
                ptr2+=1
        
        while ptr1<len(nums1):
            id,v = nums1[ptr1]
            res.append([id,v])
            ptr1+=1
        
        while ptr2 < len(nums2):
            id,v = nums2[ptr2]
            res.append([id,v])
            ptr2+=1
        

        return res
