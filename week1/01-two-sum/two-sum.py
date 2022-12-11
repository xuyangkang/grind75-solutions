class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        last_seen = {v:k for k, v in enumerate(nums)}
        for i, num in enumerate(nums):
            maybe_j = last_seen.get(target - num)
            if maybe_j and maybe_j != i:
                return [i, maybe_j]
