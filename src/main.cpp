//*********************************************************************************************************//

//                Code to calculate the coefficients for 1--2 and 1--3 Directional Angular Correlation     //
//      		            Author: Nirupama Sensharma				                   //
//			            Date: November 18, 2018					           //
              
//*********************************************************************************************************//


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

#include "declare.h"
using namespace std;
	
	
int main() 
	{
	int option;
	start:
	cout<<"Select type of angular correlation to be viewed:"<<endl;
	cout<<"1. 1--2 directional angular correlation"<<endl;
	cout<<"2. 1--3 directional angular correlation"<<endl;
	cout<<"Enter 1 or 2"<<endl;
	cin>>option;
	
	if (option == 1)
	angcorr_main();
	else if (option == 2)
	angcorr_ggg();
	else {cout<<"TRY AGAIN!"<<endl;
		goto start;}

	return 0;
}

	
