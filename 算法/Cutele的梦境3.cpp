#include <bits/stdc++.h>
using namespace std;

int main()
{
	double g,h;
	int p;
	cin>>g;
	if(g<=400.00)
		h=g*1.15,p=15;
	else if(g<=800.00)
		h=g*1.12,p=12;
	else if(g<=1200.00)
		h=g*1.10,p=10;
	else if(g<=2000.00)
		h=g*1.07,p=7;
	else
		h=g*1.04,p=4;
	cout<<"Novo salario: "<<fixed<<setprecision(2)<<h<<endl;
	cout<<"Reajuste ganho: "<<fixed<<setprecision(2)<<h-g<<endl;
	cout<<"Em percentual: "<<p<<" %"<<endl;
	return 0;
}

