//Matthew Avallone
#include <list>
#include <iostream>
using namespace std;

typedef list<char>::iterator LCI; //allows us to use LCI instead of typing out rest
auto x = 3; //makes every x automatically equal to 3

template <typename fred, typename george> //creates a variable that has no type but allows us to create a "cookie cutter" type function
fred myFind(fred start, fred end, george target) {
	return end;
}

list<char> lc = { 17, 38 };
//begin(), end() return iterators of the same type as the data structure
for (LCI iter = lc.begin(); iter != lc.end(); ++iter) {
	cout << *iter << endl;
}

auto result = find_if(lc.begin(), lc.end(), isEven);
template <typename fred, class velma>
bool find_if(fred start, fred stop, [](int n)->bool {return n % 2 == 0;}) { //bool return type in lamda expression is unnecessary
	return true;
}