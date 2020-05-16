//Problem 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int path[100][100] = { 0 }; //path[i][j]��0���i, j���I�������q�A��1��ܦ��@����
float How_Long_Cnt[120] = { 0.0 }; //�O���U�ظ��|���ץX�{�L������
float How_Much_Mid_Cnt[120] = { 0.0 }; //�O���U�ظ��|���׸g�Lmid������
int stack[120], m = 1, start, end, mid, con = 0;
float total_path_cnt = 0.0, meet_mid_cnt = 0.0;

void dfs(int p)
{
	int i, j;
	for (i = 1; i <= 100; i++)
	{
		int re_find = 0;
		for (int k = 0; k < m; k++)
		{
			if (stack[k] == i)
			{
				re_find = 1;
				break;
			}
		}
		if (path[p][i] == 1 && re_find == 0)
		{
			if (i == end)//�p�G�`�j��F���I�A�N��X��~�g�L�����|
			{
				for (j = 0; j < m; j++)
				{
					printf("%-5d", stack[j]);
					if (stack[j] == mid)
					{
						if (con == 0)
							How_Much_Mid_Cnt[m] = How_Much_Mid_Cnt[m] + 1.0;
						con = 1;
					}
				}
				printf("%-5d\n", end);
				How_Long_Cnt[m] = How_Long_Cnt[m] + 1.0;
				con = 0;
			}
			else//�p�G���I���O���I
			{
				stack[m] = i;//�N���I�s�_��
				m++;
				dfs(i);//���۲`�j
				m--;
			}
		}
	}
}

int main()
{
	int i, j, size, buffer;
	scanf("%d,%d,%d,%d", &size, &start, &end, &mid);
	if (start > end)
	{
		int start_temp = start;
		start = end;
		end = start_temp;
	}
	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size; j++)
		{
			scanf(" %d", &buffer);
			if (buffer == 1)
			{
				path[i][j] = 1;
			}
		}
	}
	stack[0] = start;
	dfs(start);
	for (i = 0; i < 120; i++)
	{
		if (How_Long_Cnt[i] > 0.0)
			break;
	}
	if (How_Long_Cnt[i] != 0.0)
	{
		printf("How_Long_Cnt[%d] = %f\n", i, How_Long_Cnt[i]);
		printf("How_Much_Mid_Cnt[%d] = %f\n", i, How_Much_Mid_Cnt[i]);
		if (start == mid || end == mid)
			printf("1.000\n");
		else
			printf("%.3f\n", How_Much_Mid_Cnt[i] / How_Long_Cnt[i]);
	}
	else if (start == mid && mid == end)
	{
		printf("1.000\n");
	}
	else
		printf("0.000\n");
	system("pause");
	return 0;
}