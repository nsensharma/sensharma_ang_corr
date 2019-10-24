//*********************************************************************************************************//

//                Code to calculate the coefficients for Gamma-Gamma-Gamma (1--3) Angular Correlation      //
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
	
//declaration of the spins, multipolarities, mixing ratios and 1--3 angular correlation coefficients for mixed and pure transitions//
	float Ig1, Ig2, Ig3, Ig4, Lg1, Lg2, Lg3, Lg4, Lg5, Lg6;
	float dg1, dg2, dg3;
	float ag0, ag2, ag4;
	float ag0_pure, ag2_pure, ag4_pure;
	float Const;
	
int angcorr_ggg() 
	{
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"	    Gamma-Gamma-Gamma Angular Correlation Coefficients                        "<<endl;	
	cout<<endl;
	cout<<"		__________________________________"<<" Ig1"<<endl;
	cout<<"             		  	 |                  "<<endl;
	cout<<"             		  	 |                  "<<endl;
	cout<<"               		  	 |  Lg1,Lg2           "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 v                  "<<endl;
	cout<<"		__________________________________"<<" Ig2"<<endl;
	cout<<"              		  	 |                  "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 |  Lg3,Lg4           "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 v                  "<<endl;
	cout<<"		__________________________________"<<" Ig3"<<endl;
	cout<<"              		  	 |                  "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 |  Lg5,Lg6           "<<endl;
	cout<<"               		  	 |                  "<<endl;
	cout<<"               		  	 v                  "<<endl;
	cout<<"		__________________________________"<<" Ig4"<<endl;
	cout<<"                                               "<<endl;
	cout<<"*******************************************************************************"<<endl;
	cout<<"*******************************************************************************"<<endl;


	//Prompting user to enter the spin of the states involved//
	cout<<"Enter the spin of the initial state, Ig1"<<endl;
	cin>>Ig1;
	cout<<"Enter the spin of second state, Ig2"<<endl;
	cin>>Ig2;
	cout<<"Enter the spin of third state, Ig3"<<endl;
	cin>>Ig3;
	cout<<"Enter the spin of the final state, Ig4"<<endl;
	cin>>Ig4;

	//Checking if user entered either integer or half-integer values for the spins. Exiting with error otherwise//
	if (((int)((Ig1*10))%5 !=0) || ((int)((Ig2*10))%5 !=0) || ((int)((Ig3*10))%5 !=0) || ((int)((Ig4*10))%5 !=0)){
		cout<<"The spin values entered are not integers or half-integers.Try again!"<<endl;
		exit(1);}


	//Prompting user to enter the multipolaritiies and the mixing ratios of the three transitions involved//
	cout<<"Enter mixing ratio for first transition"<<endl;
	cin>>dg1;
		
	cout<<"Enter the multipolarity of the first transition, Lg1"<<endl;
	cin>>Lg1;
	if (dg1==0) //checking if it is a pure or a mixed transition//
	Lg2 = Lg1;
	else {cout<<"Enter the next possible multipole (in case of mixing) for the first transition, Lg2"<<endl;
	cin>>Lg2;}
	
	cout<<"Enter mixing ratio for intermediate transition"<<endl;
	cin>>dg2;
	cout<<"Enter the multipolarity of the intermediate transition, Lg3"<<endl;
	cin>>Lg3;
	if (dg2==0)
	Lg4 = Lg3;
	else {cout<<"Enter the next possible multipole (in case of mixing) for the intermediate transition, Lg4"<<endl;
	cin>>Lg4;}

	cout<<"Enter mixing ratio for third transition"<<endl;
	cin>>dg3;
	cout<<"Enter the multipolarity of the third transition, Lg5"<<endl;
	cin>>Lg5;
	if (dg3==0)
	Lg6 = Lg5;
	else {cout<<"Enter the next possible multipole (in case of mixing) for the third transition, Lg6"<<endl;
	cin>>Lg6;}
	
	
	Const = pow(-1,(Lg3-Ig2-Ig3))*sqrt(((2*Ig2)+1)*((2*Ig3)+1));
	
	ag0 = Const*Agk(Ig2,Lg1,Lg1,Ig1,dg1,0)*Agk(Ig3,Lg5,Lg5,Ig4,dg3,0)*(W(Ig2,Ig2,Ig3,Ig3,0,Lg3)+((dg2*dg2)*W(Ig2,Ig2,Ig3,Ig3,0,Lg4)));
	ag2 = Const*Agk(Ig2,Lg1,Lg1,Ig1,dg1,2)*Agk(Ig3,Lg5,Lg5,Ig4,dg3,2)*(W(Ig2,Ig2,Ig3,Ig3,2,Lg3)+((dg2*dg2)*W(Ig2,Ig2,Ig3,Ig3,2,Lg4)));
	ag4 = Const*Agk(Ig2,Lg1,Lg1,Ig1,dg1,4)*Agk(Ig3,Lg5,Lg5,Ig4,dg3,4)*(W(Ig2,Ig2,Ig3,Ig3,4,Lg3)+((dg2*dg2)*W(Ig2,Ig2,Ig3,Ig3,4,Lg4)));

		
	cout<<"The 1--3 angular correlation coefficients are: "<<endl<<"a0 = "<<ag0<<endl<<"a2 = "<<ag2<<endl<<"a4 = "<<ag4<<endl;	

	//Opening a file '1--3_angcorr.dat' to write in the angles and the corresponding values as calculated from W2 fuction//
	ofstream outfile ("1--3_angcorr.dat");
	if (!outfile) {
		cout<<"1--3_angcorr.dat could not be opened for writing!"<<endl;
		exit(1);
		}


	outfile<<"*******************************************************************************"<<endl;
	outfile<<"*******************************************************************************"<<endl;
	outfile<<"	    Gamma-Gamma-Gamma Angular Correlation Coefficients                 "<<endl;	
	outfile<<endl;
	outfile<<"		__________________________________"<<Ig1<<endl;
	outfile<<"             		  	 |                  "<<endl;
	outfile<<"             		  	 |                  "<<endl;
	outfile<<"               		  	 |  "<<Lg1<<","<<Lg2<<"(d="<<dg1<<")           "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 v                  "<<endl;
	outfile<<"		__________________________________"<<Ig2<<endl;
	outfile<<"              		  	 |                  "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 |  "<<Lg3<<","<<Lg4<<"(d="<<dg2<<")           "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 v                  "<<endl;
	outfile<<"		__________________________________"<<Ig3<<endl;
	outfile<<"              		  	 |                  "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 |  "<<Lg5<<","<<Lg6<<"(d="<<dg3<<")           "<<endl;
	outfile<<"               		  	 |                  "<<endl;
	outfile<<"               		  	 v                  "<<endl;
	outfile<<"		__________________________________"<<Ig4<<endl;
	outfile<<"                                               "<<endl;
	outfile<<"*******************************************************************************"<<endl;
	outfile<<"*******************************************************************************"<<endl;

		
	//Calling the W2 function for angles from 0-180 degrees//
	for (float theta=0; theta<=180; theta=theta+5.0) {
		float theta_rad = (theta*3.14159)/180;
		outfile<<theta<<"   "<<angcor(theta_rad,ag2,ag4)<<endl;
	}

	cout<<"File \"1--3_angcorr.dat\" with the 1--3 angular correlation values successfully created!"<<endl;
	outfile.close();

	cout<<endl;

	
	if (dg1 == 0 && dg2 == 0 && dg3 == 0)
	exit(1);

	char make_choice;
	start_make_choice:
	cout<<"Do you want pure 1--3 angular correlation results (y or n)?"<<endl;
	cin>>make_choice;

	cout<<endl;


	if (make_choice != 'y' && make_choice != 'n'){
	cout<<"Enter a valid choice (y or n)"<<endl;
	goto start_make_choice;}

	else if (make_choice == 'y') {
	//calling the Agk coefficients function to calculate a0, a2 and a4 for pure transitions//
	ag0_pure = Const*Agk(Ig2,Lg1,Lg1,Ig1,0,0)*Agk(Ig3,Lg5,Lg5,Ig4,0,0)*W(Ig2,Ig2,Ig3,Ig3,0,Lg3);
	ag2_pure = Const*Agk(Ig2,Lg1,Lg1,Ig1,0,2)*Agk(Ig3,Lg5,Lg5,Ig4,0,2)*W(Ig2,Ig2,Ig3,Ig3,2,Lg3);
	ag4_pure = Const*Agk(Ig2,Lg1,Lg1,Ig1,0,4)*Agk(Ig3,Lg5,Lg5,Ig4,0,4)*W(Ig2,Ig2,Ig3,Ig3,4,Lg3);
	//cout<<Const<<"  "<<ag0_pure<<"  "<<ag2_pure<<"  "<<ag4_pure<<endl;


	//Opening a file '1--3_angcorr_pure.dat' to put in the angles and the corresponding values as calculated from W2 fuction for pure transitions//
		ofstream outfile ("1--3_angcorr_pure.dat");
		if (!outfile) {
		cout<<"1--3_angcorr_pure.dat could not be opened for writing!"<<endl;
		exit(1);
		}


		//Calling the W2 function for angles from 0-180 degrees//
		for (float theta=0; theta<=180; theta=theta+5.0) {
		float theta_rad = (theta*3.14159)/180;
		outfile<<theta<<"   "<<angcor(theta_rad,ag2_pure,ag4_pure)<<endl;
		}


		cout<<"File \"1--3_angcorr_pure.dat\" with the 1--3 angular correlation values for pure transitions successfully created!"<<endl;

		outfile.close();
		}

	cout<<endl;
	

	
return 0;
}

	
