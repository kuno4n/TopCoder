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

double micro = 1e-10;

class AutoLoan {
	public:
	double interestRate(double price, double monthlyPayment, int loanTerm) {
		double mid = 0.0;
        double high = 100.0;
        double low = 0.0;
        
        do{
            double balance = price;
            mid = (high+low) / 2;
            double mi = (100 + (mid/12)) / 100;
            REP(i, loanTerm){
                balance *= mi;
                balance -= monthlyPayment;
            }
            if(balance < 0) low = mid;
            else high = mid;
        }while(micro < high-low && micro < (high-low)/high);
        
        return mid;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			double price              = 6800;
			double monthlyPayment     = 100;
			int loanTerm              = 68;
			double expected__         = 1.3322616182218813E-13;

			clock_t start__           = clock();
			double received__         = AutoLoan().interestRate(price, monthlyPayment, loanTerm);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			double price              = 2000;
			double monthlyPayment     = 510;
			int loanTerm              = 4;
			double expected__         = 9.56205462458368;

			clock_t start__           = clock();
			double received__         = AutoLoan().interestRate(price, monthlyPayment, loanTerm);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			double price              = 15000;
			double monthlyPayment     = 364;
			int loanTerm              = 48;
			double expected__         = 7.687856394581649;

			clock_t start__           = clock();
			double received__         = AutoLoan().interestRate(price, monthlyPayment, loanTerm);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			double price              = ;
			double monthlyPayment     = ;
			int loanTerm              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AutoLoan().interestRate(price, monthlyPayment, loanTerm);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			double price              = ;
			double monthlyPayment     = ;
			int loanTerm              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AutoLoan().interestRate(price, monthlyPayment, loanTerm);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			double price              = ;
			double monthlyPayment     = ;
			int loanTerm              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = AutoLoan().interestRate(price, monthlyPayment, loanTerm);
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
// Auto dealerships frequently advertise tempting loan offers in order to make it easier for people to afford the "car of their dreams".  A typical sales tactic is to show you various cars, and then talk in terms of what your monthly payment would be, to say nothing of how much you are actually paying for the car, how much interest you pay, or how long you have to make payments.

A typical auto loan is calculated using a fixed interest rate, and is set up so that you make the same monthly payment for a set period of time in order to fully pay off the balance.  The balance of your loan starts out as the sticker price of the car.  Each month, the monthly interest is added to your balance, and the amount of your payment is subtracted from your balance.  (The payment is subtracted after the interest is added.)  The monthly interest rate is 1/12 of the yearly interest rate.  Thus, if your annual percentage rate is 12%, then 1% of the remaining balance would be charged as interest each month.

You have been checking out some of the cars at your local dealership, TopAuto.  An excited salesman has just approached you, shouting about how you can have the car you are looking at for a payment of only monthlyPayment for only loanTerm months!   You are to return a double indicating the annual percentage rate of the loan, assuming that the initial balance of the loan is price.


DEFINITION
Class:AutoLoan
Method:interestRate
Parameters:double, double, int
Returns:double
Method signature:double interestRate(double price, double monthlyPayment, int loanTerm)


NOTES
-Because of the way interest is compounded monthly, the actual interest accrued over the course of a year is not necessarily the same as (balance * yearly interest rate).  In fact, it's usually more.
-In a real situation, information like this would typically need to be disclosed, but since you aren't at a point of signing any paperwork, the salesman has no legal obligation to tell you anything.
-The return value must be within 1e-9 absolute or relative error of the actual result.


CONSTRAINTS
-price will be between 1 and 1000000, inclusive.
-monthlyPayment will be between 0 and price / 2, inclusive.
-loanTerm will be between 1 and 600, inclusive.
-The resulting interest rate will be between 0 and 100, inclusive.


EXAMPLES

0)
6800
100
68

Returns: 1.3322616182218813E-13

Noting that 68 payments of 100 equals the total price of 6800, so there is no interest.

1)
2000
510
4

Returns: 9.56205462458368

Here, we do pay a little interest.  At 9.562% annual interest, that means each month we pay 0.7968% of the balance in interest.  Our payment schedule looks like this:


Month | + Interest | - Payment | = Balance
------------------------------------------
      |            |           |  2000.00
   1  |     15.94  |   510.00  |  1505.94
   2  |     12.00  |   510.00  |  1007.94
   3  |      8.03  |   510.00  |   505.97
   4  |      4.03  |   510.00  |     0.00



2)
15000
364
48

Returns: 7.687856394581649

This is similar to what purchasing a new car with no money down might look like, if you make payments for 4 years.

*/

// END CUT HERE
