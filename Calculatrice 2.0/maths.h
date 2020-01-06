#ifndef MATHS_H_INCLUDED
#define MATHS_H_INCLUDED

double Pow(double a, double b){
	int exp = b;
	if(exp>0){
		return Pow(a, exp-1)*a;
	}else if(exp<0){
		return Pow(a, exp+1)/a;
	}else{
		return 1;
	}
}

double Sqrt(double a, double b){
	int exp = b;
	double u;

	double min = 0;
	double max = a+1;

	if(a>0){
		while(max-min>0.000001){
			double dicho = (min+max)/2;
			if(a>Pow(dicho,2)){
				min = dicho;
			}else if(a<Pow(dicho,2)){
				max = dicho;
			}else{
				u = dicho;
			}
		}
	}else{
		printf("\n\nIl doit y avoir une erreur.\n");
		return 0;
	}

	u = (min+max)/2;

	if(exp==2){
		for (int i=0; i<25; i++){
			u=(u+(a/u))/2;
		}
	}else{
		for (int i=0; i<25; i++){
			u=(1/exp)*((exp-1)*u+(a/(Pow(u, exp-1))));
		}
	}

	return u;

}

int Factorielle(double a){
	if (a<=0){
		return 1;
	}else{
		return a*Factorielle(a-1);
	}
}

double Pi_bs(int t){
	double u = 1;
	double v = 1/Sqrt(2,2);
	double w = 1/4;
	double p = 1;
	double pi;

	for (int i=0; i<t; i++){
		u=(u+v)/2;
		v=Sqrt((u+v),2);
		w=w-p*(Pow((u-((u+v)/2)),2));
		p=2*p;
	}

	pi=(Pow((u+v),2))/(4*w);

	return pi;
}

#endif
