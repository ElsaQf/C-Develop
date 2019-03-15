//������4����ά�����еĲ���
//��Ŀ����һ����ά�����У�ÿһ�д����ҵ�����ÿһ�д��ϵ��µ���
//�����һ������������һ����ά�����һ���������ж��������Ƿ��и����� 

// �����������Ͻǿ�ʼ��
//target<a[i][j] -> ������ j-- 
//target>a[i][j] -> ������ i++ 

#include <iostream>
using namespace std;

bool Find(int *matrix, int rows, int cols, int n){
	int row = 0, col = cols - 1;
	while(row < rows && col >= 0){
		if(n == matrix[row*cols+col]){
			return true;
		}else if(n < matrix[row*cols+col]){
			col--;
		}else{
			row++;
		}
	}
	return false;
}

int main(){
	int matrix[][4] = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
	int i = 10;
	bool found = Find((int *)matrix, 4, 4, i);
	if(found){
		cout << "Found";
	}else{
		cout << "Not Found";
	}
	return 0;
}
