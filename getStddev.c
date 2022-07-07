double SL_getStddev(double eingabe, double avg){
	static double quadr_sum, n;
	quadr_sum += (eingabe - avg)*(eingabe - avg);
	return quadr_sum;
}

