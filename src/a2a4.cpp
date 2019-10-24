//*********************************************************************************************************//

//                Code to verify the a2 vs. a4 dependence varying d1 with a constant d2 		   //
//				for 1--2 directional angular correlation                   		   //
//      		            Author: Nirupama Sensharma				                   //
//			            Date: December 20, 2017					           //
              
//*********************************************************************************************************//


#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

#include "declare.h"
using namespace std;


float a2a4(float I1, float I2, float I3, float L1, float L2, float L3, float L4, float d2)
{
	float A2 = 0., A4 = 0.;
	float mix_ratio;

	ofstream file ("a2a4.dat");
	if (!file) {
		cout<<"a2a4.dat could not be opened for writing!"<<endl;
		exit(1);
		}

	for (mix_ratio = -20.0; mix_ratio < 20.0; mix_ratio = mix_ratio + 0.1){
		A2 = (Ak(I1, L1, L2, I2,mix_ratio,2))*(Ak(I3, L3, L4, I2,d2,2));
		A4 = (Ak(I1, L1, L2, I2,mix_ratio,4))*(Ak(I3, L3, L4, I2,d2,4));
		file<<A2<<"   "<<A4<<endl;
	}	
	
	file.close();

return 0;
}
