class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i1 = m-1; i2 = n-1
        for i in range((m+n-1), -1, -1):
            print("i:",i,"i1:",i1,"i2:",i2, end='\t')
            if i1 < 0 and i2 < 0:
                print("Both are low")
                break
            if i1 < 0:
                nums1[i] = nums2[i2]
                i2 -= 1
                print("i1 is low")
                continue
            if i2 < 0:
                nums1[i] = nums1[i1]
                i1 -= 1
                print("i2 is low")
                continue
            element1 = nums1[i1]; element2 = nums2[i2]
            if element1 > element2:
                print("e1>e2")
                nums1[i] = nums1[i1]
                i1 -= 1
            else:
                print("e1<=e2")
                nums1[i] = nums2[i2]
                i2 -= 1