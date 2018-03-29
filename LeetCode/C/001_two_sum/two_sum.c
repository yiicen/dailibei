/*
Given an array of integers, return indices of the two numbers
such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <stdlib.h>

struct Object {
    int val;
    int index;
};

static int Compare(const void *a, const void *b) {
    return ((struct Object *)a)->val - ((struct Object *)b)->val;
}

extern int *TwoSum(int *nums, int nums_size, int target) {
    int i, j;
    struct Object *objs = malloc(nums_size * sizeof(struct Object));
    for (i = 0; i != nums_size; ++i) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    qsort(objs, nums_size, sizeof(struct Object), Compare);

    int count = 0;
    int *results = malloc(2 * sizeof(int));
    i = 0;
    j = nums_size - 1;
    while (i < j) {
        int diff = target - objs[i].val;
        if (diff > objs[j].val) {
            while (++i < j && objs[i].val == objs[i-1].val) {
            }
        } else if (diff < objs[j].val) {
            while (--j > i && objs[j].val == objs[j+1].val) {
            }
        } else {
            results[0] = objs[i].index;
            results[1] = objs[j].index;
            return results;
        }
    }

    return NULL;
}
