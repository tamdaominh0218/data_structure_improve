#include <iostream>
#include <deque >
#include <set>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void insert_Node(struct Node** head, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = *head;
	*head = newNode;
}

void insertEnd(struct Node** head, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	//Nếu danh sách trống thì chèn luôn vào
	if (*head==nullptr)
	{
		*head = newNode;
		return;
	}

	Node* temp = *head;
	while (temp->next!=nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void display(struct Node* head) {
	while (head!=NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << "Null_ptr" << endl;
}

int countNode(struct Node* head) {
	int count = 0;
	while (head!=nullptr)
	{
		count++;
		head = head->next;
	}
	return count;
}

int sumNodes(struct Node* head) {
	int sum = 0;
	while (head!=nullptr)
	{
		sum += head->data;
		head = head->next;
	}
	return sum;
}

int maxNode(struct Node* head) {
	int max = INT32_MIN;
	while (head!=nullptr)
	{
		if (head->data>max)
		{
			max = head->data;
		}
		head = head->next;
	}
	return max;
}

Node* linearSearch(struct Node* head, int x) {
	while (head!=nullptr)
	{
		if (x==head->data)
		{
			return head;
		}
		head = head->next;
	}
	return NULL;
}

////Linear search using recursion
//Node* linearSearch(struct Node* head, int x) {
//	if (head==nullptr)
//	{
//		return nullptr;
//	}
//	else
//	{
//		if (x == head->data)
//		{
//			return head;
//		}
//		linearSearch(head->next, x);
//	}
//}

void insert_into_node(struct Node** head, int posi, int value) {
	if (posi==0)
	{
		insert_Node(head, value);
		return;
	}
	Node* temp = *head;
	for (size_t i = 0; i < posi-1; i++)
	{
		temp = temp->next;
	}
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = temp->next;
	temp->next= newNode;
}

void insertSorted(struct Node** head, int value) {
	Node* temp1 = *head;
	if (value < temp1->data)
	{
		insert_Node(head, value);
	}
	else
	{
		Node* temp2 = *head;
		while (temp1->data < value)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			if (temp1->next == nullptr)
			{
				insertEnd(head, value);
				return;
			}
		}
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = temp2->next;
		temp2->next = newNode;
	}
}

void delete_linked(struct Node** head, int posi) {
	Node* temp1 = *head;
	Node* temp2 = nullptr;
	if (posi==0)
	{
		temp2 = temp1;
		*head = temp1->next;
		delete temp2;
	}
	else if (posi>0)
	{
		for (size_t i = 0; i < posi; i++)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2->next = temp1->next;
		delete temp1;
	}
}

//bool checkSorted(struct Node* head) {
//	int temp;
//	while (head!=nullptr)
//	{
//		temp = head->data;
//		head = head->next;
//		if (head==nullptr)
//		{
//			return 1;
//		}
//		else
//		{
//			if (head->data < temp)
//			{
//				return 0;
//			}
//		}
//	}
//}

bool checkSorted(struct Node* head) {
	int temp = INT32_MIN;
	while (head != nullptr)
	{
	
		if (head->data < temp)
		{
			return 0;
		}
		temp = head->data;
		head = head->next;
	}
	return 1;
}

//void removeDuplicates(struct Node** head) {
//	Node* p1 = *head;
//	Node* p2 = p1->next;
//	while (p1!=NULL)
//	{
//		if (p1->data!=p2->data)
//		{
//			p1 = p1->next;
//			p2 = p2->next;
//			if (p2==nullptr)
//			{
//				return;
//			}
//		}
//		else
//		{
//			p1->next = p2->next;
//			delete p2;
//			p2 = p1->next;
//			if (p2 == nullptr)
//			{
//				return;
//			}
//		} 
//	}
//}

void removeDuplicates(struct Node** head) {
	if (*head==nullptr)
	{
		return;
	}
	Node* p1 = *head;
	Node* p2 = nullptr;
	while (p1->next != nullptr)
	{
		if (p1->data != p1->next->data)
		{
			p1 = p1->next;
		}
		else
		{
			p2 = p1->next;
			p1->next = p2->next;
			delete p2;
		}
	}
}

////================================
////Revert linked list sử dụng STL
////================================
//void reversing(struct Node** head) {
//	Node* p = *head;
//	deque <int> backup;
//	while (p!=NULL)
//	{
//		backup.push_front(p->data);
//		p = p->next;
//	}
//	p = *head;
//	for (size_t i = 0; i < size(backup); i++)
//	{
//		p->data = backup.at(i);
//		p = p->next;
//	}
//}

////================================
////Revert linked list sử dụng con trỏ trượt
////================================
//void reversing(struct Node** head) {
//	Node* left = nullptr;
//	Node* mid = nullptr;
//	Node* right = *head;
//	while (right!=nullptr)
//	{
//		left = mid;
//		mid = right;
//		right = right->next;
//		mid->next = left;
//	}
//	*head = mid;
//}

//================================
//Revert linked list sử dụng recursive
//================================
void reversing(struct Node** head, struct Node* q, struct Node* p) {
	if (p)
	{
		reversing(head, p, p->next);
		p->next = q;
	}
	else
	{
		*head = q;
	}
}

//void concatenating(struct Node** head1, const struct Node* head2) {
//	while (head2!=nullptr)
//	{
//		insertEnd(head1, head2->data);
//		head2 = head2->next;
//	}
//}

void concatenating(struct Node** head1, struct Node* head2) {
	Node* p = *head1;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = head2;
	head2 = nullptr;
}

void sorting(struct Node** head) {
	if (checkSorted(*head)==1)
	{
		return;
	}
	else
	{
		Node* p = *head;
		multiset<int> backup;
		while (p!=nullptr)
		{
			backup.insert(p->data);
			p = p->next;
		}
		p = *head;
		for (int x : backup)
		{
			if (p == nullptr) break;
			p->data = x;
			p = p->next;
		}
	}
}

void merging(struct Node** head1, struct Node* head2) {
	sorting(head1);
	while (head2!=nullptr)
	{
		insertSorted(head1, head2->data);
		head2 = head2->next;
	}
	removeDuplicates(head1);
}

bool check_loop(struct Node* head) {
	Node* p = head;
	Node* q = head;
	do
	{
		if (p == nullptr) return 0;
		p = p->next->next;
		q = q->next;
		if (p == q) return 1;
	} while (p!=nullptr || p != q);
	if (p == q)
	{
		return 1;
	}
	else if (p == nullptr)
	{
		return 0;
	}
}

int main() {
	struct  Node *n = nullptr;

	//================================
	//Chèn vào đầu linked list
	//================================
	//insert_Node(&n, 6);
	//insert_Node(&n, 8);
	//insert_Node(&n, 9);
	//insert_Node(&n, 3);
	//display(n);

	//================================
	//Chèn vào cuối linked list
	//================================
	/*insertEnd(&n, 6);
	insertEnd(&n, 8);
	insertEnd(&n, 8);
	insertEnd(&n, 15);
	insertEnd(&n, 19);
	insertEnd(&n, 19);
	insertEnd(&n, 19);
	insertEnd(&n, 25); 
	insertEnd(&n, 35);
	insertEnd(&n, 50);
	display(n);*/

	//================================
	//Tìm count, sum, max node
	//================================
	//cout << countNode(n) << endl;
	//cout << sumNodes(n) << endl;
	//cout << maxNode(n) << endl;
	
	//================================
	//Searching
	//================================
	/*int search1 = 1;
	cout << linearSearch(n, search1) << endl;
	int search2 = 8;
	cout << linearSearch(n, search2) << endl;*/

	//================================
	//Chèn vào vị trí bất kì
	//================================
	//insert_into_node(&n, 4, 10);
	//display(n);
	//insert_into_node(&n, 0, 1);
	//display(n);

	//cout << "Linked list is sorted: " << checkSorted(n) << endl;

	//================================
	//Insert to sorted
	//================================
	//insertSorted(&n, 12);
	//insertSorted(&n, 3);
	//insertSorted(&n, 25);
	//display(n);
	
	//================================
	//Delete
	//================================
	/*delete_linked(&n,0);
	display(n);*/

	//removeDuplicates(&n);
	//reversing(&n, NULL ,n);
	//display(n);

	//struct  Node* n2 = nullptr;
	//insertEnd(&n2, 8);
	//insertEnd(&n2, 15);
	//insertEnd(&n2, 25);
	//insertEnd(&n2, 81);

	//concatenating(&n, n2);
	//display(n);

	//struct  Node* n3 = nullptr;
	//insertEnd(&n3, 8);
	//insertEnd(&n3, 3);
	//insertEnd(&n3, 9);
	//insertEnd(&n3, 2);
	//insertEnd(&n3, 10);
	//insertEnd(&n3, 16);
	//insertEnd(&n3, 13);
	//insertEnd(&n3, 15);
	//display(n3);

	//struct  Node* n4 = nullptr;
	//insertEnd(&n4, 2);
	//insertEnd(&n4, 15);
	//insertEnd(&n4, 21);
	//insertEnd(&n4, 29);
	//display(n4);
	//merging(&n3, n4);
	//display(n3);

	struct  Node* n5 = nullptr;
	insertEnd(&n5, 8);
	insertEnd(&n5, 3);
	insertEnd(&n5, 9);
	insertEnd(&n5, 2);
	insertEnd(&n5, 10);

	struct  Node* n6 = nullptr;
	insertEnd(&n6, 22);
	insertEnd(&n6, 15);
	insertEnd(&n6, 21);
	insertEnd(&n6, 29);

	n5->next->next->next->next->next = n5->next;
	cout << check_loop(n5) << endl;
	cout << check_loop(n6) << endl;

	return 0;
}

//5 2 7 3
//2 5 7 3
//