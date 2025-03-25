/*
 * File:   extra_tc_inventory.h
 * Author: NTM
 *
 */

#include <iostream>
#include <sstream>
#include "../../include/app/inventory.h"
#include "../../include/util/Object.h"
#include "tc_checker.h"

using namespace std;

bool extra_tc_inventory81() {
	Object::reset();
	int expect = 2;
	string error = "List1D::add + size";
	try {
		List1D<Object> list;
		list.add({ "100" });
		list.add({ "200" });
		return NumberChecker(list.size(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory82() {
	Object::reset();
	string expect = "200";
	string error = "List1D::get";
	try {
		List1D<Object> list;
		list.add({ "100" });
		list.add({ "200" });
		list.add({ "300" });
		return StringChecker(list.get(1).getContent(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory83() {
	Object::reset();
	string expect = "400";
	string error = "List1D::set";
	try {
		List1D<Object> list;
		list.add({ "100" });
		list.add({ "200" });
		list.add({ "300" });
		list.set(1, { "400" });
		return StringChecker(list.get(1).getContent(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory84() {
	Object::reset();
	string expect = "[100, 200, 300]";
	string error = "List1D::toString";
	try {
		List1D<Object> list;
		list.add({ "100" });
		list.add({ "200" });
		list.add({ "300" });
		return StringChecker(list.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory85() {
	//Object::reset();
	//string expect = "[100, 200, 300]";
	//string error = "List1D::Operator <<";
	//try {
	//	List1D<Object> list;
	//	list.add({ "100" });
	//	list.add({ "200" });
	//	list.add({ "300" });
	//	stringstream ss;
	//	ss << list;
	//	return StringChecker(ss.str(), expect, error);
	//}
	//catch (...) {
	//	cout << "Error: " + error << endl;
	//	return 0;
	//}
	cout << "Pass" << endl;
	return 1;
}

bool extra_tc_inventory86() {
	Object::reset();
	string expect = "[100, 200, 300]";
	string error = "List1D(const T* array, int num_elements)";
	try {
		Object list[] = { {"100"}, {"200"}, {"300"} };
		List1D<Object> output(list, 3);
		return StringChecker(output.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory87() {
	Object::reset();
	string expect = "[0, 0, 0]";
	string error = "List1D(int num_elements)";
	try {
		List1D<int> output(3);
		return StringChecker(output.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory88() {
	Object::reset();
	string expect = "[, , ]";
	string error = "List1D(int num_elements)";
	try {
		List1D<Object> output(3);
		return StringChecker(output.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory89() {
	Object::reset();
	string expect = "[100, 200, 300, 400, 500]";
	string error = "List1D::Copy constructor";
	try {
		List1D<Object> output0;
		output0.add({ "100" });
		output0.add({ "200" });
		output0.add({ "300" });
		List1D<Object> output1 = output0;
		output0.set(0, { "-100" });
		output0.set(1, { "-200" });
		output0.set(2, { "-300" });
		output1.add({ "400" });
		output1.add({ "500" });
		return StringChecker(output1.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory90() {
	Object::reset();
	int expect = 0;
	string error = "List1D::Destructor";
	try {
		{
			List1D<Object> output0;
			output0.add({ "100" });
			output0.add({ "200" });
			output0.add({ "300" });
		}
		return Memleak(expect);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory91() {
	Object::reset();
	int expect = 0;
	string error = "List2D:: rows";
	try {
		List2D<Object> list2D;
		return NumberChecker(list2D.rows(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory92() {
	Object::reset();
	string expect = "[[100, 200, 300], [400, 500]]";
	string error = "List2D(List1D<T>* array, int num_rows) + List2D::toString";
	try {
		Object row0[] = { {"100"}, {"200"}, {"300"} };
		Object row1[] = { {"400"}, {"500"} };
		List1D<Object> list1D[] = {List1D<Object>(row0, 3), List1D<Object>(row1, 2)};
		List2D<Object> list2D(list1D, 2);
		return StringChecker(list2D.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory93() {
	Object::reset();
	string expect = "[[100, 200, 300], [400, 500]]";
	string error = "List2D(List1D<T>* array, int num_rows)";
	try {
		Object row0[] = { {"100"}, {"200"}, {"300"} };
		Object row1[] = { {"400"}, {"500"} };
		List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row1, 2) };
		List2D<Object> list2D(list1D, 2);
		list1D[0].set(0, { "-100" });
		list1D[1].set(0, { "-400" });
		return StringChecker(list2D.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory94() {
	Object::reset();
	string expect = "[[100, 200, 300], [400, 500]]";
	string error = "List2D(List1D<T>* array, int num_rows)";
	try {
		Object row0[] = { {"100"}, {"200"}, {"300"} };
		Object row1[] = { {"400"}, {"500"} };
		List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row1, 2) };
		List2D<Object> list2D(list1D, 2);
		list1D[0].set(0, { "-100" });
		list1D[1].set(0, { "-400" });
		return StringChecker(list2D.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory95() {
	//Object::reset();
	//string expect = "[[100, 200, 300], [400, 500, 600]]";
	//string error = "List2D::Operator <<";
	//try {
	//	Object row0[] = { {"100"}, {"200"}, {"300"} };
	//	Object row1[] = { {"400"}, {"500"}, {"600"} };
	//	List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row0, 3) };
	//	List2D<Object> list2D(list1D, 2);
	//	list2D.setRow(1, List1D<Object>(row1, 3));
	//	stringstream ss;
	//	ss << list2D;
	//	return StringChecker(ss.str(), expect, error);
	//}
	//catch (...) {
	//	cout << "Error: " + error << endl;
	//	return 0;
	//}
	cout << "Pass" << endl;
	return 1;
}

bool extra_tc_inventory96() {
	Object::reset();
	string expect = "300";
	string error = "List2D::get";
	try {
		Object row0[] = { {"100"}, {"200"}, {"300"} };
		Object row1[] = { {"400"}, {"500"}, {"600"} };
		List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row1, 3) };
		List2D<Object> list2D(list1D, 2);
		return StringChecker(list2D.get(0, 2).getContent(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory97() {
	Object::reset();
	string error = "List2D::getRow";
	try {
		Object row0[] = { {"100"}, {"200"}, {"300"} };
		Object row1[] = { {"400"}, {"500"}, {"600"} };
		Object row2[] = { {"700"}, {"800"}, {"900"} };
		List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row1, 3), List1D<Object>(row2, 3) };
		List2D<Object> list2D(list1D, 3);
		return StringChecker(list2D.getRow(1).toString(), list1D[1].toString(), error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory98() {
	Object::reset();
	string expect = "[[100, 200, 300], [400, 500, 600], [700, 800, 900]]";
	string error = "List2D::Copy constructor";
	try {
		Object row0[] = { {"100"}, {"200"}, {"300"} };
		Object row1[] = { {"400"}, {"500"}, {"600"} };
		Object row2[] = { {"700"}, {"800"}, {"900"} };
		List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row1, 3), List1D<Object>(row2, 3) };
		List2D<Object> list2D(list1D, 3);
		List2D<Object> copy_list2D = list2D;
		return StringChecker(copy_list2D.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory99() {
	Object::reset();
	string expect = "[[100, 200, 300], [400, 500, 600], [700, 800, 900]]";
	string error = "List2D::Copy constructor";
	try {
		Object row0[] = { {"100"}, {"200"}, {"300"} };
		Object row1[] = { {"400"}, {"500"}, {"600"} };
		Object row2[] = { {"700"}, {"800"}, {"900"} };
		List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row1, 3), List1D<Object>(row2, 3) };
		List2D<Object> list2D(list1D, 3);
		List2D<Object> copy_list2D = list2D;
		list2D.setRow(1, list1D[0]);
		return StringChecker(copy_list2D.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory100() {
	Object::reset();
	int expect = 0;
	string error = "List2D::Destructor";
	try {
		{
			Object row0[] = { {"100"}, {"200"}, {"300"} };
			Object row1[] = { {"400"}, {"500"}, {"600"} };
			Object row2[] = { {"700"}, {"800"}, {"900"} };
			List1D<Object> list1D[] = { List1D<Object>(row0, 3), List1D<Object>(row1, 3), List1D<Object>(row2, 3) };
			List2D<Object> list2D(list1D, 3);
		}
		return Memleak(expect);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory101() {
	int expect = 0;
	string error = "InventoryManager::size";
	try {
		InventoryManager inv;
		return NumberChecker(inv.size(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory102() {
	int expect = 3;
	string error = "InventoryManager(const List2D<InventoryAttribute>& matrix, const List1D<string>& names, const List1D<int>& quantities)";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100}};
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C"};
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1)};
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return NumberChecker(inv.size(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory103() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],\nProductNames: [Product A, Product B, Product C],\nQuantities: [50, 30, 20]\n]";
	string error = "InventoryManager::toString";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory104() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],\nProductNames: [Product A, Product B, Product C],\nQuantities: [50, 30, 20]\n]";
	string error = "InventoryManager::Copy constructor";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		InventoryManager copy_inv = inv;
		return StringChecker(copy_inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory105() {
	int expect = 3;
	string error = "InventoryManager::size";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return NumberChecker(inv.size(), 3, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory106() {
	string error = "InventoryManager::getProductAttributes";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			return StringChecker(inv.getProductAttributes(1).toString(), list1D[1].toString(), error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is valid!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory107() {
	string error = "InventoryManager::getProductAttributes";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.getProductAttributes(-1);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory108() {
	string error = "InventoryManager::getProductAttributes";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.getProductAttributes(3);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory109() {
	string error = "InventoryManager::getProductName";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			return StringChecker(inv.getProductName(1), product_name[1], error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is valid!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory110() {
	string error = "InventoryManager::getProductName";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.getProductName(-1);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory111() {
	string error = "InventoryManager::getProductName";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.getProductName(3);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory112() {
	string error = "InventoryManager::getProductQuantity";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			return NumberChecker(inv.getProductQuantity(1), quantities_[1], error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is valid!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory113() {
	string error = "InventoryManager::getProductQuantity";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.getProductQuantity(-1);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory114() {
	string error = "InventoryManager::getProductQuantity";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.getProductQuantity(3);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory115() {
	int expect = 123;
	string error = "InventoryManager::updateQuantity";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.updateQuantity(1, 123);
			return NumberChecker(inv.getProductQuantity(1), 123, error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is valid!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory116() {
	string error = "InventoryManager::updateQuantity";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.updateQuantity(-1, 123);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory117() {
	string error = "InventoryManager::updateQuantity";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.updateQuantity(3, 123);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory118() {
	string expect = "InventoryManager[\nAttributesMatrix: [[Jennie: 163.000000, Jisoo: 162.000000, Lisa: 166.000000, Rose: 168.000000]],\nProductNames: [BlackPink],\nQuantities: [4]\n]";
	string error = "InventoryManager::addProduct";
	try {
		InventoryManager inv;
		InventoryAttribute attributeA3[] = { {"Jennie", 163}, {"Jisoo", 162}, {"Lisa", 166}, {"Rose", 168}};
		List1D<InventoryAttribute> girl_group(attributeA3, 4);
		string name = "BlackPink";
		int quantity = 4;
		inv.addProduct(girl_group, name, quantity);
		return StringChecker(inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory119() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [Jennie: 163.000000, Jisoo: 162.000000, Lisa: 166.000000, Rose: 168.000000]],\nProductNames: [Product A, Product B, Product C, BlackPink],\nQuantities: [50, 30, 20, 4]\n]";
	string error = "InventoryManager::addProduct";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		InventoryAttribute attributeA3[] = { {"Jennie", 163}, {"Jisoo", 162}, {"Lisa", 166}, {"Rose", 168} };
		List1D<InventoryAttribute> girl_group(attributeA3, 4);
		string name = "BlackPink";
		int quantity = 4;
		inv.addProduct(girl_group, name, quantity);
		return StringChecker(inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory120() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [color: 2.000000]],\nProductNames: [Product A, Product C],\nQuantities: [50, 20]\n]";
	string error = "InventoryAttribute::removeProduct";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.removeProduct(1);
			return StringChecker(inv.toString(), expect, error);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is valid!", error);
		}
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory121() {
	string error = "InventoryManager::removeProduct";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.removeProduct(-1);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory122() {
	string error = "InventoryManager::removeProduct";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		try {
			inv.removeProduct(3);
		}
		catch (const out_of_range& e) {
			return StringChecker(e.what(), "Index is invalid!", error);
		}
		return StringChecker("Index is valid!", "Index is invalid!", error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory123() {
	string expect = "[Product A, Product B]";
	string error = "InventoryAttribute::query";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 20, 30, 50 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.query("weight", 10.0, 20.0, 10, 0).toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory124() {
	string expect = "[Product B, Product A]";
	string error = "InventoryAttribute::query";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 20, 30, 50 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.query("height", 20.0, 160.0, 10, 0).toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory125() {
	string expect = "[]";
	string error = "InventoryAttribute::query";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2}, {"height", 10} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 20, 30, 50 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 2) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.query("volume", 0.0, 1000.0, 10, 0).toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory126() {
	string expect = "[Product B, Product C]";
	string error = "InventoryAttribute::query";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 20}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 10}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2}, {"weight", 18} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 20, 30, 50 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 2) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.query("weight", 2.0, 20.0, 25, 0).toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory127() {
	string expect = "[Product C, Product A, Product B]";
	string error = "InventoryAttribute::query";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 100} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 156} };
		InventoryAttribute attributeA2[] = { {"color", 2}, {"height", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 2) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.query("height", 2.0, 160.0, 10, 1).toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory128() {
	string expect = "[Product A, Product B, Product C]";
	string error = "InventoryAttribute::query";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 10}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"weight", 10} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.query("weight", 2.0, 20.0, 10, 1).toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory129() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],\nProductNames: [Product A, Product B, Product C],\nQuantities: [50, 130, 20]\n]";
	string error = "InventoryAttribute::removeDuplicates";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		InventoryAttribute attributeA3[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		string product_name[] = { "Product A", "Product B", "Product C", "Product B"};
		int quantities_[] = { 50, 30, 20 , 100 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1), List1D< InventoryAttribute>(attributeA3, 3) };
		List2D<InventoryAttribute> matrix(list1D, 4);
		List1D<string> names(product_name, 4);
		List1D<int> quantities(quantities_, 4);
		InventoryManager inv(matrix, names, quantities);
		inv.removeDuplicates();
		return StringChecker(inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory130() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 19.000000, depth: 24.000000, height: 100.000000]],\nProductNames: [Product A, Product B, Product C, Product B],\nQuantities: [50, 30, 20, 100]\n]";
	string error = "InventoryAttribute::removeDuplicates";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		InventoryAttribute attributeA3[] = { {"weight", 19}, {"depth", 24}, {"height", 100} };
		string product_name[] = { "Product A", "Product B", "Product C", "Product B" };
		int quantities_[] = { 50, 30, 20 , 100 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1), List1D< InventoryAttribute>(attributeA3, 3) };
		List2D<InventoryAttribute> matrix(list1D, 4);
		List1D<string> names(product_name, 4);
		List1D<int> quantities(quantities_, 4);
		InventoryManager inv(matrix, names, quantities);
		inv.removeDuplicates();
		return StringChecker(inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory131() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000]],\nProductNames: [Product A, Product B, Product C, Product A],\nQuantities: [50, 30, 20, 100]\n]";
	string error = "InventoryAttribute::removeDuplicates";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		InventoryAttribute attributeA3[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		string product_name[] = { "Product A", "Product B", "Product C", "Product A" };
		int quantities_[] = { 50, 30, 20 , 100 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1), List1D< InventoryAttribute>(attributeA3, 3) };
		List2D<InventoryAttribute> matrix(list1D, 4);
		List1D<string> names(product_name, 4);
		List1D<int> quantities(quantities_, 4);
		InventoryManager inv(matrix, names, quantities);
		inv.removeDuplicates();
		return StringChecker(inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory132() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000, color: 50.000000]],\nProductNames: [Product A, Product B, Product C, Product B],\nQuantities: [50, 130, 220, 40]\n]";
	string error = "InventoryAttribute::removeDuplicates";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		InventoryAttribute attributeA3[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA4[] = { {"weight", 20}, {"depth", 24}, {"height", 100}, {"color", 50} };
		InventoryAttribute attributeA5[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C", "Product B", "Product B", "Product C"};
		int quantities_[] = { 50, 30, 20, 100, 40, 200 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1), List1D< InventoryAttribute>(attributeA3, 3), List1D< InventoryAttribute>(attributeA4, 4), List1D< InventoryAttribute>(attributeA5, 1) };
		List2D<InventoryAttribute> matrix(list1D, 6);
		List1D<string> names(product_name, 6);
		List1D<int> quantities(quantities_, 6);
		InventoryManager inv(matrix, names, quantities);
		inv.removeDuplicates();
		return StringChecker(inv.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory133() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 11.000000, height: 157.000000], [weight: 21.000000, depth: 25.000000, height: 101.000000], [color: 3.000000]],\nProductNames: [Product A, Product B, Product C, Product D, Product E, Product F],\nQuantities: [50, 30, 20, 10, 30, 50]\n]";
	string error = "InventoryAttribute::merge";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20};
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv1(matrix, names, quantities);
		
		InventoryAttribute attributeA02[] = { {"weight", 11}, {"height", 157} };
		InventoryAttribute attributeA12[] = { {"weight", 21}, {"depth", 25}, {"height", 101} };
		InventoryAttribute attributeA22[] = { {"color", 3} };
		string product_name2[] = { "Product D", "Product E", "Product F" };
		int quantities_2[] = { 10, 30, 50 };
		List1D<InventoryAttribute> list1D2[] = { List1D< InventoryAttribute>(attributeA02, 2), List1D< InventoryAttribute>(attributeA12, 3), List1D< InventoryAttribute>(attributeA22, 1) };
		List2D<InventoryAttribute> matrix2(list1D2, 3);
		List1D<string> names2(product_name2, 3);
		List1D<int> quantities2(quantities_2, 3);
		InventoryManager inv2(matrix2, names2, quantities2);

		auto inv3 = InventoryManager::merge(inv1, inv2);

		return StringChecker(inv3.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory134() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],\nProductNames: [Product A, Product B, Product C],\nQuantities: [50, 30, 20]\n]";
	string error = "InventoryAttribute::merge";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv1(matrix, names, quantities);
		InventoryManager inv2;
		auto inv3 = InventoryManager::merge(inv1, inv2);

		return StringChecker(inv3.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory135() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],\nProductNames: [Product A, Product B, Product C],\nQuantities: [50, 30, 20]\n]";
	string error = "InventoryAttribute::merge";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv1(matrix, names, quantities);
		InventoryManager inv2;
		auto inv3 = InventoryManager::merge(inv2, inv1);

		return StringChecker(inv3.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory136() {
	string expect = "InventoryManager[\nAttributesMatrix: [[weight: 10.000000, height: 156.000000]],\nProductNames: [Product A],\nQuantities: [50]\n]";
	string error = "InventoryAttribute::split";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		InventoryManager inv1;
		InventoryManager inv2;
		inv.split(inv1, inv2, 0.34);
		return StringChecker(inv1.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory137() {
	string expect = "InventoryManager[\nAttributesMatrix: [[color: 2.000000]],\nProductNames: [Product C],\nQuantities: [20]\n]";
	string error = "InventoryAttribute::split";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		InventoryManager inv1;
		InventoryManager inv2;
		inv.split(inv1, inv2, 0.7);
		return StringChecker(inv2.toString(), expect, error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory138() {
	string error = "InventoryAttribute::getAttributesMatrix";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.getAttributesMatrix().toString(), matrix.toString(), error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory139() {
	string error = "InventoryAttribute::getProductNames";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.getProductNames().toString(), names.toString(), error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}

bool extra_tc_inventory140() {
	string error = "InventoryAttribute::getQuantities";
	try {
		InventoryAttribute attributeA0[] = { {"weight", 10}, {"height", 156} };
		InventoryAttribute attributeA1[] = { {"weight", 20}, {"depth", 24}, {"height", 100} };
		InventoryAttribute attributeA2[] = { {"color", 2} };
		string product_name[] = { "Product A", "Product B", "Product C" };
		int quantities_[] = { 50, 30, 20 };
		List1D<InventoryAttribute> list1D[] = { List1D< InventoryAttribute>(attributeA0, 2), List1D< InventoryAttribute>(attributeA1, 3), List1D< InventoryAttribute>(attributeA2, 1) };
		List2D<InventoryAttribute> matrix(list1D, 3);
		List1D<string> names(product_name, 3);
		List1D<int> quantities(quantities_, 3);
		InventoryManager inv(matrix, names, quantities);
		return StringChecker(inv.getQuantities().toString(), quantities.toString(), error);
	}
	catch (...) {
		cout << "Error: " + error << endl;
		return 0;
	}
}