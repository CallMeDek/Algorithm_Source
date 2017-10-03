#include "multiplication.h"

int lengthOfbinary(int number)
{
	if (number == 0) return 0;
	return 1 + lengthOfbinary(number >> 1);
}

int _min(int a, int b)
{
	return a < b ? a : b;
}

int power(int index)
{
	int i, value = 1;
	for (i = 0; i < index; i++)
		value *= 2;
	return value;
}

int multiply(int a, int b)
{
	int length = _min(lengthOfbinary(a), lengthOfbinary(b));
	if (length < 2) return a * b;

	int half_length = length >> 1;
	int left_a = a >> half_length;
	int right_a = a % (power(half_length));
	int left_b = b >> half_length;
	int right_b = b % (power(half_length));

	int first = multiply(left_a, left_b);
	int middle = multiply((left_a + right_a), (left_b + right_b));
	int right = multiply(right_a, right_b);

	return first*power(half_length << 1) + (middle - first - right)*power(half_length) + right;
}