
#ifndef CIRCLE_TABLE_H
#define CIRCLE_TABLE_H
struct NODE{
	int data;
	NODE* nextNode;
	NODE(int _data) {
		data = _data;
		nextNode = nullptr;
	}
};
struct CIRCLE_TABLE {
	NODE* next;
};
CIRCLE_TABLE table;
void initAllTable(CIRCLE_TABLE& a, int n) {
	for (int i = 1; i <= n; i++) {
		NODE* newNode = new NODE(i);
		NODE* temp = a.next;
		while ((*temp).nextNode != nullptr) {
			temp = (*temp).nextNode;
		}
		(*temp).nextNode = newNode;
	}
}     

void passTable(CIRCLE_TABLE& table, int n, int m) {
	NODE* temp = table.next;
	while (n > 1) {
		for (int i = 1; i < m - 1; i++) {
			if(temp == nullptr) temp = table.next;
			else temp = (*temp).nextNode;
		}
		(*temp).nextNode = (*(*temp).nextNode).nextNode;
		delete (*temp).nextNode;
		n--;
	}
}

#endif // !CIRCLE_TABLE_H

