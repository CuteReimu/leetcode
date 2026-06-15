function twoSum(nums: number[], target: number): number[] {
  const s = new Map<number, number>();
  for (let i = 0; i < nums.length; i++) {
    const index2 = s.get(target - nums[i]);
    if (index2 !== undefined) {
      return [index2, i];
    }
    s.set(nums[i], i);
  }
  return [];
};