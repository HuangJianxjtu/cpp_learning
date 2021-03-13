class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        length = len(nums)
        res = []
        def permute_dfs(numset, checked, deepth):
            if deepth == length:
                res.append(checked[:])
                return
            for i in range(length):
                if numset[i] not in checked:
                    checked.append(numset[i])
                    permute_dfs(numset, checked, deepth+1)
                    checked.pop()

        permute_dfs(nums , [] , 0)
        return res


input_nums = [1, 2, 3]

s = Solution()
s.permute(input_nums)
print(s)

