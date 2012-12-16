#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class KingSort {
    string conv(int a){
        string res = "";
        switch (a/10) {
            case 1: {res += "X";break;}
            case 2: {res += "XX";break;} 
            case 3: {res += "XXX";break;}
            case 4: {res += "XL";break;}
            case 5: {res += "L";break;}
        }
        switch (a%10) {
            case 1: {res += "I";break;}
            case 2: {res += "II";break;}
            case 3: {res += "III";break;}
            case 4: {res += "IV";break;}
            case 5: {res += "V";break;}
            case 6: {res += "VI";break;}
            case 7: {res += "VII";break;}
            case 8: {res += "VIII";break;}
            case 9: {res += "IX";break;}
        }
        return res;
    }
    
	public:
	vector <string> getSortedList(vector <string> kings) {
        vector < pair <string, int> > tmp;
        
        REP(i, SZ(kings)){
            stringstream ss(kings[i]);
            string s1 = "";
            string s2 = "";
            ss >> s1 >> s2;
            int a = 0;
            REP(j, 51) if(conv(j) == s2) a = j;
            tmp.push_back(make_pair(s1, a));
        }
        sort(ALL(tmp));
        
        vector <string> res;
        REP(i, SZ(tmp)){
            res.push_back(tmp[i].first + " " + conv(tmp[i].second));
        }
        
        return res;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
        cerr << endl << endl;
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
        cerr << endl << endl;
	}
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... ";
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
        cerr << "    Expected: " << expected << endl;
		if (verdict == "FAILED") { 
			cerr << "    Received: " << received << endl; 
		}
		cerr << endl;
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string kings[]            = {"Louis IX", "Louis VIII"};
			string expected__[]       = {"Louis VIII", "Louis IX" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string kings[]            = {"Louis IX", "Philippe II"};
			string expected__[]       = {"Louis IX", "Philippe II" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string kings[]            = {"Richard III", "Richard I", "Richard II"};
			string expected__[]       = {"Richard I", "Richard II", "Richard III" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string kings[]            = {"John X", "John I", "John L", "John V"};
			string expected__[]       = {"John I", "John V", "John X", "John L" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string kings[]            = {"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"};
			string expected__[]       = {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			string kings[]            = {"Philippe II", "Philip II"};
			string expected__[]       = {"Philip II", "Philippe II" };

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			string kings[]            = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = KingSort().getSortedList(vector <string>(kings, kings + (sizeof kings / sizeof kings[0])));
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}

/*
// PROBLEM STATEMENT
// 
Every good encyclopedia has an index. The entries in the index are usually sorted in alphabetic order. However, there are some notable exceptions. In this task we will consider one such exception: the names of kings.



In many countries it was common that kings of the same name received ordinal numbers. This ordinal number was written as a Roman numeral and appended to the actual name of the king.
For example, "Louis XIII" (read: Louis the thirteenth) was the thirteenth king of France having the actual name Louis.



In the index of an encyclopedia, kings who share the same name have to be sorted according to their ordinal numbers. For example, Louis the 9th should be listed after Louis the 8th.



You are given a vector <string> kings. Each element of kings is the name of one king. The name of each king consists of his actual name, a single space, and a Roman numeral. Return a vector <string> containing the names
rearranged into their proper order: that is, the kings have to be in ascending lexicographic order according to their actual name, and kings with the same name have to be in the correct numerical order.


DEFINITION
Class:KingSort
Method:getSortedList
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> getSortedList(vector <string> kings)


NOTES
-The Roman numerals for 1 through 10 are I, II, III, IV, V, VI, VII, VIII, IX, and X.
-The Roman numerals for 20, 30, 40, and 50 are XX, XXX, XL, and L.
-The Roman numeral for any other two-digit number less than 50 can be constructed by concatenating the numeral for its tens and the numeral for its ones. For example, 47 is 40 + 7 = "XL" + "VII" = "XLVII".
-Standard string comparison routines give the correct ordering for the actual names of kings.
-Formally, given two different strings A and B we say that A is lexicographically smaller than B if either (A is a prefix of B) or (there is at least one index where A and B differ, and for the smallest such index the character in A has a lower ASCII value than the character in B).


CONSTRAINTS
-Each actual name of a king will be a string containing between 1 and 20 characters, inclusive.
-Each actual name will start by an uppercase letter ('A'-'Z').
-Each other character in each actual name will be a lowercase letter ('a'-'z').
-kings will contain between 1 and 50 elements, inclusive.
-Each element of kings will have the form "ACTUALNAME ORDINAL", where ACTUALNAME is an actual name as defined above, and ORDINAL is a valid Roman numeral representing a number between 1 and 50, inclusive.
-The elements of kings will be pairwise distinct.


EXAMPLES

0)
{"Louis IX", "Louis VIII"}

Returns: {"Louis VIII", "Louis IX" }

Louis the 9th should be listed after Louis the 8th.

1)
{"Louis IX", "Philippe II"}

Returns: {"Louis IX", "Philippe II" }

Actual names take precedence over ordinal numbers.

2)
{"Richard III", "Richard I", "Richard II"}

Returns: {"Richard I", "Richard II", "Richard III" }



3)
{"John X", "John I", "John L", "John V"}

Returns: {"John I", "John V", "John X", "John L" }



4)
{"Philippe VI", "Jean II", "Charles V", "Charles VI", "Charles VII", "Louis XI"}

Returns: {"Charles V", "Charles VI", "Charles VII", "Jean II", "Louis XI", "Philippe VI" }

These are the French monarchs who ruled between 1328 and 1483.

5)
{"Philippe II", "Philip II"}

Returns: {"Philip II", "Philippe II" }

"Philippe" and "Philip" are distinct names, and "Philip" is lexicographically smaller than "Philippe".

*/

// END CUT HERE
