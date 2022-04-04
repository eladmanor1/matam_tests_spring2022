#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int power_of_two(int a);
int main()
{
	int i;

	printf("Enter size of input:\n");
	
		if (scanf("%d", &i)==1)
			if (i <= 0)
			{
				printf("Invalid size\n");
				return 0;
         	}
		int* arr;
		arr =malloc(i * sizeof(int));
		if (arr == NULL)
			return 0;
			
		printf("Enter numbers:\n");
		int temp;
		for (int j = 0; j < i; j++)
		{
			if (scanf("%d", &temp) == 0)
			{
				printf("Invalid number\n");
				free(arr);
				return 0;
			}
			arr[j] = temp;	
		}
		int sum = 0 ,p;
        bool One_Flag = false;
		for (int m = 0; m < i; m++)
		{
			p = power_of_two(arr[m]);
            if (arr[m]==1)
            {
              One_Flag = true;  
            }
               
			sum += p;
			if (p == 0 && !One_Flag)
				continue;
			printf("The number %d is a power of 2: %d = 2^%d\n", arr[m], arr[m], p);
            One_Flag =false;
		}
		printf("Total exponent sum is %d\n", sum);
		free(arr);
		return 0;
}
int power_of_two(int a)
{
	int power = 2, count = 1;
	if (a % 2 == 1)
		return 0;
	while (a > power)
	{
		power *= 2;
		count++;
	}
	if (a == power)
		return count;
	return 0;
}