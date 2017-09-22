//============================================================================
// Name        : multiplyLinkedList.cpp
// Author      : Prashant Mulge
// Version     : 1.0
// Copyright   : @PrashantMulge
// Description : Multiplication of two Linked list in C++.
//============================================================================

#include <iostream>
using namespace std;

void readNumbers();
void listInit();
bool checkList();
void printList();
void reverseList();
void multiplyList();
class Node
{
public:
	int num;
	Node *next;
};

Node *firstList;
Node *secondList;
Node *sumList;


int main() {
	cout << "Type in the two numbers to be multiplied, digit by digit. At the end of each number enter '-1'." << endl;
	listInit();
	readNumbers();
	checkList();
	//cout << "Printing the numbers" << endl;
	//printList();
	reverseList();
	//printList();

	multiplyList();

	Node *temp = sumList;
	//cout << "Result" << endl;
	/*while(temp)
	{
		//cout << temp->num << endl;
		temp = temp->next;
	}*/
	
	//cout << " reversed Result" << endl;
	Node *prev, *nxt, *cur;
	cur = sumList->next;
	prev = NULL;

	while(cur)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	sumList->next = prev;

	temp = sumList->next;	
	cout << "Result" << endl;
	while(temp)
	{
		cout << temp->num;
		temp = temp->next;
	}
	cout << endl;
	return 0;
}

void readNumbers()
{
	int ele;
	Node *temp, *newNode;
	cout << "Enter first number" << endl;
	cin >> ele;
	temp = firstList;// = temp;

	while(ele != -1)
	{
		newNode = new Node();
		newNode->next = NULL;
		newNode->num = ele;
		temp->next = newNode;
		temp = temp->next;
		cin >> ele;
	}


	temp = NULL;
	cout << "Enter Second number" << endl;
	cin >> ele;
	//secondList = temp;
	temp = secondList;

	while(ele != -1)
	{
		newNode = new Node();
		newNode->next = NULL;
		newNode->num = ele;
		temp->next = newNode;
		temp = temp->next;
		cin >> ele;
	}

}

void listInit()
{
	firstList = new Node();
	firstList->next = NULL;
	secondList = new Node();
	secondList->next = NULL;
	sumList = new Node();
	sumList->next = NULL;
}

void printList()
{
	Node *temp1 = firstList, *temp2 = secondList;

	while(temp1)
	{
		cout << temp1->num << endl;
		temp1 = temp1->next;
	}

	while(temp2)
	{
		cout << temp2->num << endl;
		temp2 = temp2->next;
	}

}

void reverseList()
{
	Node *prev, *nxt, *cur;
	cur = firstList->next;
	prev = NULL;

	while(cur)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	firstList->next = prev;

	cur = secondList->next;
	prev = NULL;

	while(cur)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	secondList->next = prev;
}

void multiplyList()
{
	Node *temp1 = firstList, *temp2 = secondList, *temp3 = sumList, *newNode = NULL;
	int ele = 0, carry = 0, val = 0, iter = 0, flag = 0;

	temp2 = temp2->next;
	while (temp2 != NULL)
	{
		ele = temp2->num;
		temp1 = firstList;
		temp3 = sumList;
		temp1 = temp1->next;
		carry = 0;

		for(int i = 0; i < iter; i++)
		{
			temp3 = temp3->next;
		}
		while(temp1 != NULL)
		{
			val = ele * temp1->num;
			val += carry;
			if(val / 10)
			{
				carry = val / 10;
				val %= 10;
			}
			else{
				carry = 0;
			}

			if(flag == 0)
			{
				newNode = new Node();
				newNode->num = val;
				newNode->next = NULL;
				temp3->next = newNode;
				temp3 = temp3->next;
			}
			else
			{
				if(temp3->next)
				{
					val += temp3->next->num;
					if(val / 10)
					{
						carry += val / 10;
						val %= 10;
					}
					temp3->next->num = val;
					temp3 = temp3->next;
				}
				else
				{
					newNode = new Node();
					newNode->num = val;
					newNode->next = NULL;
					temp3->next = newNode;
					temp3 = temp3->next;
				}
			}

			temp1 = temp1->next;

		}
		iter++;
		if(carry > 0)
		{
			newNode = new Node();
			newNode->num = carry;
			newNode->next = NULL;
			temp3->next = newNode;
			temp3 = temp3->next;
		}

		flag = 1;
		temp2 = temp2->next;
	}
}

bool checkList()
{
	if(!firstList)
		return false;
	else if(!secondList)
		return false;
}

