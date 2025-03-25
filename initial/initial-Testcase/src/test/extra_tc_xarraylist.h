/*
 * File:   extra_tc_xarraylist.h
 * Author: NTM
 *
 */

#include <iostream>
#include "../../include/list/XArrayList.h"
#include "../../include/util/Object.h"
#include "tc_checker.h"

using namespace std;

bool extra_tc_xarraylist1() {
	Object::reset();
	Object* expect = nullptr;
	string error = "XArrayList::Constructor";
	try {
		XArrayList<Object> output;
		return ListChecker<Object>(&output, expect, 0, &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_xarraylist2() {
	Object::reset();
	Object* expect = nullptr;
	string error = "XArrayList::Constructor";
	try {
		XArrayList<Object> output(0, Object::objectEQ, 5);
		return ListChecker<Object>(&output, expect, 0, &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_xarraylist3() {
	Object::reset();
	Object** expect = nullptr;
	string error = "XArrayList::Constructor";
	try {
		XArrayList<Object*> output(XArrayList<Object*>::free, Object::objectEQ, 5);
		return ListChecker<Object*>(&output, expect, 0, &Object::object2str, &Object::objectEQ, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_xarraylist4() {
	Object::reset();
	Object* expect = nullptr;
	string error = "XArrayList::Destructor";
	try {
		XArrayList<Object>* output = new XArrayList<Object>();
		delete output;
		return Memleak(0);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_xarraylist5() {
	Object::reset();
	Object* expect = nullptr;
	string error = "XArrayList::Destructor";
	try {
		XArrayList<Object*>* output = new XArrayList<Object*>(XArrayList<Object*>::free, Object::objectEQ, 5);
		delete output;
		return Memleak(0);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_xarraylist6() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"} };
	string error = "XArrayList::add";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist7() {
	Object::reset();
	int expect = 0;
	string error = "XArrayList::Destructor";
	try {
		try {
			XArrayList<Object> output;
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

bool extra_tc_xarraylist8() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::add";
	try {
		XArrayList<Object> output(0, 0, 2);
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

bool extra_tc_xarraylist9() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "XArrayList::add";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist10() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "XArrayList::add";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist11() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"} };
	string error = "XArrayList::removeAt";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist12() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::removeAt";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist13() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::removeAt";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist14() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "XArrayList::removeAt";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist15() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "XArrayList::removeAt";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist16() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"} };
	string error = "XArrayList::removeItem";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist17() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::removeItem";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist18() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "XArrayList::removeItem";
	try {
		XArrayList<Object*> output(XArrayList<Object*>::free, Object::objectEQ);
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

bool extra_tc_xarraylist19() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj3 = { "300" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "XArrayList::removeItem";
	try {
		XArrayList<Object*> output(0, Object::objectEQ, 1);
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

bool extra_tc_xarraylist20() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "XArrayList::removeItem";
	try {
		XArrayList<Object*> output(XArrayList<Object*>::free, Object::objectEQ, 1);
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

bool extra_tc_xarraylist21() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::empty";
	try {
		XArrayList<Object> output;
		return NumberChecker(output.empty(), 1, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_xarraylist22() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::empty";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist23() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::size";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist24() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::clear";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist25() {
	Object::reset();
	string error = "XArrayList::clear";
	try {
		XArrayList<Object*> output(XArrayList<Object*>::free);
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

bool extra_tc_xarraylist26() {
	Object::reset();
	Object expect = { "300" };
	string error = "XArrayList::get";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist27() {
	Object::reset();
	Object expect[] = { {"100"}, {"200"}, {"300"}, {"400"} };
	string error = "XArrayList::get";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist28() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "XArrayList::get";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist29() {
	Object::reset();
	string expect = "Index is out of range!";
	string error = "XArrayList::get";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist30() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj3 = { "300" };
	Object* expect = &obj4;
	string error = "XArrayList::removeItem + get";
	try {
		XArrayList<Object*> output(0, Object::objectEQ);
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

bool extra_tc_xarraylist31() {
	Object::reset();
	int expect = 3;
	string error = "XArrayList::indexOf";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist32() {
	Object::reset();
	int expect = 1;
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj2 = { "200" };
	string error = "XArrayList::indexOf";
	try {
		XArrayList<Object*> output(0, Object::objectEQ);
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

bool extra_tc_xarraylist33() {
	Object::reset();
	int expect = 1;
	string error = "XArrayList::contains";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist34() {
	Object::reset();
	int expect = 1;
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object _obj2 = { "200" };
	string error = "XArrayList::contains";
	try {
		XArrayList<Object*> output(0, Object::objectEQ);
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

bool extra_tc_xarraylist35() {
	Object::reset();
	string expect = "[100, 200, 300, 400]";
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	string error = "XArrayList::toString";
	try {
		XArrayList<Object> output;
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

bool extra_tc_xarraylist36() {
	Object::reset();
	string expect = "[100, 200, 300, 400]";
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	string error = "XArrayList::toString";
	try {
		XArrayList<Object*> output;
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

bool extra_tc_xarraylist37() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "XArrayList::Copy constructor";
	try {
		XArrayList<Object*> list(0, Object::objectEQ);
		try {
			list.add(&obj1);
			list.add(&obj2);
			list.add(&obj3);
			list.add(&obj4);
			XArrayList<Object*> output = list;
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

bool extra_tc_xarraylist38() {
	Object::reset();
	string error = "XArrayList::Copy constructor";
	try {
		XArrayList<Object*> list(XArrayList<Object*>::free, Object::objectEQ);
		try {
			list.add(new Object("100"));
			list.add(new Object("200"));
			list.add(new Object("300"));
			list.add(new Object("400"));
			XArrayList<Object*> output = list;
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

bool extra_tc_xarraylist39() {
	Object::reset();
	Object obj1 = { "100" };
	Object obj2 = { "200" };
	Object obj3 = { "300" };
	Object obj4 = { "400" };
	Object* expect[] = { &obj1, &obj2, &obj3, &obj4 };
	string error = "XArrayList::Operator =";
	try {
		XArrayList<Object*> list(0, Object::objectEQ);
		try {
			list.add(&obj1);
			list.add(&obj2);
			list.add(&obj3);
			list.add(&obj4);
			XArrayList<Object*> output(0, Object::objectEQ);
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

bool extra_tc_xarraylist40() {
	Object::reset();
	string error = "XArrayList::Operator =";
	try {
		XArrayList<Object*> list(XArrayList<Object*>::free, Object::objectEQ);
		try {
			list.add(new Object("100"));
			list.add(new Object("200"));
			list.add(new Object("300"));
			list.add(new Object("400"));
			XArrayList<Object*> output(XArrayList<Object*>::free, Object::objectEQ);
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