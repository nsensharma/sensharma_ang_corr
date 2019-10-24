//*********************************************************************************************************//

//                Functions for calculating 1--2 and 1--3 Directional Angular Correlation                  //
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
	
		//****DEFINING ALL THE FUNCTIONS REQUIRED IN CALCULATING THE COEFFICIENTS****//

	//defining the factorial function//	
	float fact(int n)		
	{
    	if ((n ==0))
	return 1;
	else if (n<0) 
	return 0;
	else
        return n * fact(n - 1);
	}



	//defining the triangle function//
	float tf(float a, float b, float c)			
	{
	float term = (((fact(a+b-c))*(fact(a-b+c))*(fact(-a+b+c)))/(fact(a+b+c+1)));
	return term;
	}



	//defining the Racah-W coefficient//
	float W(float a, float b, float c, float d, float e, float f)
	{
	float term1 = sqrt(tf(a,b,e) * tf(c,d,e) * tf(a,c,f) * tf(b,d,f));
	float sum = 0;
	float alpha1 = a+b+e;
	float alpha2 = c+d+e;
	float alpha3 = a+c+f;
	float alpha4 = b+d+f;
	float beta1 = a+b+c+d;
	float beta2 = a+d+e+f;
	float beta3 = b+c+e+f; 
	
	for(int z=0; z<10000; ++z) {
		if (((z-alpha1)>=0) && ((z-alpha2)>=0) && ((z-alpha3)>=0) && ((z-alpha4)>=0) && ((beta1-z)>=0) && ((beta2-z)>=0) && ((beta3-z)>=0)){
		float term2 = pow(-1,(z+beta1));
		float term3 = fact(z+1);
		float term4 = (fact(z-alpha1))*(fact(z-alpha2))*(fact(z-alpha3))*(fact(z-alpha4))*(fact(beta1-z))*(fact(beta2-z))*(fact(beta3-z));
				sum += term1*term2*term3*(1/term4);}
		else sum += 0;}
	return sum;
	}



	//defining the wigner-6j function//	
	float w6j(float a, float b, float c, float d, float e, float f)
	{
	float term1 = pow(-1,(a+b+c+d));
	return term1*W(a,b,c,d,e,f);
	}	



	//defining wigner-3j function//
	float w3j(float j1, float j2, float j, float m1, float m2, float m)		
	{
	float sum = 0;	
	float term1 = pow(-1,(j1-j2-m));
	float term2 = sqrt(tf(j1,j2,j));
	float term3 = sqrt((fact(j1+m1))*(fact(j1-m1))*(fact(j2+m2))*(fact(j2-m2))*(fact(j+m))*(fact(j-m)));

	for(int t=0; t<10000; ++t) {
		if (((j-j2+t+m1)>=0) && ((j-j1+t-m2)>=0) && ((j1+j2-j-t)>=0) && ((j1-t-m1)>=0) && ((j2-t+m2)>=0)){
				float term4 = pow(-1,t);
				float term5 = (fact(t))*(fact(j-j2+t+m1))*(fact(j-j1+t-m2))*(fact(j1+j2-j-t))*(fact(j1-t-m1))*(fact(j2-t+m2));
				sum += ((term1*term2*term3)*(term4/term5));}
		else sum += 0;}
	//checking for all the conditions for non-zero wigner 3j symbols//
	if ((m != m1+m2)|| ((j1+j2-j)<0) || ((j1-j2+j)<0) || ((-j1+j2+j)<0))
	return 0;
	else return sum;
	}



	//defining the Clebsch-Gordan Coefficients//
	float CG(float j1, float j2, float m1, float m2, float j, float m)	
	{
	float term1 = pow(-1,(j1-j2+m));
	float term2 = sqrt((2*j)+1);
	float term3 = w3j(j1,j2,j,m1,m2,-m);
	return term1*term2*term3;
	}



	//defining the F-coefficients//
	float F(float Jf, float L1, float L2, float Ji, int k)			
	{
	float fterm = pow(-1,(Jf-Ji-1))*(sqrt(((2*L1)+1)*((2*L2)+1)*((2*Ji)+1)));
	return fterm*CG(L1,L2,-1,1, k, 0)*w6j(Ji, Jf, k, L2, L1, Ji);
	}

//W(Ig3,Ig2,0,Lg3,Ig2,Ig3)

	//defining the statistical tensor//
	float B(float J, int k)					
	{
	float term;
	if ((int)(J) % 2 == 0)
		term = (sqrt(((2*J)+1))*(pow(-1,J))*CG(J, J, 0, 0, k, 0));
	else
		term = (sqrt(((2*J)+1))*(pow(-1,(J-0.5)))*CG(J, J, 0.5, -0.5, k, 0));
	return term;
	}



	//defining the f-coefficients//
	float f(float Jf, float L1, float L2, float Ji, int k)		
	{
	return B(Ji,k) * F(Jf, L1, L2, Ji,k);
	}



	//defining the Ak coefficients (to be used in the 1--2 angular correlation function)//
	float Ak(float Jf, float L1, float L2, float Ji, float d, int k)	
	{
	float term = (F(Jf,L1,L1,Ji,k) + ((2*d)*(F(Jf,L1,L2,Ji,k))) + ((d*d)*(F(Jf,L2,L2,Ji,k))))/(1+(d*d));
	return term;
	}

	

	//defining the Ak coefficients (to be used in the 1--3 angular correlation function)//
	float Agk(float Jf, float L1, float L2, float Ji, float d, int k)	
	{
	float term = (F(Jf,L1,L1,Ji,k) + ((2*d)*(F(Jf,L1,L2,Ji,k))) + ((d*d)*(F(Jf,L2,L2,Ji,k))));
	return term;
	}



	//defining the angular correlation function//
	float angcor(float theta,float a2, float a4)
	{	
	float P2=0.5*(3*cos(theta)*cos(theta)-1);
	float P4=0.125*(35*cos(theta)*cos(theta)*cos(theta)*cos(theta)-30*cos(theta)*cos(theta));
	float W2 = (1+a2*P2+a4*P4);
	return W2;
	}

	
