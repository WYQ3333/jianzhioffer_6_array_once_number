//一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。
//请写程序找出这两个只出现一次的数字。

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		sort(data.begin(), data.end());//对数组进行排序
		//从有序数组中找到只出现一次的数字
		int pre = 0;
		int cur = 1;
		int flag = 0;
		while (cur < data.size()){
			if (cur+2<data.size()&&data[pre] == data[cur]){
				pre += 2;
				cur += 2;
			}
			else if (cur + 2 <data.size() && data[pre] != data[cur]){
				if (flag == 0){
					flag = 1;
					*num1 = data[pre];
				}
				else if (flag == 1){
					*num2 = data[pre];
					break;
				}
				pre += 1;
				cur += 1;
			}
			else if (cur + 2 == data.size()){
				if (flag == 0){
					pre += 2;
					cur += 2;
					*num1 = data[pre];
					*num2 = data[cur];
					break;
				}
				else if (flag == 1){
					pre += 2;
					*num2 = data[pre];
					break;
				}
			}
			else if (cur + 1 == data.size()){
				if (flag == 0){
					pre += 1;
					cur += 1;
					*num1 = data[pre];
					*num2 = data[cur];
					break;
				}
				else if (flag == 1){
					pre += 1;
					*num2 = data[pre];
					break;
				}
			}
		}
	}
};

int main(){
	Solution s;
	int a = 0;
	int b = 0;
	vector<int> array = { 2, 4, 3, 6, 3, 2};
	s.FindNumsAppearOnce(array, &a, &b);
	cout << a << " " << endl;
	cout << b << " " << endl;
	system("pause");
	return 0;
}
