//make a calculator
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int>digit;
stack<char>op;

void introduce()
{
	printf("\n");
	printf("\t(@^o^@)   C++简易计算器  (⌒:⌒)\n");
	printf("\t(~):(~)                  (~)v(~) \n");
	printf("\n\n");
	cout<<"\t请输入表达式，例如2+3*2+2 *3"<<endl;
}
/*
void clear()
{
	digit.clear();
	op.clear();
}
*/
bool isCalc(char ch)
{
	if (op.empty())
	{
		return false;
	}
	if (op.top() =='(')
	{
		return false;
	}
	if(ch == '+' || ch == '-')
	{
		return true;
	}
	if (ch == '*' && (op.top() == '*' || op.top() == '/'))
	{
		return true;
	}
	if (ch == '/' && (op.top() == '*' || op.top() == '/'))
	{
		return true;
	}
	return false;
}

void calculator()
{
	if (!digit.size())
	{
		cout << "表达式输入错误\n" << endl;
		system("pause");
		exit(0);
	}
	int right = digit.top();
	digit.pop();

	if (!digit.size())
	{
		cout << "表达式输入错误\n" << endl;
		system("pause");
		exit(0);
	}
	int left = digit.top();
	digit.pop();

	int result = 0;
	switch(op.top())
	{
		case '+':
			result = left + right;
			break;
		case '-':
			result = left - right;
			break;
		case '*':
			result = left * right;
			break;
		case '/':
		{
			if(right == 0)
			{
				cout << "表达式输入错误，分母不能为0\n" << endl;
				system("pause");
				exit(0);
			}
			result = left / right;
		}
			break;
	}
	op.pop();
	digit.push(result);
}

int getResult(string str)
{
	//clear();
	int temp = 0;
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		if (isdigit(str[i]))
		{
			temp = temp * 10 + (str[i] - '0');
			if(i + 1 == str.length() || !isdigit(str[i + 1]))
			{
				digit.push(temp);
				temp = 0;
			}
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (isCalc(str[i]))
			{
				calculator();
			}
			op.push(str[i]);
		}
		else if (str[i] == '(')
		{
			op.push(str[i]);
		}
		else if(str[i] ==')')
		{
			while(op.top() != '(')
			{
				calculator();
			}
			op.pop();
		}
	}
	while(!op.empty())
	{
		calculator();
	}
	return digit.top();
}

int main()
{
	/* code */
	introduce();
	string str;
	cin>>str;
	int result = getResult(str);
	cout<<"result = "<< result <<endl;
	return 0;
}