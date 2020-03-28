#include "ArrayList.h"
#include <stdio.h>
int main(void)
{
	List list;	//리스트 생성
	int data;
	init(&list);

	insert(&list, 11);	//데이터 삽입
	insert(&list, 11);
	insert(&list, 22);
	insert(&list, 22);
	insert(&list, 33);

	printf("삭제 전 현재 데이터의 수: %d \n", Count(&list));

	if (first(&list, &data))
	{
		printf("%d ", data);

		while (next(&list, &data))
			printf("%d ", data);
	}
	printf("\n");

	if (first(&list, &data))	//data=22인 list 삭제
	{
		if (data == 22)
			Remove(&list);
		while (next(&list, &data))
		{
			if (data == 22)
				Remove(&list);
		}
	}

	printf("삭제 후 현재 데이터의 수: %d \n", Count(&list));

	if (first(&list, &data))
	{
		printf("%d ", data);

		while (next(&list, &data))
			printf("%d ", data);
	}
	printf("\n");
	return (0);
}
