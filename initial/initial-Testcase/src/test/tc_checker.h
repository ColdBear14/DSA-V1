/*
 * File:   tc_checker.h
 * Author: NTM
 *
 */

#ifndef TC_CHECKER_H
#define TC_CHECKER_H

#include <iostream>
#include <string>
#include "../../include/list/XArrayList.h"
#include "../../include/list/DLinkedList.h"
#include "../../include/util/Object.h"
#include "../../include/app/inventory.h"

using namespace std;

template<typename T>
string list2string(XArrayList<T>* output, string(*itemtostring)(T&)) {
	string ans = "";
	for (auto& c : *output) {
		ans += itemtostring(c);
		ans += " ";
	}
	if (ans != "")
		ans.pop_back();
	return ans;
}

template<typename T>
string list2string(DLinkedList<T>* output, string(*itemtostring)(T&)) {
	string ans = "";
	for (auto& c : *output) {
		ans += itemtostring(c);
		ans += " ";
	}
	if (ans != "")
		ans.pop_back();
	return ans;
}

template<typename T>
string list2string(T* expect, int n, string(*itemtostring)(T&)) {
	string ans = "";
	for (T* p = expect, *nE = expect + n; p != nE; ++p) {
		ans += itemtostring(*p);
		ans += " ";
	}
	if (ans != "")
		ans.pop_back();
	return ans;
}

template<typename T>
bool ListChecker(DLinkedList<T>* output, T* expect, int n, string(*item2string)(T&), bool (*itemEqual)(T&, T&), const string& error = "") {
	T* p = expect, * nE = expect + n;
	for (auto& c : *output) {
		if (p == nE || !itemEqual(*p, c)) {
			cout << "Fail: " << error << endl;
			cout << "Output: " << list2string<T>(output, item2string) << endl;
			cout << "Expect: " << list2string<T>(expect, n, item2string) << endl;
			return 0;
		}
		++p;
	}
	if (p == nE) {
		cout << "Pass" << endl;
		return 1;
	}
	else {
		cout << "Fail: " << error << endl;
		cout << "Output: " << list2string<T>(output, item2string) << endl;
		cout << "Expect: " << list2string<T>(expect, n, item2string) << endl;
		return 0;
	}
}

template<typename T>
bool ListChecker(XArrayList<T>* output, T* expect, int n, string(*item2string)(T&), bool (*itemEqual)(T&, T&), const string& error = "") {
	T* p = expect, * nE = expect + n;
	for (auto& c : *output) {
		if (p == nE || !itemEqual(*p, c)) {
			cout << "Fail: " << error << endl;
			cout << "Output: " << list2string<T>(output, item2string) << endl;
			cout << "Expect: " << list2string<T>(expect, n, item2string) << endl;
			return 0;
		}
		++p;
	}
	if (p == nE) {
		cout << "Pass" << endl;
		return 1;
	}
	else {
		cout << "Fail: " << error << endl;
		cout << "Output: " << list2string<T>(output, item2string) << endl;
		cout << "Expect: " << list2string<T>(expect, n, item2string) << endl;
		return 0;
	}
}

string removeSpaces(const string& str) {
	string ans;
	for (const char& c : str)
		if (c != ' ')
			ans += c;
	return ans;
}

bool StringChecker2(const string& output, const string& expect, const string& error = "") {
	if (removeSpaces(output) == removeSpaces(expect)) {
		cout << "Pass" << endl;
		return 1;
	}
	else {
		cout << "Fail: " << error << endl;
		cout << "Output: " << output << endl;
		cout << "Expect: " << expect << endl;
		return 0;
	}
}

bool StringChecker(const string& output, const string& expect, const string& error = "") {
	if (output == expect) {
		cout << "Pass" << endl;
		return 1;
	}
	else {
		cout << "Fail: " << error << endl;
		cout << "Output: " << output << endl;
		cout << "Expect: " << expect << endl;
		return 0;
	}
}

bool NumberChecker(const int& output, const int& expect, const string& error = "") {
	if (output == expect) {
		cout << "Pass" << endl;
		return 1;
	}
	else {
		cout << "Fail: " << error << endl;
		cout << "Output: " << output << endl;
		cout << "Expect: " << expect << endl;
		return 0;
	}
}

bool Memleak(const int& num_of_object, const string& error = "Memory leak (Object)") {
	if (num_of_object == Object::num_of_object) {
		cout << "Pass" << endl;
		return 1;
	}
	else {
		cout << "Fail: " << error << endl;
		cout << "Leak: " << Object::num_of_object - num_of_object << endl;
		return 0;
	}
}

#endif /* TC_CHECKER_H */