/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
    int lower = 0;
	int upper = n;

    int mid = (lower + upper) / 2;
    int gret = 0;

    while (upper - lower > 1)
    {
        gret = guess(mid);
        if (gret == 0) return mid;

        if (gret < 0) upper = mid;
        if (gret > 0) lower = mid;

        mid = ((upper - lower) / 2) + lower;
    }

    return upper;
}
