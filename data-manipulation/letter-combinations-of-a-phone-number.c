// by Li-Aaron


typedef struct _N2C {
	char number;
	int len;
	char * characters[4];
} N2C;

N2C n2c[] = {
	{ '0',0,{ "" } },
	{ '1',0,{ "" } },
	{ '2',3,{ "a","b","c" } },
	{ '3',3,{ "d","e","f" } },
	{ '4',3,{ "g","h","i" } },
	{ '5',3,{ "j","k","l" } },
	{ '6',3,{ "m","n","o" } },
	{ '7',4,{ "p","q","r","s" } },
	{ '8',3,{ "t","u","v" } },
	{ '9',4,{ "w","x","y","z" } },
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
char ** letterCombinations(char * digits, int* returnSize) {
	char ** ret = NULL;
	int n2c_idx;
	int size = 1;    // how many strings in return.
	int digitcount = strlen(digits);
	int lastlen;     // how long a same charaster last in each loop
	int totallen;    // how many same charasters in each loop
	int skiplen;     // how many space to skip in each loop

  // error handling
  if (digitcount == 0) {
    *returnSize = 0;
    return NULL;
  }

	// calculate size and allocate.
	for (int i = 0; i < digitcount; i++) {
		n2c_idx = (int)(digits[i] - '0');
		size *= n2c[n2c_idx].len;
	}
	ret = (char**)malloc(size * sizeof(char*));
	for (int i = 0; i < size; i++) {
		ret[i] = (char*)calloc((digitcount + 1), sizeof(char));
	}

	lastlen = size;
	skiplen = 1;
	// for each digit
	for (int i = 0; i < digitcount; i++) {
		n2c_idx = (int)(digits[i] - '0');
		// this lastlen = prev lastlen / this character num
		lastlen /= n2c[n2c_idx].len;
		totallen = size / n2c[n2c_idx].len;

		// for each character in digit
		for (int idx_char = 0; idx_char < n2c[n2c_idx].len; idx_char++) {
			int cnt = 0;
			int idx_skip = 0;
			// length of each character
			while (cnt < totallen) {
				// for each character last
				for (int idx_loc = 0; idx_loc < lastlen; idx_loc++) {
					strcat(ret[idx_char * lastlen + idx_skip + idx_loc], n2c[n2c_idx].characters[idx_char]);
					cnt++;
				}
				idx_skip += skiplen;
			}
		}
		// next skiplen = this lastlen
		skiplen = lastlen;
	}
	*returnSize = size;
	return ret;
}