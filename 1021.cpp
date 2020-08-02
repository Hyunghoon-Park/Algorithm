#include <iostream>
#include <deque>
#include <queue>
using namespace std;
deque<int> dq;
queue<int> q;
int main() {
	int n, m, tmp;
	int cnt = 0;	//횟수 저장
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		dq.push_back(i);	//deque에 1부터 입력값까지 저장
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);	
		q.push(tmp);	//queue에 찾아야할 숫자 리스트를 저장
	}
	while (q.size() != 0) {	//while의 종료조건은 찾아야할 숫자 리스트인 q가 더이상 없을때
		tmp = q.front();	//queue의 가장 앞에있는 숫자 저장
		q.pop();			//queue에 가장 앞에있는 숫자 pop
		for (int i = 0; i < dq.size(); i++) {	
			if (dq[i] == tmp) {	//dq.at()를 사용할수도 있음, for 문에서 찾아야할 숫자와 일치하면 if문 안으로 들어옴
				if (i <= dq.size() / 2) {	//i 가 dq의 크기보다 작거나 같으면 왼쪽에서부터 숫자를 뽑아서 오른쪽으로 붙임
					for (int j = 0; j < i; j++) {	//찾아야할 숫자가 가장 왼쪽에 올 때 까지 반복
						tmp = dq.front();
						dq.pop_front();
						dq.push_back(tmp);
						cnt++;
					}
					dq.pop_front();	// 해당숫자 pop
					break;
				}
				else {	//아닐경우 오른쪽에서 왼쪽으로 숫자를 옮김
					for (int j = dq.size() - 1; j >= i; j--) {	//찾아야할 숫자가 가장 왼쪽에 올 때 까지 반복
						tmp = dq.back();
						dq.pop_back();
						dq.push_front(tmp);
						cnt++;
					}
					dq.pop_front(); // 해당숫자 pop
					break;
				}
			}
		}
	}
	printf("%d", cnt);
	return 0;
}