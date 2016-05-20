
int sum(int one, int two);
int get_int(void);

int main(void)
{
	int boys, girls;
	int total;
	
	boys = get_int();
	girls = get_int();
		
	total = sum(boys, girls);

	return 0;
}
int sum(int one, int two)
{
	int res = one + two;
	return res;
}
int get_int(void)
{
	static int accum = 0;
	return  ++accum;
}
