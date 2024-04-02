#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <hash_map>
#include <hash_set>
using namespace std;
#pragma region MyRegion

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
#pragma endregion




int main()
{
#pragma region MyRegion

	vector<int> test{ 1, 5, 1, 3, 2, 3, 8 };
	
	for (auto item : duplicateValues(test))
	{
		cout << item << endl;
	}
	
	for (auto i : dublicatesValues2(test))
	{
		cout << i.first << " : " << i.second << endl;
	}
#pragma endregion

	hash_set<int> hset1;
	hset1.bucket(50);
	hset1.insert(5);
	/* 
		если есть порядок данных list<>, forward_list<>, vector<>
		если известно количесво данных vector<>
		если порядок добавления не важен set<>, map<>, hash_set<>, hash_map<>
		если необходимо добавлять значение в конец list<>, или forward_list<>
		если непонятно какую структуру взять то лучше выбрать set<> или map<>
		^^^
		|||
		если нужно хранить небольшое кол-во значений hash_set<>, hash_map<>
	*/

}