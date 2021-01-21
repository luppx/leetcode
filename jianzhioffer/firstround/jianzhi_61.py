class Solution(object):
    def max_heapify(self, heap, root, heap_len):
        p = root
        while p * 2 + 1 < heap_len:
            l, r = p * 2 + 1, p * 2 + 2
            if heap_len <= r or heap[r] < heap[l]:
                nex = l
            else:
                nex = r
            if heap[p] < heap[nex]:
                heap[p], heap[nex] = heap[nex], heap[p]
                p = nex
            else:
                break

    def build_heap(self, heap):
        for i in range(len(heap) - 1, -1, -1):
            self.max_heapify(heap, i, len(heap))

    def heap_sort(self, nums):
        self.build_heap(nums)
        for i in range(len(nums) - 1, -1, -1):
            nums[i], nums[0] = nums[0], nums[i]
            self.max_heapify(nums, 0, i)
        return nums

    def isStraight(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums_sorted = self.heap_sort(nums)
        idx = 0
        for i in range(0, 4):
            if nums_sorted[i] == 0:
                idx += 1
            elif nums_sorted[i] == nums_sorted[i+1]:
                return False
        if nums_sorted[4] - nums[idx] < 5:
            return True
        else:
            return False


if __name__ == '__main__':
    nums = [4,10,4,0,9]
    obj = Solution()
    result = obj.isStraight(nums)
    print(result)
