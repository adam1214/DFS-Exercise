//Problem 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int path[100][100] = { 0 }; //path[i][j]為0表示i, j兩點之間不通，為1表示有一條路
float How_Long_Cnt[120] = { 0.0 }; //記錄各種路徑長度出現過的次數
float How_Much_Mid_Cnt[120] = { 0.0 }; //記錄各種路徑長度經過mid的次數
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
			if (i == end)//如果深搜到了終點，就輸出剛才經過的路徑
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
			else//如果該點不是終點
			{
				stack[m] = i;//將該點存起來
				m++;
				dfs(i);//接著深搜
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