#include <vector>

long long sum(std::vector<int>& a)
{
	long long total = 0;

	for (unsigned int i = 0; i < a.size(); i++)
		total += a[i];

	return total;
}