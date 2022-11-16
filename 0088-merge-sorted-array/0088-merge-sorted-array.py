class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        print(m, n)
        _num = nums1[:m+1]
        i = 0
        j = 0 # first arr index
        k = 0 # second arr index
        while i < m + n:
            if j < m and k < n and _num[j] <= nums2[k]:
                nums1[i] = _num[j]
                i += 1
                j += 1
            elif j < m and k < n and _num[j] > nums2[k]:
                nums1[i] = nums2[k]
                i += 1
                k += 1
            elif j < m and k >= n:
                nums1[i] = _num[j]
                i += 1
                j += 1
            elif k < n and j >= m:
                nums1[i] = nums2[k]
                i += 1
                k += 1