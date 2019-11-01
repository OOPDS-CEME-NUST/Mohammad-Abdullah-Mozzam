
#include<iostream>
using namespace std;


struct node
{
	double data1;
	node* upcoming;
};
class link
{
private:
	node* head;
	node* tail;
public:
	link();
	void create_node(double);
	void display();
	void add_first(double);
	void insert_last(double);
	void delete_start();
	void delete_last();
	void delete_add(int, double);
};
int main()
{
	link ob;
	cout << "starting 5 nodes are :\n";
	ob.create_node(25);
	ob.create_node(50);
	ob.create_node(90);
	ob.create_node(40);
	ob.create_node(55);

	ob.display();

	cout << endl;
	cout << "A new node is added in the start  :\n";
	ob.add_first(15);
	cout << endl;
	ob.display();
	cout << endl;	cout << endl;

	cout << "A new node is added in the end  :\n";
	ob.insert_last(10);
	ob.display();
	cout << endl;	cout << endl;

	cout << "1st node is removed  :\n";
	ob.delete_start();
	ob.display();
	cout << endl;	cout << endl;

	cout << "last node is removed  :\n";
	ob.delete_last();
	ob.display();
	cout << endl;	cout << endl;

	cout << "4th node  is removed  and is created at 3rd position :\n";
	ob.delete_add(4, 40);
	ob.display();
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}

link::link()
{
	head = NULL;
	tail = NULL;
}
void link::create_node(double data) {
	node* temp = new node;
	temp->data1 = data;
	temp->upcoming = NULL;
	if (head == NULL) {
		head = temp;
		tail = head;
		temp = NULL;
	}
	else {
		tail->upcoming = temp;
		tail = temp;
	}
}
void link::display() {
	node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << "           ";
		cout << ptr->data1;
		ptr = ptr->upcoming;

	}
}
void link::add_first(double data) {
	node* ptr = new node;
	ptr->data1 = data;
	ptr->upcoming = head;
	head = ptr;
	ptr = NULL;
}
void link::insert_last(double data) {
	node* ptr;
	ptr = head;
	while (ptr->upcoming != NULL)
	{
		ptr = ptr->upcoming;
	}
	node* temp = new node;
	temp->data1 = data;
	temp->upcoming = NULL;
	ptr->upcoming = temp;
	tail = temp;
	temp = NULL;

}
void link::delete_start() {

	node* ptr;
	ptr = head;
	head = ptr->upcoming;
	ptr = NULL;
}
void link::delete_last()
{

	node* pre = NULL;
	node* temp;
	temp = head;
	while (temp->upcoming != NULL)
	{
		pre = temp;
		temp = temp->upcoming;

	}

	tail = pre;
	pre->upcoming = NULL;
	pre = NULL;
	temp = NULL;

}
void link::delete_add(int pos, double data) {
	pos--;
	node* pre = NULL;
	node* temp;
	temp = head;
	for (int i = 1; i <= pos;i++)
	{
		if (i == 3) {

			node* ptr = new node;
			ptr->data1 = data;
			pre->upcoming = NULL;
			pre->upcoming = ptr;
			ptr->upcoming = temp;

		}
		pre = temp;
		temp = temp->upcoming;

	}

	pre->upcoming = NULL;

	pre->upcoming = temp->upcoming;
	temp->upcoming = NULL;
	temp = NULL;
	pre = NULL;


}

