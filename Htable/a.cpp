#include "htable.h"
int main()
{
	try
	{
		htable<string> table(10);
		pair<string, string> test1;
		pair<string, string> test2;
		pair<string, string> test11;
		test1 = make_pair("Aram", "01251500");
		test2 = make_pair("Artur","111111111");
		test11 = make_pair("Aram", "222222222");
		table.insert(test1);
		table.insert(test2);
		table.insert(test11);
		table.printElement("Aram");
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}