float SL_getStddev(int eingabe, float avg){
	static int quadr_sum, n;
	quadr_sum += (eingabe - avg)*(eingabe - avg);
	return quadr_sum;
}

