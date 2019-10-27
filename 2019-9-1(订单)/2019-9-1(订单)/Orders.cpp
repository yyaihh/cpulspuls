#include "Orders.h"

Orders::Orders() {
	m_size = 0;
}

double Orders::count(int n) {
	double sum = 0;
	double m = 0;
	cout << "������۸�ϵ��\n";
	cin >> m;
	for (int i = 1; i <= n; ++i) {
		cout << "�������Ʒ" << i << "������\n";
		cin >> m_size;
		sum += m_size * m_s_OriginalCost[i] * m;
	}
	return sum;
}
void Orders::input(int n) {
	if (m_s_OriginalCost == nullptr) {
		m_s_OriginalCost = new double[n + 1];
	}
	else if (n > m_s_OriginalCost[0]) {
		Free();
		m_s_OriginalCost = new double[n + 1];
	}
	m_s_OriginalCost[0] = n;
	for (int i = 1; i <= n; ++i) {
		cout << "�������Ʒ" << i << "��ԭ��\n";
		cin >> m_s_OriginalCost[i];
	}
}
void Orders::Free() {
	delete m_s_OriginalCost;
}
Orders::~Orders() {
}
double* Orders::m_s_OriginalCost = nullptr;