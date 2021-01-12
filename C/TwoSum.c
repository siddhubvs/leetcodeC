#define HASH_SIZE 500000
int hash_func(int v){
    int index = (v) %HASH_SIZE;
    return index< 0? index+HASH_SIZE: index; 
}

void insert(int *hash_table, int key, int value){   
    hash_table[hash_func(key)] = value;
}

int find(int *hash_table, int key){
    return hash_table[hash_func(key)];
}

int res[2];
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int hash[HASH_SIZE + 1 ] = {0};
    for(int i =0; i <numsSize; ++i){
        int found =find(hash, target - nums[i]);
        if (found){
            res[0] = i;
            res[1] = found -1;
            return res;
        }
        insert(hash, nums[i], i+1);
    } 
    return res;
}
