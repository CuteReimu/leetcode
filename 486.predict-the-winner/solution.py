class Solution:
    def __init__(self):
        self.dict = {}

    def PredictTheWinner(self, nums: List[int]) -> bool:
        a, b = self.PredictTheWinner2(nums, 0, len(nums) - 1, 1)
        return a >= b

    def PredictTheWinner2(self, nums: List[int], i: int, j: int, turn: int) -> (int, int):
        if i == j:
            return (nums[i], 0) if turn == 1 else (0, nums[i])
        result = self.dict.get((i, j, turn))
        if result is not None:
            return result
        a1, b1 = self.PredictTheWinner2(nums, i + 1, j, 3 - turn)
        a2, b2 = self.PredictTheWinner2(nums, i, j - 1, 3 - turn)
        if turn == 1:
            if a1 + nums[i] - b1 >= a2 + nums[j] - b2:
                self.dict[(i, j, turn)] = (a1 + nums[i], b1)
            else:
                self.dict[(i, j, turn)] = (a2 + nums[j], b2)
        else:
            if b1 + nums[i] - a1 >= b2 + nums[j] - a2:
                self.dict[(i, j, turn)] = (a1, b1 + nums[i])
            else:
                self.dict[(i, j, turn)] = (a2, b2 + nums[j])
        return self.dict[(i, j, turn)]
