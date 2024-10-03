#include <iostream>
#include <unordered_map>
using namespace std;

long long N, P, Q, X, Y = 0;
unordered_map<long long, long long> hashMap;
long long sol(long long num);

int main(void)
{
	cin >> N >> P >> Q >> X >> Y;

	hashMap[0] = 1;
	cout << sol(N);
	return 0;
}
long long  sol(long long num)
{
	if (hashMap.find(num) != hashMap.end())
	{
		return hashMap[num];
	}
	else
	{
		long long temp1, temp2 = 0;
		if ((num / P - X) <= 0)
		{
			temp1 = 1;
		}
		else
		{
			temp1 = sol(num / P - X);
		}
		
		if ((num / Q - Y) <= 0)
		{
			temp2 = 1;
		}
		else
		{
			temp2 = sol(num / Q - Y);
		}
			
		hashMap[num] = temp1 + temp2;

		return hashMap[num];
	}
}