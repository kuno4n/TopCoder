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

#define INF ((1<<31)-1)

bool isPow2(long long l){
    if (l <= 0) return false;
    else if (l & (l-1)) return false;
    else return true;
}

class AfraidOfEven {
	public:
	vector <int> restoreProgression(vector <int> seq) {
        for(LL first = seq[0]; first <= INF; first<<=1){
            for(LL second = seq[1]; second <= INF; second<<=1){
                LL diff = second - first;
                VI res;
                res.push_back(first);
                res.push_back(second);
                FOR(i, 2, SZ(seq)){
                    LL tmp = res[i-1] + diff;
                    if(tmp <= 0 || tmp > INF || tmp < seq[i] || tmp%seq[i] != 0 || !isPow2(tmp/seq[i])) break;
                    res.push_back(tmp);
                }
                if(SZ(res) == SZ(seq)) return res;
            }
        }
        return seq;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
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
	}
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int seq[]                 = {1, 1, 3, 1, 5};
			int expected__[]          = {1, 2, 3, 4, 5 };

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {9, 7, 5, 3, 1};
			int expected__[]          = {9, 7, 5, 3, 1 };

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {999, 999, 999, 999};
			int expected__[]          = {999, 999, 999, 999 };

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {7, 47, 5, 113, 73, 179, 53};
			int expected__[]          = {14, 47, 80, 113, 146, 179, 212 };

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int seq[]                 = {749, 999, 125, 1};
			int expected__[]          = {1498, 999, 500, 1 };

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int seq[]                 = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int seq[]                 = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int seq[]                 = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = AfraidOfEven().restoreProgression(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// A sequence of integers a[0], a[1], ..., a[N-1], where N >= 3, is called an arithmetic progression if the difference between any two successive terms in the sequence is a constant. More precisely, it is an arithmetic progression if a[i] - a[i-1] = a[i+1] - a[i] for every integer i such that 0 < i < N-1.  


Sasha and Pasha are students sharing the same room. Once, when Pasha had left the room, Sasha was in a good mood. So he took a piece of chalk and wrote an arithmetic progression on the blackboard. The progression consisted of at least 4 elements, all of which were positive integers. Then Sasha went to class, and Pasha came back.


Pasha is a very nice person, but there's one problem with him -- he's frightened of even numbers! So, when he returned, he decided to make all the numbers on the board odd. He did this by repeatedly finding an arbitrary even number X, erasing it, and writing X/2 in its place. He continued to perform this step until no even numbers remained.


Your task is to help Sasha restore the initial progression. You will be given a vector <int> seq, where the i-th element is the i-th number in the sequence written on the blackboard after Pasha's actions. Return an vector <int> whose i-th element is the i-th number in a sequence that Sasha could have originally written on the blackboard. The constraints will ensure that at least one such sequence exists. If there are several such sequences, choose the one among them whose vector <int> representation is lexicographically smallest.

DEFINITION
Class:AfraidOfEven
Method:restoreProgression
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> restoreProgression(vector <int> seq)


NOTES
-The lexicographically smaller of two different vector <int>s containing the same number of elements is the one with a smaller number at the first position where they differ.
-It is guaranteed that all elements of the resulting vector <int> will fit into a 32-bit signed integer data type.


CONSTRAINTS
-seq will contain between 4 and 50 elements, inclusive.
-Each element of seq will be between 1 and 1000, inclusive.
-Each element of seq will be odd.
-There will exist at least one arithmetic progression from which Pasha would produce exactly the sequence described by seq.


EXAMPLES

0)
{1, 1, 3, 1, 5}

Returns: {1, 2, 3, 4, 5 }

If the progression written by Pasha was {1, 2, 3, 4, 5}, then Sasha would divide 2 by 2 once and 4 by 2 twice to produce exactly {1, 1, 3, 1, 5}. Note that Pasha could have written other progressions, e.g., {2, 4, 6, 8, 10}, but {1, 2, 3, 4, 5} has the lexicographically smallest vector <int> representation.

1)
{9, 7, 5, 3, 1}

Returns: {9, 7, 5, 3, 1 }

It is possible that all terms in the original progression were odd. In this case Pasha wouldn't perform any replacements.


Note that an arithmetic progression doesn't have to be an increasing sequence.

2)
{999, 999, 999, 999}

Returns: {999, 999, 999, 999 }

A sequence where all terms are the same is also an arithmetic progression.

3)
{7, 47, 5, 113, 73, 179, 53}

Returns: {14, 47, 80, 113, 146, 179, 212 }



4)
{749, 999, 125, 1}

Returns: {1498, 999, 500, 1 }

Some elements of the original progression could be greater than 1000.


*/

// END CUT HERE
