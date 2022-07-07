double SL_getAvg(double eingabe){
	static double sum, n;
	sum += eingabe;
	return sum/++n;
}

