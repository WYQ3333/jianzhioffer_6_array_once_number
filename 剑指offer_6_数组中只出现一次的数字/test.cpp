//һ�����������������������֮�⣬���������ֶ�������ż���Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		sort(data.begin(), data.end());//�������������
		//�������������ҵ�ֻ����һ�ε�����
		int i = 0;
		int j = 1;
		int flag = 0;
		while (j < data.size()){
			if (j+2<data.size()&&data[i] == data[j]){
				i += 2;
				j += 2;
			}
			else if (flag==0&&j + 1 < data.size() && data[i] != data[j]){
				*num1 = data[i];
				flag = 1;
				i += 1;
				j += 1;
			}
			else if (flag == 1 && j + 1 < data.size() && data[i] != data[j]){
				*num2 = data[i];
				flag = 2;
				i += 1;
				j += 1;
			}
			else if (flag==1&&j + 1 == data.size() && i + 1 == data.size() - 1){
				*num2 = data[i];
			}
		}

	}
};

int main(){
	Solution s;
	int a = 0;
	int b = 0;
	vector<int> array = { 2, 4, 3, 6, 3, 2, 5, 5 };
	s.FindNumsAppearOnce(array, &a, &b);
	cout << a << " " << endl;
	cout << b << " " << endl;
	system("pause");
	return 0;
}
