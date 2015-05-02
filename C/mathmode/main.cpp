#include <iostream>

using namespace std;

/* Remove $/$$ from a LaTeX file and replace with \(, \), \[ and \]
 *
 * May break on $$$$ and similar stuff.
 *
 */
int main(void) {
	// Are we in $/$$ mathmode?
	bool math = false;
	// Last character
	int last = 0;
	while (!cin.eof()) {
		int c = cin.get();
		// TODO Figure out why I'm reading -1 sometimes
		if (c <= 0) continue;
		if (last == '\\') {
			// The char c is escaped, gets printed verbatim ...
			cout.put(c);
			// ... and may not influence following stuff.
			c = 0;
		} else if (last == '$') {
			cout.put('\\');
			if (c == '$') {
				cout.put(math?']':'[');
				c = 0; // That $ is used up.
			} else {
				cout.put(math?')':'(');
				cout.put(c);
			}
			math = !math;
		} else if (c != '$') {
			cout.put(c);
		}
		last = c;
	}
	return 0;
}
