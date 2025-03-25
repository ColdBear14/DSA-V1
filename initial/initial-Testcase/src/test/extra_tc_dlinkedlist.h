/*
 * File:   extra_tc_dlinkedlist.h
 * Author: NTM
 *
 */

#include <iostream>
#include "../../include/list/DLinkedList.h"
#include "../../include/util/Object.h"
#include "tc_checker.h"

using namespace std;

bool extra_tc_dlinkedlist41() {
	Object::reset();
	Object* expect = nullptr;
	string error = "DLinkedList::Constructor";
	try {
		DLinkedList<Object> output;
		return ListChecker<Object>(&output, expect, 0, &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist42() {
	Object::reset();
	Object* expect = nullptr;
	string error = "DLinkedList::Constructor";
	try {
		DLinkedList<Object> output(0, Object::objectEQ);
		return ListChecker<Object>(&output, expect, 0, &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist43() {
	Object::reset();
	Object** expect = nullptr;
	string error = "DLinkedList::Constructor";
	try {
		DLinkedList<Object*> output(DLinkedList<Object*>::free, Object::objectEQ);
		return ListChecker<Object*>(&output, expect, 0, &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist44() {
	Object::reset();
	Object* expect = nullptr;
	string error = "DLinkedList::Destructor";
	try {
		DLinkedList<Object>* output = new DLinkedList<Object>();
		delete output;
		return Memleak(0);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist45() {
	Object::reset();
	Object* expect = nullptr;
	string error = "DLinkedList::Destructor";
	try {
		DLinkedList<Object*>* output = new DLinkedList<Object*>(DLinkedList<Object*>::free, Object::objectEQ);
		delete output;
		return Memleak(0);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist46() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"} };
	string error = "DLinkedList::add";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		
		return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist47() {
	Object::reset();
	int expect = 0;
	string error = "DLinkedList::Destructor";
	try {
		
		try {
			DLinkedList<Object> output;
			output.add({ "400" });
			output.add({ "300" });
			output.add({ "200" });
			output.add({ "100" });
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return Memleak(expect);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist48() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::add";
	try {
		DLinkedList<Object> output(0, 0);
		try {
			output.add(0, expect[2]);
			output.add(1, expect[3]);
			output.add(0, expect[1]);
			output.add(0, expect[0]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist49() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "DLinkedList::add";
	try {
		DLinkedList<Object> output;
		try {
			output.add({ "100" });
			output.add(10, {"100"});
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), expect, error);
		}
		return StringChecker("Index is not out of range!", expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist50() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "DLinkedList::add";
	try {
		DLinkedList<Object> output;
		try {
			output.add(-1, { "100" });
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), expect, error);
		}
		return StringChecker("Index is not out of range!", expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist51() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"} };
	string error = "DLinkedList::removeAt";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.add(expect[2]);
			output.removeAt(3);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}

		return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist52() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::removeAt";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.add(expect[3]);
			output.removeAt(3);
			output.add(expect[3]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist53() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::removeAt";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.removeAt(0);
			output.add(expect[3]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist54() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "DLinkedList::removeAt";
	try {
		DLinkedList<Object> output;
		try {
			output.add({"100"});
			output.removeAt(1);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), expect, error);
		}
		return StringChecker("Index is not out of range!", expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist55() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "DLinkedList::removeAt";
	try {
		DLinkedList<Object> output;
		try {
			output.removeAt(-1);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), expect, error);
		}
		return StringChecker("Index is not out of range!", expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist56() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"} };
	string error = "DLinkedList::removeItem";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[1]);
			output.add(expect[2]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		output.removeItem(expect[1]);
		return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist57() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::removeItem";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.add(expect[3]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return NumberChecker(output.removeItem(expect[1]), 1, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist58() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "DLinkedList::removeItem";
	try {
		DLinkedList<Object*> output(DLinkedList<Object*>::free, Object::objectEQ);
		try {
			output.add(new Object("100"));
			output.add(new Object("100"));
			output.add(new Object("200"));
			output.add(new Object("300"));
			output.add(new Object("400"));
			output.removeItem(expect[0]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return ListChecker<Object*>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist59() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj3 = { "300" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "DLinkedList::removeItem";
	try {
		DLinkedList<Object*> output(0, Object::objectEQ);
		try {
			output.add(&obj1);
			output.add(&obj2);
			output.add(&obj3);
			output.add(&_obj3);
			output.removeItem(&_obj3);
			output.add(&obj4);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return ListChecker<Object*>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist60() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "DLinkedList::removeItem";
	try {
		DLinkedList<Object*> output(DLinkedList<Object*>::free, Object::objectEQ);
		try {
			output.add(new Object("100"));
			output.add(new Object("100"));
			output.add(new Object("200"));
			output.add(new Object("300"));
			output.add(new Object("400"));
			output.removeItem(expect[0], [](Object* obj) { delete obj; });
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return Memleak(8);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist61() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::empty";
	try {
		DLinkedList<Object> output;
		return NumberChecker(output.empty(), 1, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist62() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::empty";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.add(expect[3]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return NumberChecker(output.empty(), 0, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist63() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::size";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.add(expect[3]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return NumberChecker(output.size(), 4, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist64() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::clear";
	try {
		DLinkedList<Object> output;
		try {
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.add(expect[3]);
			output.clear();
			output.add(expect[0]);
			output.add(expect[1]);
			output.add(expect[2]);
			output.add(expect[3]);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist65() {
	Object::reset();
	string error = "DLinkedList::clear";
	try {
		DLinkedList<Object*> output(DLinkedList<Object*>::free);
		try {
			output.add(new Object("100"));
			output.add(new Object("200"));
			output.add(new Object("300"));
			output.add(new Object("400"));
			output.clear();
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return Memleak(0);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist66() {
	Object::reset();
	Object expect = { "300" };
	string error = "DLinkedList::get";
	try {
		DLinkedList<Object> output;
		try {
			output.add({ "100" });
			output.add({ "200" });
			output.add({ "300" });
			output.add({ "400" });
			return StringChecker(output.get(2).getContent(), expect.getContent(), error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist67() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "DLinkedList::get";
	try {
		DLinkedList<Object> output;
		try {
			output.add({ "500" });
			output.add({ "200" });
			output.add({ "300" });
			output.add({ "400" });
			output.get(0) = { "100" };
			return ListChecker<Object>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist68() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "DLinkedList::get";
	try {
		DLinkedList<Object> output;
		try {
			output.add({ "100" });
			output.get(-1);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), expect, error);
		}
		return StringChecker("Index is not out of range!", expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist69() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "DLinkedList::get";
	try {
		DLinkedList<Object> output;
		try {
			output.add({ "100" });
			output.get(5);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), expect, error);
		}
		return StringChecker("Index is not out of range!", expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist70() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj3 = { "300" };
	Object* expect = &obj4;
	string error = "DLinkedList::removeItem + get";
	try {
		DLinkedList<Object*> output(0, Object::objectEQ);
		try {
			output.add(&obj1);
			output.add(&obj2);
			output.add(&obj3);
			output.add(&obj4);
			output.add(&_obj3);
			output.removeItem(&obj3);
			return StringChecker(output.get(2)->getContent(), expect->getContent(), error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist71() {
	Object::reset();
	int expect = 3;
	string error = "DLinkedList::indexOf";
	try {
		DLinkedList<Object> output;
		try {
			output.add({ "100" });
			output.add({ "200" });
			output.add({ "300" });
			output.add({ "400" });
			output.add({ "400" });
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return NumberChecker(output.indexOf({ "400" }), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist72() {
	Object::reset();
	int expect = 1;
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj2 = { "200" };
	string error = "DLinkedList::indexOf";
	try {
		DLinkedList<Object*> output(0, Object::objectEQ);
		try {
			output.add(&obj1);
			output.add(&obj2);
			output.add(&obj3);
			output.add(&obj4);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return NumberChecker(output.indexOf(&_obj2), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist73() {
	Object::reset();
	int expect = 1;
	string error = "DLinkedList::contains";
	try {
		DLinkedList<Object> output;
		try {
			output.add({ "100" });
			output.add({ "200" });
			output.add({ "300" });
			output.add({ "400" });
			output.add({ "400" });
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return NumberChecker(output.contains({ "400" }), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist74() {
	Object::reset();
	int expect = 1;
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj2 = { "200" };
	string error = "DLinkedList::contains";
	try {
		DLinkedList<Object*> output(0, Object::objectEQ);
		try {
			output.add(&obj1);
			output.add(&obj2);
			output.add(&obj3);
			output.add(&obj4);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return NumberChecker(output.contains(&_obj2), 1, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist75() {
	Object::reset();
	string expect = "[100, 200, 300, 400]";
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	string error = "DLinkedList::toString";
	try {
		DLinkedList<Object> output;
		try {
			output.add(obj1);
			output.add(obj2);
			output.add(obj3);
			output.add(obj4);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return StringChecker(output.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist76() {
	Object::reset();
	string expect = "[100, 200, 300, 400]";
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	string error = "DLinkedList::toString";
	try {
		DLinkedList<Object*> output;
		try {
			output.add(&obj1);
			output.add(&obj2);
			output.add(&obj3);
			output.add(&obj4);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return StringChecker(output.toString(Object::object2str), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist77() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "DLinkedList::Copy constructor";
	try {
		DLinkedList<Object*> list(0, Object::objectEQ);
		try {
			list.add(&obj1);
			list.add(&obj2);
			list.add(&obj3);
			list.add(&obj4);
			DLinkedList<Object*> output = list;
			output.removeItem(&obj3);
			output.removeItem(&obj4);
			output.add(2, &obj4);
			output.add(2, &obj3);
			return ListChecker<Object*>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist78() {
	Object::reset();
	string error = "DLinkedList::Copy constructor";
	try {
		DLinkedList<Object*> list(DLinkedList<Object*>::free, Object::objectEQ);
		try {
			list.add(new Object("100"));
			list.add(new Object("200"));
			list.add(new Object("300"));
			list.add(new Object("400"));
			DLinkedList<Object*> output = list;
			list.setDeleteUserDataPtr(0);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return Memleak(0);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist79() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "DLinkedList::Operator =";
	try {
		DLinkedList<Object*> list(0, Object::objectEQ);
		try {
			list.add(&obj1);
			list.add(&obj2);
			list.add(&obj3);
			list.add(&obj4);
			DLinkedList<Object*> output(0, Object::objectEQ);
			output = list;
			output.removeItem(&obj3);
			output.removeItem(&obj4);
			output.add(2, &obj4);
			output.add(2, &obj3);
			return ListChecker<Object*>(&output, expect, sizeof(expect) / sizeof(expect[0]), &Object::object2str, &Object::objectEQ, error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_dlinkedlist80() {
	Object::reset();
	string error = "DLinkedList::Operator =";
	try {
		DLinkedList<Object*> list(DLinkedList<Object*>::free, Object::objectEQ);
		try {
			list.add(new Object("100"));
			list.add(new Object("200"));
			list.add(new Object("300"));
			list.add(new Object("400"));
			DLinkedList<Object*> output(DLinkedList<Object*>::free, Object::objectEQ);
			output.add(new Object("500"));
			output = list;
			list.setDeleteUserDataPtr(0);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is not out of range!", error);
		}
		return Memleak(0);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}