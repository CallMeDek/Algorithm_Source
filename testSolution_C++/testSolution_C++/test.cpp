#include <iostream>
#include "userInput.h"
#include "fastSum.h"

int main(void)
{
	TypedInput a;
	a.setSize();
	//a.testCode();

	FiledInput b;
	b.setSize();
	//b.testCode();

	FastSum c(a.getSize());
	c.execute();

	FastSum d(b.getSize());
	d.execute();

	return 0;
}