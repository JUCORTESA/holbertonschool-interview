#include "palindrome.h"
/**
 * is_palindrome - checks if a number is palindrome.
 * @n: number to check
 * Return: 1 if palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long aux = 0, rev = 0, number;

	number = n;
	while (n != 0)
	{
		aux = n % 10;
		rev = rev * 10 + aux;
		n /= 10;
	}

	if (rev == number)
		return (1);
	return (0);
}
