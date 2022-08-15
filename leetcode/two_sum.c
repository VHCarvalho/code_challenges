#include <stdlib.h>

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int j;
    int *ret;
    
    i = 0;
    j = 0;
    *returnSize = 2;
    ret = (int *)malloc(sizeof(int) * 2);
   while(i < numsSize)
    {
        j = i + 1;
        while(j < numsSize)
        {
            if(nums[i] + nums[j] == target)
            {
                ret[0] = i;
                ret[1] = j;
                return (ret);
            }
            j++;
        }
        i++;
    }
    return (ret);   
}
