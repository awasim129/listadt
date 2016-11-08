#include <iostream>
#include <conio.h>

using namespace std;

struct node {
	int data;
	node *next;
};

node *START = NULL;

node *createNode() {
	node *temp;
	temp = (node*)malloc(sizeof(node));
	return temp;
}

void insertatEnd(int n) {
	node *temp, *t;

	 temp = createNode();
	(*temp).data = n;
	(*temp).next = NULL;

	if (START == NULL) {
		START = temp;
	}

	else {
		t = START;

		while ((*t).next != NULL) {
			(t) = (*t).next;
		}
		(*t).next = temp;
	}
	}

void insertatStart(int n) {
	node *temp,*t;
	
	temp = createNode();
	(*temp).data = n;
	(*temp).next = START;
	
	if (START == NULL) {
		START = temp;
	}
	else {
		t = START;
		START = temp;
	}
}

void insertatPos(int pos, int n) {
	node *temp, *t,*swap;
	int sentinel = 1;
	temp = createNode();
	(*temp).data = n;

	if (START == NULL) {
		START = temp;
	}
	else {
		t = START;

		while (sentinel < pos - 1) {
			sentinel++;
			t = (*t).next;
		}
//			swap = t;
		swap = (*t).next;
		(*t).next = temp;
		(*temp).next = swap;
	}
}

void Display() {
	node *disp;
	disp = START;

	if ((*disp).next == NULL) {
		cout << "LinkedList is Empty";
	}

	else {
		while ((*disp).next != NULL) {
			cout << (*disp).data << " ";
			disp = (*disp).next;
			
		}
		cout << (*disp).data;
		system("pause");
			}

}

void main() {
hell:
	system("cls");
	cout << "Hey! How u doinnnn!!! ;) \n\n";

	cout << "1. Add to LinkedList (End)\n"
		<< "2. Add to LinkedList (Front)\n"
		<< "3. Add to LinkedList (Any Position)\n"
		<< "4. View LinkedList\n"
		<< "5. Exit\n"
		<<"\nEnter Choice: ";

	int choice;
	cin >> choice;
	
	int n;
	

	if (choice == 1) {
		system("cls");
		cout << "Enter number to be inserted into LinkedList: ";
		cin >> n;
		insertatEnd(n);
		goto hell;
	}

	else if (choice == 2) {
		system("cls");
		cout << "Enter number to be inserted into LinkedList: ";
		cin >> n;
		insertatStart(n);
		goto hell;
	}

	else if (choice == 3) {
		system("cls");
		int pos;
		cout << "Enter number to be inserted into LinkedList: ";
		cin >> n;
		cout << "Enter Position for Insertion: ";
		cin >> pos;
		insertatPos(pos, n);
		goto hell;
	}

	else if (choice==4) {
		system("cls");
		Display();
		goto hell;
	}

	else {
		system("pause");
	}

}