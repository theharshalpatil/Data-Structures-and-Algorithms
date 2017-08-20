// C++ Program to implement Singly Linked List (SLL)
#include <iostream>
using namespace std;

// Declaration of Node for LL
struct node {
	int value;
	struct node * next;
}*head;

// Class Declaration
class sll {
public:
	node* new_node(int);
	void insert_first();
	void insert_pos();
	void insert_last();
	void delete_pos();
	void search();
	void update();
	void sort();
	void reverse(node *, node *);
	void display();
	sll() {
		head = NULL;
	}
};

// Implement a menu
void main() {
	int choice, nodes, position, element, i;
	sll sl;
	head = NULL;
	while(1) {
		cout << endl << "=== Singly Linked List Implementation ===" << endl;
		cout << "1. Insert node at begining" << endl;
		cout << "2. Insert node at last" << endl;
		cout << "3. Insert node at a position" << endl;
		cout << "4. Sort Linked List" << endl;
		cout << "5. Delete a particular node" << endl;
		cout << "6. Update a node value" << endl;
		cout << "7. Search an element" << endl;
		cout << "8. Reverse Linked List" << endl;
		cout << "9. Display Linked List" << endl;
		cout << "10. Exit!" << endl;
		cout << "ENTER YOUR CHOICE: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Inserting node at begining => " << endl;
			sl.insert_first();
			cout << endl;
			break;
		case 2:
			cout << "Inserting node at last => " << endl;
			sl.insert_last();
			cout << endl;
			break;
		case 3:
			cout << "Inserting at a given position => " << endl;
			sl.insert_pos();
			cout << endl;
			break;
		case 4:
			cout << "Sorting Linked List => " << endl;
			sl.sort();
			cout << endl;
			break;
		case 5:
			cout << "Deleting a particular node => " << endl;
			sl.delete_pos();
			cout << endl;
			break;
		case 6:
			cout << "Updating particular node value => " << endl;
			sl.update();
			cout << endl;
			break;
		case 7:
			cout << "Searching in LL => " << endl;
			sl.search();
			cout << endl;
			break;
		case 8:
			cout << "Revering elements of LL => " << endl;
			sl.reverse(NULL, head);
			cout << endl;
			break;
		case 9:
			cout << "Displaying LL => " << endl;
			sl.display();
			cout << endl;
			break;
		case 10:
			cout << "Exiting..." << endl;
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}
}

// Creating new node
node *sll::new_node(int val){
	struct node *temp;
	temp = new(struct node);
	if (temp == NULL) {
		cout << "Memory not allocated" << endl;
		return 0;
	}
	else {
		temp->value = val;
		temp->next = NULL;
		return temp;
	}
}

// Insert elemeent at the begining
void sll::insert_first(){
	int val;
	cout << "Enter new Value to be inserted: ";
	cin >> val;
	struct node *temp, *n;
	temp = new_node(val);
	if (head == NULL) {
		head = temp;
		head->next = NULL;
	}
	else {
		n = head;
		head = temp;
		head->next = n;
	}
	cout << "Element " << val << " inserted at the beginning." << endl;
}

// Insert element at the last
void sll::insert_last() {
	int val;
	cout << "Enter new Value to be inserted: ";
	cin >> val;
	struct node *temp, *h;
	temp = new_node(val);
	h = head;
	while (h->next != NULL) {
		h = h->next;		// Goto the last node
	}
	temp->next = NULL;
	h->next = temp;
	cout << "Element " << val << " inserted at the last." << endl;
}

// Insert element at a given position
void sll::insert_pos() {
	int val, pos, cnt = 0;
	cout << "Enter new Value to be inserted: ";
	cin >> val;
	struct node *temp, *h, *ptr;
	temp = new_node(val);
	cout << "Enter the position at which node is to be inserted: ";
	cin >> pos;
	
	h = head;
	while (h != NULL) {
		h = h->next;
		cnt++;
	}

	if (pos == 1) {
		if (head == NULL) {
			head = temp;
			head->next = NULL;
		}
		else {
			ptr = head;
			head = temp;
			head->next = ptr;
		}
	}
	else if (pos > 1 && pos <= cnt) {
		h = head;
		for (int i = 1; i < pos; i++) {
			ptr = h;
			h = h->next;
		}
		ptr->next = temp;
		temp->next = h;
	}
	else {
		cout << "Position is out of range!" << endl;
	}
}

// Deleting element at a given position
void sll::delete_pos() {
	int pos, cnt = 0;
	if (head == NULL) {
		cout << "List is empty!" << endl;
		return;
	}
	cout << "Enter the postition of value to be deleted: ";
	cin >> pos;
	struct node *h, *ptr;
	h = head;
	if (pos == 1) {
		head = h->next;
		cout << "Element " << h->value << " Deleted." << endl;
		free(h);
	}
	else {
		while (h != NULL) {
			h = h->next;
			cnt++;
		}
		if (pos > 0 && pos <= cnt) {
			h = head;
			for (int i = 1; i < pos; i++) {
				ptr = h;
				h = h->next;
			}
			ptr->next = h->next;
			cout << "Element " << h->value << " Deleted." << endl;
		}
		else {
			cout << "Position out of range!" << endl;
		}
		free(h);
	}
}

// Searching an element
void sll::search() {
	int val, pos = 0;
	bool flag = false;
	if (head == NULL) {
		cout << "List is empty!" << endl;
		return;
	}
	cout << "Enter the Value to be searched: ";
	cin >> val;
	struct node *ptr;
	ptr = head;
	while (ptr != NULL) {
		pos++;
		if (ptr->value == val) {
			flag = true;
			cout << "Element " << val << " found at position " << pos << endl;
		}
		ptr = ptr->next;
	}
	if (!flag) {
		cout << "Element " << val << " not in the list" << endl;
	}
}

// Update a particular node
void sll::update() {
	int val, pos;
	if (head == NULL) {
		cout << "List is empty!" << endl;
		return;
	}
	cout << "Enter the position of node to be updated: ";
	cin >> pos;
	cout << "Enter new value: ";
	cin >> val;
	struct node *h;
	h = head;
	if (pos == 1) {
		head->value = val;
	}
	else {
		for (int i = 0; i < pos - 1; i++) {
			if (h == NULL) {
				cout << "Position out of range!" << endl;
				return;
			}
			h = h->next;
		}
		h->value = val;
	}
	cout << "Element Updated" << endl;
}

// Sorting Linked List
void sll::sort() {
	struct node *ptr, *h;
	int val;
	if (head == NULL) {
		cout << "The List is Empty!" << endl;
		return;
	}
	ptr = head;
	while (ptr != NULL) {
		for (h = ptr->next; h != NULL; h = h->next) {
			if (ptr->value > h->value){
				val = ptr->value;
				ptr->value = h->value;
				h->value = val;
			}
		}
		ptr = ptr->next;
	}
}

// Reversing Linked List
// This is a recursive approach to start pass reverse(NULL, head);
void sll::reverse(node *prev, node *curr) {
	if (curr) {
		reverse(curr, curr->next);
		curr->next = prev;
	}
	else {
		head = prev;
	}
}

void sll::display() {
	if (head == NULL) {
		cout << "The List is Empty." << endl;
		return;
	}

	struct node *h;
	h = head;
	cout << "Elements in the list are: " << endl;
	while (h != NULL) {
		cout << h->value << " -> ";
		h = h->next;
	}
	cout << "NULL" << endl;
}