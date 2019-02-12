#include <iostream>
using namespace std;

class node {
public:
	int num;
	node *next;
};
void del(int m, node *head);

int main()
{
	node *head,*p, *q;
	int n, m, k, i;

	cin >> n >> m >> k;

	head = p = new node;
	p->num = 1;
	for (i = 1; i < n; ++i) {
		q = new node;
		q->num = i + 1;
		p->next = q;
		p = q;
	}
	p->next = head;

	i = 0;
	while (i < k - 1) {
		head = head->next;
		i++;
	}

	del(m, head);
	return 0;
}


void del(int m, node *head) {
	node *p, *q;
	int i;
	p = new node;
	q = new node;
	q = head;

	while (q->next != q) {
		i = 0;
		while (i < m - 2) {
			q = q->next;
			i++;
		}
		p = q->next;
		q->next = p->next;
		cout << p->num << " ";
		delete p;
		q = q->next;
	}
	cout << q->num;
	delete q;
}