void HanoiTowerMove(int num, char from, char by, char to)
{
	if(num == 1) //재귀 탈출조건(이동할 원반의 수가 1개일 때)
	{
		printf("원반 1을 %c에서 %c로 이동\n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);              //1번
		printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);  //2번
		HanoiTowerMove(num - 1, by, from, to);             //3번
	}
}
