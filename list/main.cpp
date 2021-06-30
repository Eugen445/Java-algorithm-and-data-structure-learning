#include <iostream>
#include <string>
#include <list>
#include <mutex>
#include <memory>
#include <xmemory>
#include "list.h"

using namespace std;



class widget {
public:
	widget(int *lhs = nullptr)
	:p(lhs)
	{}

	/*给自己赋值会出错
	widget& operator=(const widget& lhs) {
		delete p;
		p = lhs.p;
		return *this;
	}*/

	widget& operator=(const widget& lhs) {

		if (this != &lhs) {

			delete p;
			p = lhs.p;
		}

		return *this;
	}
private:
	int *p;
};

int main()
{
	List<int> arr;
	for (int i = 0; i < 10; ++i)
		arr.push_back(i);

	list<int> arr2;
	for (int i = 0; i < 10; ++i)
		arr2.push_back(i);

	return 0;
}