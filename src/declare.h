//*********************************************************************************************************//

//                Variable declaration for 1--2 and 1--3 Directional Angular Correlation                   //
//      		            Author: Nirupama Sensharma				                   //
//			            Date: November 18, 2018					           //
              
//*********************************************************************************************************//


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;
	
	
		//****DECLARING ALL THE FUNCTIONS REQUIRED IN CALCULATING THE COEFFICIENTS****//

		
	float fact(int n);		
		//defining the factorial function//



	float tf(float a, float b, float c);			
		//defining the triangle function//


	
	float W(float a, float b, float c, float d, float e, float f);
		//defining the Racah-W coefficient//



	float w6j(float a, float b, float c, float d, float e, float f);
		//defining the wigner-6j function//	


	
	float w3j(float j1, float j2, float j, float m1, float m2, float m);		
		//defining wigner-3j function//	

	
	float CG(float j1, float j2, float m1, float m2, float j, float m);	
		//defining the Clebsch-Gordan Coefficients//


	
	float F(float Jf, float L1, float L2, float Ji, int k);			
		//defining the F-coefficients//
	

	
	float B(float J, int k);				
		//defining the statistical tensor//
	

	float f(float Jf, float L1, float L2, float Ji, int k);		
		//defining the f-coefficients//


	
	float Ak(float Jf, float L1, float L2, float Ji, float d, int k);	
		//defining the Ak coefficients (to be used in the 1--2 angular correlation function)//



	float Agk(float Jf, float L1, float L2, float Ji, float d, int k);	
		//defining the Ak coefficients (to be used in the 1--3 angular correlation function)//



	float angcor(float theta,float a2, float a4);
		//defining the angular correlation function//


	
	float a2a4(float I1, float I2, float I3, float L1, float L2, float L3, float L4, float d2);
		//defining the function to check the variation of a2 vs. a4 at constant d2//

	

	int angcorr_main();
		//defining the angular correlation function for 1--2 directional correlation//



	int angcorr_ggg();
		//defining the angular correlation function for 1--3 directional correlation//

	


	
