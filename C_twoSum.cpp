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
    
    // Q1�@why int* ��function               Ans: �]���n��array �ҥH�n�Ϋ��w pointer
    // Q2  why return ���S�� & �S�t ?
    // Q3  why �@�w�n static int ? 
/*  http://archerworks.blogspot.com/2010/07/cstatic.html
C�y��static����ӥت�
1.static storage �]�R�A�s�x�^�G�ܼ��x�s�Ŷ���static storage�ӫDfunction stack�A���ܼƥͩR�g���P�{���ۦP�C
2.internal linkage�]�����s���^�G�����ܼƥi���d����ɮפ��C�]ť���o�O��ӥ[���A���F��֫O�d�r���ϥΩҥH�]��static�^

��A�ϥ�static�׹��r...
�w�g�������s���S�ʪ�(�ϰ��ܼ�)�N�[�W�R�A�s�x�S�ʡC
�w�g���R�A�s�x�S�ʪ�(�����ܼƩM�禡)�N�[�W�����s���S�ʡC

C++�h�h�F�@�ح׹���H "����"
�M�ӥ�static�N�����׹������O�������M�L�k��o�����s���S�ʡA�ҥH�ݭn�t�Xprivate��protected�B�~�����s���d�򪺭���C
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
