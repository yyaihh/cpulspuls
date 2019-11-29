#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<functional>
#include<list>
using namespace std;
class PCB {
	static int id;
public:
	string m_pname;
	int Tarrive;//����ʱ��
	int Tservice;//����ʱ��
	int Tsurplus;//ʣ��ʱ��
	int Tstart;//��ʼʱ��
	int Taccomplish;//���ʱ��
	int prio;//���ȼ�---����Խ�����ȼ�Խ��
	int if_finish;//�����Ƿ����
	int num;//���̸���
	bool operator >(const PCB& p)const {
		return this->Tarrive > p.Tarrive;
	}
};
priority_queue<PCB, vector<PCB>, greater<PCB>> fcfs(vector<PCB>& vp) {
	priority_queue<PCB, vector<PCB>, greater<PCB>> pq(vp.rbegin(), vp.rend());
	return pq;
}
list<PCB> RR(priority_queue<PCB, vector<PCB>, greater<PCB>>& pq) { 
	list<PCB> l;
	size_t T;
	cout << "������ʱ��Ƭ\n";
	cin >> T;
	while (!pq.empty()) {
		l.push_back(pq.top());
		pq.pop();
	}
	for (auto i = l.begin(); !l.empty(); ++i) {

	}
}
void print(const PCB& p) {
	cout << "������" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t" << "���ʱ��" << endl;
	cout << p.m_pname << '\t' << p.Tarrive << "\t\t" << p.Tservice << "\t\t" << p.Taccomplish<<endl;
}
void print2(int num){
	cout << "������" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t" << "���ʱ��" << endl;
	for (int i = 0; i < num; i++){
		
	}
}
int MENU() {
	int n;
	cout << "��������������������������������������������������" << endl;
	cout << "��������������������1��FCFS�㷨 ������������������" << endl;
	cout << "��������������������2��RR�㷨 ��������������������" << endl;
	cout << "��������������������0���˳� ����������������������" << endl;
	cout << "��������������������������������������������������" << endl;
	cin >> n;
	return n;
}
void input(vector<PCB>& vp) {
	for (auto& i : vp) {
		cout << "�����������������ʱ�䡢����ʱ��" << endl;
		cin >> i.m_pname;
		cin >> i.Tarrive;
		cin >> i.Tservice;
	}
}
int main() {
	int num;
	cout << "��������̸���\n";
	cin >> num;
	vector<PCB> vp(num);
	input(vp);
	priority_queue<PCB, vector<PCB>, greater<PCB>> pq1 = fcfs(vp);
	priority_queue<PCB, vector<PCB>, greater<PCB>> pq2 = pq1;
	while (1) {
		switch (MENU()) {
		case 1:
			while (!pq1.empty()) {
				print(pq1.top());
				pq1.pop();
			}
			break;
		case 2:
			
			break;
		case 0:
			cout << "�˳�!\n";
			break;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}