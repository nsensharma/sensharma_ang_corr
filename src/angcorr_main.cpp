//*********************************************************************************************************//

//                Code to calculate the coefficients for Gamma-Gamma (1--2) Angular Correlation            //
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
	
//declaration of the spins, multipolarities, mixing ratios and angular correlation coefficients for mixed and pure transitions//
	float I1, I2, I3, L1, L2, L3, L4;
	float d1, d2;
	float a0, a2, a4;
	float a0_pure, a2_pure, a4_pure;
	
int angcorr_main() 
	{
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"	    Gamma-Gamma Angular Correlation Coefficients                          "<<endl;	
	cout<<endl;
	cout<<"		__________________________________"<<" I1"<<endl;
	cout<<"             		  	 |                  "<<endl;
	cout<<"             		  	 |                  "<<endl;
	cout<<"               		  	 |  L1,L2           "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 v                  "<<endl;
	cout<<"		__________________________________"<<" I2"<<endl;
	cout<<"              		  	 |                  "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 |  L3,L4           "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 v                  "<<endl;
	cout<<"		__________________________________"<<" I3"<<endl;
	cout<<"                                               "<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;


	//Prompting user to enter initial, intermediate and final spin of the states involved//
	cout<<"Enter the spin of the initial state, I1"<<endl;
	cin>>I1;
	cout<<"Enter the spin of the intermediate state, I2"<<endl;
	cin>>I2;
	cout<<"Enter the spin of the final state, I3"<<endl;
	cin>>I3;

	//Checking if user entered either integer or half-integer values for the spins. Exiting with error otherwise//
	if (((int)((I1*10))%5 !=0) || ((int)((I2*10))%5 !=0) || ((int)((I3*10))%5 !=0)){
		cout<<"The spin values entered are not integers or half-integers.Try again!"<<endl;
		exit(1);}


	//Prompting user to enter the multipolaritiies and the mixing ratios of the two transitions involved//
	cout<<"Enter mixing ratio for first transition"<<endl;
	cin>>d1;
		
	cout<<"Enter the multipolarity of the first transition, L1"<<endl;
	cin>>L1;
	if (d1==0) //checking if it is a pure or a mixed transition//
	L2 = L1;
	else {cout<<"Enter the next possible multipole (in case of mixing) for the first transition, L2"<<endl;
	cin>>L2;}
	
	cout<<"Enter mixing ratio for second transition"<<endl;
	cin>>d2;
	cout<<"Enter the multipolarity of the second transition, L3"<<endl;
	cin>>L3;
	if (d2==0)
	L4 = L3;
	else {cout<<"Enter the next possible multipole (in case of mixing) for the second transition, L4"<<endl;
	cin>>L4;}
	

	//calling the Ak coefficients function to calculate a0, a2 and a4//
	a0 = (Ak(I1, L1, L2, I2,d1,0))*(Ak(I3, L3, L4, I2,d2,0));
	a2 = (Ak(I1, L1, L2, I2,d1,2))*(Ak(I3, L3, L4, I2,d2,2));
	a4 = (Ak(I1, L1, L2, I2,d1,4))*(Ak(I3, L3, L4, I2,d2,4));

	cout<<"The angular correlation coefficients are: "<<endl<<"a0 = "<<a0<<endl<<"a2 = "<<a2<<endl<<"a4 = "<<a4<<endl;	


	//Opening a file 'coefficients.dat' to write in the calculated a2 and a4 values from above. To be used for plotting in the a2 vs. a4 graph//  
	ofstream coeff_file ("coefficients.dat");
	if (!coeff_file) {
		cout<<"coefficients.dat could not be opened for writing!"<<endl;
		exit(1);
		}
	else coeff_file<<a2<<"  "<<a4<<endl;
	coeff_file.close();	
	
	

	//Opening a file 'angcorr.dat' to write in the angles and the corresponding values as calculated from W2 fuction//
	ofstream outfile ("angcorr.dat");
	if (!outfile) {
		cout<<"angcorr.dat could not be opened for writing!"<<endl;
		exit(1);
		}


	outfile<<"*******************************************************************************"<<endl;
	outfile<<"*******************************************************************************"<<endl;
	outfile<<"	    Gamma-Gamma Angular Correlation Coefficients                          "<<endl;	
	outfile<<endl;
	outfile<<"		__________________________________"<< I1<<endl;
	outfile<<"             		  	 |                  "<<endl;
	outfile<<"             		  	 |                  "<<endl;
	outfile<<"               		  	 |  "<<L1<<","<<L2<<"(d="<<d1<<")           "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 v                  "<<endl;
	outfile<<"		__________________________________"<< I2<<endl;
	outfile<<"              		  	 |                  "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 |  "<<L3<<","<<L4<<"(d="<<d2<<")           "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 v                  "<<endl;
	outfile<<"		__________________________________"<< I3<<endl;
	outfile<<"                                               "<<endl;
	outfile<<"*******************************************************************************"<<endl;
	outfile<<"*******************************************************************************"<<endl;

	
	//Calling the W2 function for angles from 0-180 degrees//
	for (float theta=0; theta<=180; theta=theta+5.0) {
		float theta_rad = (theta*3.14159)/180;
		outfile<<theta<<"   "<<angcor(theta_rad,a2,a4)<<endl;
	}

	cout<<"File \"angcorr.dat\" with the angular correlation values successfully created!"<<endl;
	outfile.close();

	cout<<endl;


	a2a4(I1,I2,I3,L1,L2,L3,L4,d2);	//Calling the a2a4 function to plot a2 vs. a4 keeping constant d2//



	//Prompting user to enter choice for calculating the angular correlation coefficients for the inputted spin values but for pure stretched transitions//
	
	if (d1 == 0 && d2 == 0)
	exit(1);

	char choice;
	start_choice:
	cout<<"Do you want angular correlation results for pure transitions (y or n)?"<<endl;
	cin>>choice;

	cout<<endl;


	if (choice != 'y' && choice != 'n'){
	cout<<"Enter a valid choice (y or n)"<<endl;
	goto start_choice;}

	else if (choice == 'y') {
	//calling the Ak coefficients function to calculate a0, a2 and a4 for pure transitions//
		a0_pure = (Ak(I1, L1, L1, I2,0,0))*(Ak(I3, L3, L3, I2,0,0));
		a2_pure = (Ak(I1, L1, L1, I2,0,2))*(Ak(I3, L3, L3, I2,0,2));
		a4_pure = (Ak(I1, L1, L1, I2,0,4))*(Ak(I3, L3, L3, I2,0,4));


	//Opening a file 'angcorr_pure.dat' to put in the angles and the corresponding values as calculated from W2 fuction for pure transitions//
		ofstream outfile ("angcorr_pure.dat");
		if (!outfile) {
		cout<<"angcorr_pure.dat could not be opened for writing!"<<endl;
		exit(1);
		}


		//Calling the W2 function for angles from 0-180 degrees//
		for (float theta=0; theta<=180; theta=theta+5.0) {
		float theta_rad = (theta*3.14159)/180;
		outfile<<theta<<"   "<<angcor(theta_rad,a2_pure,a4_pure)<<endl;
		}


		cout<<"File \"angcorr_pure.dat\" with the angular correlation values for pure transitions successfully created!"<<endl;

		outfile.close();
		}

	cout<<endl;
	

return 0;
}

	
