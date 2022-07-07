float SL_getAvg(int eingabe){
	static int sum, n;
	sum += eingabe;
	return(((float)sum)/ ++n);
}

