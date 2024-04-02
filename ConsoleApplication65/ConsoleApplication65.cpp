#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>

using namespace std;
//поиск дубликатов
//функция принимает массив, а возвращает bool

bool duplicates(const vector<int>& arr) //O(N^2) - временная o(1) - сложность по памяти 
{
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] == arr[j]) return true;
		}
	}
	return false;
}
bool duplicates1(const vector<int>& arr) // O(N) - временная O (N/2) - сложность по памяти 
{
	set<int> tempSet;
	for (auto i : arr)
	{
		tempSet.insert(i);
	}
	/*if (arr.size() > tempSet.size()) return true;
	else return false;*/
	return arr.size() > tempSet.size();
}
// O(N^2) - временная сложность  O(N/2) - сложность по памяти 
vector<int> duplicateValues(const vector<int>& arr)
{
	vector<int> result;
	result.reserve(arr.size() / 2);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] == arr[j]) result.push_back(arr[i]);
		}
	}
	return result;
}


// O(N) - временная, O(N/2) - по памяти 
map<int, int> dublicatesValues2(const vector<int>& arr)
{
	// значение из вектора : кол-во 
	map<int, int> result;
	for (auto item : arr)
	{
		result[item] += 1;
	}
	return result;
}

int main()
{
	vector<int> test{ 1, 5, 1, 3, 2, 3, 8 };
	/*for (auto item : duplicateValues(test))
	{
		cout << item << endl;
	}*/

	for (auto i : dublicatesValues2(test))
	{
		cout << i.first << " : " << i.second << endl;
	}
}
