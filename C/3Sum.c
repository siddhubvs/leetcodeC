int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 3) 
        return NULL;
    int i, high, low, sum;
    int** result = (int**)malloc(sizeof(int)*numsSize*(numsSize-1)/2);
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    for (i = 0; nums[i] <= 0 && i < numsSize-2;)
    {
        low = i + 1;
        high = numsSize - 1;
        while (low < high)
        {
            sum = nums[low] + nums[high] + nums[i];
            if (sum > 0)
                high--;
            else if (sum < 0)
                low++;
            else
            {
                *returnSize += 1;
                result[*returnSize-1] = (int*)malloc(sizeof(int)*3);
                result[*returnSize-1][0] = nums[i];
                result[*returnSize-1][1] = nums[low];
                result[*returnSize-1][2] = nums[high];
                
                do high--; while (nums[high]==nums[high+1] && low < high);
            }
        }
       
        do i++; while (nums[i]==nums[i-1] && i < numsSize-2);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = 3;
    return result;
}
