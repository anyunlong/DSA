void reverse(int *nums, int numSize) {
    if (nums == NULL || numSize < 2) {
        return;
    }
    // numSize 最小是 2
    int maxIndex = numSize / 2;
    for (int index = 0; index < maxIndex; ++index) {
        int secondIndex = numSize - index - 1;
        int temp = nums[index];
        nums[index] = nums[secondIndex];
        nums[secondIndex] = temp;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (nums == NULL || numsSize < 2 || k < 0) {
        return;
    }
    reverse(nums, numsSize);
    int moveCount = k % numsSize;
    reverse(nums, moveCount);
    reverse(&nums[moveCount], numsSize - moveCount);
}
