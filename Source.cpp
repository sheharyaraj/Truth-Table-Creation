#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	bool flag = false;
	int col;
	int rows = 2;

	stack <char> st;
	stack<int>	st1;
	int n1;
	int n2;
	string str;
	string str1;
	string postfix;
	string postfix1;
	char num1;
	char num2;
	char num3;
	char num4;
	char num5;

	char table[2] = {
		'0','1'
	};

	char result[2];

	char table1[4][2] = {
			{'0','0'},{'0','1'},{'1','0'},{'1','1'}
	};

	char result1[4];

	char table2[8][3] = {
			{'0','0','0'},{'0','0','1'},{'0','1','0'},{'0','1','1'},{'1','0','0'},{'1','0','1'},{'1','1','0'},{'1','1','1'}
	};

	char result2[8];

	char table3[16][4] = {
			{'0','0','0','0'},{'0','0','0','1'},{'0','0','1','0'},{'0','0','1','1'},{'0','1','0','0'},{'0','1','0','1'},{'0','1','1','0'},{'0','1','1','1'},
			{'1','0','0','0'},{'1','0','0','1'},{'1','0','1','0'},{'1','0','1','1'},{'1','1','0','0'},{'1','1','0','1'},{'1','1','1','0'},{'1','1','1','1'}
	};
	char result3[16];

	char table4[32][5] = {
			{'0','0','0','0','0'},{'0','0','0','0','1'},{'0','0','0','1','0'},{'0','0','0','1','1'},{'0','0','1','0','0'},{'0','0','1','0','1'},
		{'0','0','1','1','0'},{'0','0','1','1','1'},{'0','1','0','0','0'},{'0','1','0','0','1'},{'0','1','0','1','0'},{'0','1','0','1','1'},{'0','1','1','0','0'},
		{'0','1','1','0','1'},	{'0','1','1','1','0'},{'0','1','1','1','1'},{'1','0','0','0','0'},{'1','0','0','0','1'},{'1','0','0','1','0'},
		{'1','0','0','1','1'},{'1','0','1','0','0'},{'1','0','1','0','1'},{'1','0','1','1','0'},{'1','0','1','1','1'},{'1','1','0','0','0'},
		{'1','1','0','0','1'},{'1','1','0','1','0'},{'1','1','0','1','1'},{'1','1','1','0','0'},{'1','1','1','0','1'},{'1','1','1','1','0'},
		{'1','1','1','1','1'}
	};
	char result4[32];

	cout << "Enter the string: ";
	getline(cin, str);
	cout << endl;

	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			flag = false;
			for (int j = 0; j < str1.size(); j++)
			{
				if (str[i] == str1[j])
				{
					flag = true;
				}
			}
			if (flag == false)
			{
				str1 = str1 + str[i];
			}
		}
	}

	if (str1.size() == 1)
	{
		rows = 2;
	}
	else
	{
		for (int i = 0; i < str1.size() - 1; i++)
		{
			rows = rows * 2;
		}
	}
	col = str1.size();

	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			postfix = postfix + str[i];
		}
		else if (str[i] == '(')
		{
			st.push('(');
		}
		else if (str[i] == ')')
		{
			while (st.top() != '(')
			{
				postfix = postfix + st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[i] == '~')
		{
			st.push('~');
		}
		else if (str[i] == '*')
		{
			if (st.empty())
			{
				st.push('*');
			}
			else if (st.top() == '~')
			{

				postfix = postfix + '~';
				st.pop();

				st.push('*');
			}
			else
			{
				st.push('*');
			}
		}
		else if (str[i] == '+')
		{
			if (st.empty())
			{
				st.push('+');
			}
			else if (st.top() == '~')
			{

				postfix = postfix + '~';
				st.pop();

				st.push('+');
			}
			else if (st.top() == '*')
			{

				postfix = postfix + '*';
				st.pop();

				st.push('+');
			}
			else
			{
				st.push('+');
			}
		}
	}

	while (!st.empty())
	{
		postfix = postfix + st.top();
		st.pop();
	}
	postfix1 = postfix;
	switch (col)
	{
	case 1:
		for (int i = 0; i < rows; i++)
		{
			num1 = table[i];

			for (int i = 0; i < postfix.size(); i++)		//assigning values in equation
			{
				if (postfix[i] >= 'a' && postfix[i] <= 'z')
				{
					postfix[i] = num1;
				}
			}

			for (int i = 0; i < postfix.size(); i++)			//evaluating equation
			{
				if (postfix[i] == '0' || postfix[i] == '1')
				{
					n1 = postfix[i] - 48;
					st1.push(n1);
				}
				else if (postfix[i] == '~')
				{
					if (st1.top() == 0)
					{
						st1.pop();
						st1.push(1);
					}
					else
					{
						st1.pop();
						st1.push(0);
					}
				}
				else if (postfix[i] == '*')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 && n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
				else if (postfix[i] == '+')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 || n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
			}
			result[i] = st1.top() + 48;
			st1.pop();
			postfix = postfix1;
		}

		cout << "Table: " << endl << endl;
		cout << "a   " << str << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << table[i] << " ";

			cout << "  " << result[i] << endl;
		}

		break;
	case 2:
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)			//getting values from truth table
			{
				if (j == 0)
				{
					num1 = table1[i][j];
				}
				else if (j == 1)
				{
					num2 = table1[i][j];
				}
			}

			for (int i = 0; i < postfix.size(); i++)		//assigning values in equation
			{
				if (postfix[i] == 'a')
				{
					postfix[i] = num1;
				}
				else if (postfix[i] == 'b')
				{
					postfix[i] = num2;
				}
			}

			for (int i = 0; i < postfix.size(); i++)			//evaluating equation
			{
				if (postfix[i] == '0' || postfix[i] == '1')
				{
					n1 = postfix[i] - 48;
					st1.push(n1);
				}
				else if (postfix[i] == '~')
				{
					if (st1.top() == 0)
					{
						st1.pop();
						st1.push(1);
					}
					else
					{
						st1.pop();
						st1.push(0);
					}
				}
				else if (postfix[i] == '*')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 && n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
				else if (postfix[i] == '+')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 || n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
			}
			result1[i] = st1.top() + 48;
			st1.pop();
			postfix = postfix1;
		}

		cout << "Table: " << endl << endl;
		cout << "a b   " << str << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << table1[i][j] << " ";
			}
			cout << "  " << result1[i] << endl;
		}

		break;
	case 3:
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)			//getting values from truth table
			{
				if (j == 0)
				{
					num1 = table2[i][j];
				}
				else if (j == 1)
				{
					num2 = table2[i][j];
				}
				else if (j == 2)
				{
					num3 = table2[i][j];
				}
			}

			for (int i = 0; i < postfix.size(); i++)		//assigning values in equation
			{
				if (postfix[i] == 'a')
				{
					postfix[i] = num1;
				}
				else if (postfix[i] == 'b')
				{
					postfix[i] = num2;
				}
				else if (postfix[i] == 'c')
				{
					postfix[i] = num3;
				}
			}

			for (int i = 0; i < postfix.size(); i++)			//evaluating equation
			{
				if (postfix[i] == '0' || postfix[i] == '1')
				{
					n1 = postfix[i] - 48;
					st1.push(n1);
				}
				else if (postfix[i] == '~')
				{
					if (st1.top() == 0)
					{
						st1.pop();
						st1.push(1);
					}
					else
					{
						st1.pop();
						st1.push(0);
					}
				}
				else if (postfix[i] == '*')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 && n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
				else if (postfix[i] == '+')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 || n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
			}
			result2[i] = st1.top() + 48;
			st1.pop();
			postfix = postfix1;
		}

		cout << "Table: " << endl << endl;						//printing truth table
		cout << "a b c  " << str << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << table2[i][j] << " ";
			}
			cout << "  " << result2[i] << endl;
		}

		break;
	case 4:
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)			//getting values from truth table
			{
				if (j == 0)
				{
					num1 = table3[i][j];
				}
				else if (j == 1)
				{
					num2 = table3[i][j];
				}
				else if (j == 2)
				{
					num3 = table3[i][j];
				}
				else if (j == 3)
				{
					num4 = table3[i][j];
				}
			}

			for (int i = 0; i < postfix.size(); i++)		//assigning values in equation
			{
				if (postfix[i] == 'a')
				{
					postfix[i] = num1;
				}
				else if (postfix[i] == 'b')
				{
					postfix[i] = num2;
				}
				else if (postfix[i] == 'c')
				{
					postfix[i] = num3;
				}
				else if (postfix[i] == 'd')
				{
					postfix[i] = num4;
				}
			}

			for (int i = 0; i < postfix.size(); i++)			//evaluating equation
			{
				if (postfix[i] == '0' || postfix[i] == '1')
				{
					n1 = postfix[i] - 48;
					st1.push(n1);
				}
				else if (postfix[i] == '~')
				{
					if (st1.top() == 0)
					{
						st1.pop();
						st1.push(1);
					}
					else
					{
						st1.pop();
						st1.push(0);
					}
				}
				else if (postfix[i] == '*')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 && n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
				else if (postfix[i] == '+')
				{
					n1 = st1.top();
					st1.pop();
					n2 = st1.top();
					st1.pop();
					if (n1 || n2)
					{
						st1.push(1);
					}
					else
					{
						st1.push(0);
					}
				}
			}
			result3[i] = st1.top() + 48;
			st1.pop();
			postfix = postfix1;
		}

		cout << "Table: " << endl << endl;						//printing truth table
		cout << "a b c d  " << str << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << table3[i][j] << " ";
			}
			cout << "  " << result3[i] << endl;
		}
		break;

		case 5:
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < col; j++)			//getting values from truth table
				{
					if (j == 0)
					{
						num1 = table4[i][j];
					}
					else if (j == 1)
					{
						num2 = table4[i][j];
					}
					else if (j == 2)
					{
						num3 = table4[i][j];
					}
					else if (j == 3)
					{
						num4 = table4[i][j];
					}
					else if (j == 4)
					{
						num5 = table4[i][j];
					}
				}

				for (int i = 0; i < postfix.size(); i++)		//assigning values in equation
				{
					if (postfix[i] == 'a')
					{
						postfix[i] = num1;
					}
					else if (postfix[i] == 'b')
					{
						postfix[i] = num2;
					}
					else if (postfix[i] == 'c')
					{
						postfix[i] = num3;
					}
					else if (postfix[i] == 'd')
					{
						postfix[i] = num4;
					}
					else if (postfix[i] == 'e')
					{
						postfix[i] = num5;
					}
				}

				for (int i = 0; i < postfix.size(); i++)			//evaluating equation
				{
					if (postfix[i] == '0' || postfix[i] == '1')
					{
						n1 = postfix[i] - 48;
						st1.push(n1);
					}
					else if (postfix[i] == '~')
					{
						if (st1.top() == 0)
						{
							st1.pop();
							st1.push(1);
						}
						else
						{
							st1.pop();
							st1.push(0);
						}
					}
					else if (postfix[i] == '*')
					{
						n1 = st1.top();
						st1.pop();
						n2 = st1.top();
						st1.pop();
						if (n1 && n2)
						{
							st1.push(1);
						}
						else
						{
							st1.push(0);
						}
					}
					else if (postfix[i] == '+')
					{
						n1 = st1.top();
						st1.pop();
						n2 = st1.top();
						st1.pop();
						if (n1 || n2)
						{
							st1.push(1);
						}
						else
						{
							st1.push(0);
						}
					}
				}
				result4[i] = st1.top() + 48;
				st1.pop();
				postfix = postfix1;
			}

			cout << "Table: " << endl << endl;						//printing truth table
			cout << "a b c d e  " << str << endl;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < col; j++)
				{
					cout << table4[i][j] << " ";
				}
				cout << "  " << result4[i] << endl;
			}
			break;

	}
}