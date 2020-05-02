#include <cassert>

/* Add your Dominance function here */
bool Dominance(bool greed = true, bool power = true) {
	if (greed && power) {
		return true;
	}
	else {
		return false;
	}
}


int main() {

	assert(Dominance(true, true));
	assert(!Dominance(true, false));
	assert(!Dominance(false, true));
	assert(!Dominance(false, false));

	// Once all of the above pass, add default values for your parameters and uncomment this last test
	assert(Dominance());

	return 0;
}