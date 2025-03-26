#include <iostream>
#include "../include/list/XArrayList.h"
#include "../include/list/DLinkedList.h"
#include "../include/app/inventory.h"
#include "test/extra_tc_xarraylist.h"
#include "test/extra_tc_dlinkedlist.h"
#include "test/extra_tc_inventory.h"

using namespace std;

bool (*testcase[])() = {
	nullptr,
	extra_tc_xarraylist1,
	extra_tc_xarraylist2,
	extra_tc_xarraylist3,
	extra_tc_xarraylist4,
	extra_tc_xarraylist5,
	extra_tc_xarraylist6,
	extra_tc_xarraylist7,
	extra_tc_xarraylist8,
	extra_tc_xarraylist9,
	extra_tc_xarraylist10,
	extra_tc_xarraylist11,
	extra_tc_xarraylist12,
	extra_tc_xarraylist13,
	extra_tc_xarraylist14,
	extra_tc_xarraylist15,
	extra_tc_xarraylist16,
	extra_tc_xarraylist17,
	extra_tc_xarraylist18,
	extra_tc_xarraylist19,
	extra_tc_xarraylist20,
	extra_tc_xarraylist21,
	extra_tc_xarraylist22,
	extra_tc_xarraylist23,
	extra_tc_xarraylist24,
	extra_tc_xarraylist25,
	extra_tc_xarraylist26,
	extra_tc_xarraylist27,
	extra_tc_xarraylist28,
	extra_tc_xarraylist29,
	extra_tc_xarraylist30,
	extra_tc_xarraylist31,
	extra_tc_xarraylist32,
	extra_tc_xarraylist33,
	extra_tc_xarraylist34,
	extra_tc_xarraylist35,
	extra_tc_xarraylist36,
	extra_tc_xarraylist37,
	extra_tc_xarraylist38,
	extra_tc_xarraylist39,
	extra_tc_xarraylist40,
	extra_tc_dlinkedlist41,
	extra_tc_dlinkedlist42,
	extra_tc_dlinkedlist43,
	extra_tc_dlinkedlist44,
	extra_tc_dlinkedlist45,
	extra_tc_dlinkedlist46,
	extra_tc_dlinkedlist47,
	extra_tc_dlinkedlist48,
	extra_tc_dlinkedlist49,
	extra_tc_dlinkedlist50,
	extra_tc_dlinkedlist51,
	extra_tc_dlinkedlist52,
	extra_tc_dlinkedlist53,
	extra_tc_dlinkedlist54,
	extra_tc_dlinkedlist55,
	extra_tc_dlinkedlist56,
	extra_tc_dlinkedlist57,
	extra_tc_dlinkedlist58,
	extra_tc_dlinkedlist59, // error
	extra_tc_dlinkedlist60,
	extra_tc_dlinkedlist61,
	extra_tc_dlinkedlist62,
	extra_tc_dlinkedlist63,
	extra_tc_dlinkedlist64,
	extra_tc_dlinkedlist65, 
	extra_tc_dlinkedlist66,
	extra_tc_dlinkedlist67,
	extra_tc_dlinkedlist68,
	extra_tc_dlinkedlist69,
	extra_tc_dlinkedlist70,
	extra_tc_dlinkedlist71,
	extra_tc_dlinkedlist72,
	extra_tc_dlinkedlist73,
	extra_tc_dlinkedlist74,
	extra_tc_dlinkedlist75,
	extra_tc_dlinkedlist76,
	extra_tc_dlinkedlist77,
	extra_tc_dlinkedlist78,
	extra_tc_dlinkedlist79,
	extra_tc_dlinkedlist80,
	extra_tc_inventory81,
	extra_tc_inventory82,
	extra_tc_inventory83,
	extra_tc_inventory84,
	extra_tc_inventory85,
	extra_tc_inventory86,
	extra_tc_inventory87,
	extra_tc_inventory88,
	extra_tc_inventory89,
	extra_tc_inventory90,
	extra_tc_inventory91,
	extra_tc_inventory92,
	extra_tc_inventory93,
	extra_tc_inventory94,
	extra_tc_inventory95,
	extra_tc_inventory96,
	extra_tc_inventory97,
	extra_tc_inventory98,
	extra_tc_inventory99,
	extra_tc_inventory100,
	extra_tc_inventory101,
	extra_tc_inventory102,
	extra_tc_inventory103,
	extra_tc_inventory104,
	extra_tc_inventory105,
	extra_tc_inventory106,
	extra_tc_inventory107,
	extra_tc_inventory108,
	extra_tc_inventory109,
	extra_tc_inventory110,
	extra_tc_inventory111,
	extra_tc_inventory112,
	extra_tc_inventory113,
	extra_tc_inventory114,
	extra_tc_inventory115,
	extra_tc_inventory116,
	extra_tc_inventory117,
	extra_tc_inventory118,
	extra_tc_inventory119,
	extra_tc_inventory120,
	extra_tc_inventory121,
	extra_tc_inventory122,
	extra_tc_inventory123,
	extra_tc_inventory124,
	extra_tc_inventory125,
	extra_tc_inventory126,
	extra_tc_inventory127,
	extra_tc_inventory128,
	extra_tc_inventory129,
	extra_tc_inventory130,
	extra_tc_inventory131,
	extra_tc_inventory132,
	extra_tc_inventory133,
	extra_tc_inventory134,
	extra_tc_inventory135,
	extra_tc_inventory136,
	extra_tc_inventory137,
	extra_tc_inventory138,
	extra_tc_inventory139,
	extra_tc_inventory140,
};

void runAll() {
	double grade = 0;
	for (int i = 1, n = sizeof(testcase) / sizeof(testcase[0]); i != n; ++i) {
		cout << "Testcase " << i << ": ";
		grade += testcase[i]();
	}
	cout << setprecision(2) << fixed << "Grade: " << grade / 140 * 10;
}

bool run(int i) {
	cout << "Testcase " << i << ": ";
	return testcase[i]();
}

int main(int argc, char** argv) {
	if (argc == 1) {
		runAll();
		return 0;
	} else {
		return run(stoi(argv[1]));
	}
}