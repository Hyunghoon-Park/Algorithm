#include <iostream>
#include <deque>
#include <queue>
using namespace std;
deque<int> dq;
queue<int> q;
int main() {
	int n, m, tmp;
	int cnt = 0;	//Ƚ�� ����
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		dq.push_back(i);	//deque�� 1���� �Է°����� ����
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);	
		q.push(tmp);	//queue�� ã�ƾ��� ���� ����Ʈ�� ����
	}
	while (q.size() != 0) {	//while�� ���������� ã�ƾ��� ���� ����Ʈ�� q�� ���̻� ������
		tmp = q.front();	//queue�� ���� �տ��ִ� ���� ����
		q.pop();			//queue�� ���� �տ��ִ� ���� pop
		for (int i = 0; i < dq.size(); i++) {	
			if (dq[i] == tmp) {	//dq.at()�� ����Ҽ��� ����, for ������ ã�ƾ��� ���ڿ� ��ġ�ϸ� if�� ������ ����
				if (i <= dq.size() / 2) {	//i �� dq�� ũ�⺸�� �۰ų� ������ ���ʿ������� ���ڸ� �̾Ƽ� ���������� ����
					for (int j = 0; j < i; j++) {	//ã�ƾ��� ���ڰ� ���� ���ʿ� �� �� ���� �ݺ�
						tmp = dq.front();
						dq.pop_front();
						dq.push_back(tmp);
						cnt++;
					}
					dq.pop_front();	// �ش���� pop
					break;
				}
				else {	//�ƴҰ�� �����ʿ��� �������� ���ڸ� �ű�
					for (int j = dq.size() - 1; j >= i; j--) {	//ã�ƾ��� ���ڰ� ���� ���ʿ� �� �� ���� �ݺ�
						tmp = dq.back();
						dq.pop_back();
						dq.push_front(tmp);
						cnt++;
					}
					dq.pop_front(); // �ش���� pop
					break;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}