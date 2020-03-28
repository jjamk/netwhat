int	BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;
	if (first > last)	//재귀 탈출조건
		return (-1);
	mid = (first + last) / 2;

	if(ar[mid] == target)
		return (mid);
	else if (target < ar[mid])
		return (BSearchRecur(ar, first, mid - 1, target));
	else
		return (BSearchRecur(ar, mid + 1, last, target));
}
