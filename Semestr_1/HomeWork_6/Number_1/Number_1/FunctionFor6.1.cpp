#include <iostream>
#include "FunctionFor6.1.h"
#include "HomeWork_6/Stack.h"

using namespace std;

int operation(const char &symbol, const int &operandOne, const int &operandTwo)
{
	int result = 0;
	switch (symbol)
	{
	case '+':
	{
		result = operandOne + operandTwo;
		break;
	}
	case '-':
	{
		result = operandOne - operandTwo;
		break;
	}
	case '*':
	{
		result = operandOne * operandTwo;
		break;
	}
	case '/':
	{
		result = operandOne / operandTwo;
		break;
	}
	default:
	{
		cout << "!!!!������!!!!�������� -1, ��� �� ���� �������� ������������� ���������\n";
		int temp = 0;
		cin >> temp;
		return -1;
	}
	}
	return result;
}

bool isNumber(const char &symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool isOperator(const char &symbol)
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int expressionResult(const string &str)
{
	auto stack = createStack();
	const int length = (int)str.size();

	for (int i = 0; i < length; ++i)
	{
		if (isNumber(str[i]))
		{
			push(stack, (int)(str[i] - '0'));
		}
		else if (isOperator(str[i]))
		{
			const int operandTwo = pop(stack);
			const int operandOne = pop(stack);
			push(stack, operation(str[i], operandOne, operandTwo));
		}
	}
	int result = pop(stack);
	deleteStack(stack);
	return result;
}

bool test()
{
	string str1 = "12+3*3-";
	string str2 = "44/43+*";
	string str3 = "777+*777+-+";
	return expressionResult(str1) == 6 && expressionResult(str2) == 7 && expressionResult(str3) == 91;
}