#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target) {
    //False
    //int ans[2];
    //OK
    static int ans[2];
    for(int i = 0; i < numsSize; i++)
    {       
        for(int j = i+1; j <numsSize; j++)
        {
            if(nums[i] == target - nums[j])
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
    //return &ans;
    
    // Q1　why int* 做function               Ans: 因為要傳array 所以要用指針 pointer
    // Q2  why return 有沒有 & 沒差 ?
    // Q3  why 一定要 static int ? 
/*  http://archerworks.blogspot.com/2010/07/cstatic.html
C語言static有兩個目的
1.static storage （靜態存儲）：變數儲存空間為static storage而非function stack，使變數生命週期與程式相同。
2.internal linkage（內部連結）：限制變數可視範圍於檔案內。（聽說這是後來加的，為了減少保留字的使用所以也用static）

當你使用static修飾字...
已經有內部連結特性的(區域變數)就加上靜態存儲特性。
已經有靜態存儲特性的(全域變數和函式)就加上內部連結特性。

C++則多了一種修飾對象 "成員"
然而用static將成員修飾為類別成員仍然無法獲得內部連結特性，所以需要配合private跟protected額外的做存取範圍的限制。
*/
    
}

int main(void) {
	int nums[4] = {2, 7, 11, 15};
	int target = 9;
	int numsSize = 4;
	int* ans_out;
	ans_out = twoSum( nums, numsSize, target);
	printf("hello C two sum %d, %d \n", ans_out[0],ans_out[1]);

	return 0;
}
