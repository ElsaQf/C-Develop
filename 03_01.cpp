//������3�������е��ظ�����

//��Ŀһ���ҳ������е��ظ����� 
//��һ������Ϊn����������������ֶ���0~n-1��Χ�ڡ�
//������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ����Ρ�
//���ҳ�����������һ���ظ�����
//���磺 
//������볤��Ϊ7������{2,3,1,0,2,5,3},
//��ô��Ӧ����ظ�����2����3 

//����һ��sort ʱ�临�Ӷ�O(nlogn) 
//��������hash ʱ�临�Ӷ�O(n) 
//	�ı�����˳�򣬿ռ临�Ӷ�O(1)
//	�½����飬��ԭ������������ŵ��������У��ռ临�Ӷ�O(n) 


#include <iostream>
#include <algorithm>
using namespace std;

//��֤�Ƿ���0~n-1
bool isValid(int nums[], int n){
	for(int i = 0; i < n; i++){
		if(nums[i] < 0 || nums[i] > n-1){
			return false;
		}
	}
	return true;
}

//����һ������ʱ�临�Ӷ�O(nlogn)
vector<int> duplication_sort(int nums[], int n){
	sort(nums, nums+n);
	vector<int> dups;
	for(int i = 1; i < n; i++){
		if(nums[i] == nums[i-1]){
			dups.push_back(nums[i]);
		}
	}
	return dups;
}
// ֻ���һ���ظ����� 
void Test1(){
	int nums[8] = {2,3,1,0,2,5,3,3};
	if(isValid(nums, 8)){
		vector<int> dup = duplication_sort(nums, 8);
		dup.erase(unique(dup.begin(), dup.end()), dup.end());//ȥ��dup�е��ظ����֣�ֻ���һ�� 
		for(int i = 0; i < dup.size(); i++){
			cout << dup[i] << " ";
		}
	}
}

// ����������ϣ��ʱ�临�Ӷ�O(n)
// �ռ临�Ӷ�O(1)���ı�����˳�� 
vector<int> duplication_hash(int nums[], int n){
	vector<int> dups;
	for(int i = 0; i < n; i++){
		if(nums[i] != i){
			if(nums[i] != nums[nums[i]]){
				while(nums[i] != nums[nums[i]]){
					int temp = nums[i];
					nums[i] = nums[temp];
					nums[temp] = temp;
				}
			}else{
				dups.push_back(nums[i]);
			}
		}
	}
	return dups;
}
// �ռ临�Ӷ�O(n)����Ҫ���������ռ� 
vector<int> duplication_hash2(int nums[], int n){
	int nums2[n];
	vector<int> dups;
	for(int i = 0; i < n; i++){
		nums2[i] = -1;
	}
	for(int i = 0; i < n; i++){
		int j = nums[i];
		if(nums2[j] == -1){
			nums2[j] = j;
		}else{
			dups.push_back(j);
		}
	}
	return dups;
} 


void Test2(){
	int nums[8] = {2,3,1,0,2,5,3,3};
	if(isValid(nums, 8)){
		vector<int> dup = duplication_hash2(nums, 8);
//		dup.erase(unique(dup.begin(), dup.end()), dup.end());//ȥ��dup�е��ظ����֣�ֻ���һ�� 
		for(int i = 0; i < dup.size(); i++){
			cout << dup[i] << " ";
		}
	}
}
 


int main(){
	Test2();
	
	return 0;
}
