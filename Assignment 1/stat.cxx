
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include "stats.h"
#include <cassert>
using namespace std;
namespace main_savitch_2C {
			statistician::statistician(){
				reset();
			}
			void statistician::next(double r){
				count++;

				if(count==1){
					tinyest=r;
					largest=r;
					total=r;
				}
				else {
					if(r>largest) largest=r;
					if(r<tinyest) tinyest=r;
					total=total+r;
				}

			}
			void statistician::reset(){
				count=0;
				total=0;
				tinyest=0;
				largest=0;
			}
			int statistician::length() const{
				int length=count;
				return length;
			}
			double statistician::sum() const{
				int sum=total;
				return sum;
			}
			double statistician::mean()const {
				assert(length()>=1);
				return(sum()/length());
			}
			double statistician::minimum()const{
				assert(length()>=1);
				double min=tinyest;
				return min;
			}
			double statistician::maximum()const{
				assert(length()>=1);
				double max=largest;
				return max;
			}
			bool operator ==(const statistician& s1, const statistician& s2){
			if (s1.length()==0 && s2.length()==0) return true;
			if(
			 (s1.length( ) == s2.length( ))
			 &&
			 (s1.sum( ) == s2.sum( ))
			 &&
			 (s1.minimum( ) == s2.minimum( ))
			 &&
			 (s1.maximum( ) == s2.maximum( ))) return true;
			 else return false;

			}
		statistician operator +(const statistician& s1, const statistician& s2){
			if (s1.length( ) == 0)
				return s2;
			if (s2.length( ) == 0)
				return s1;

			else{
			statistician s3;
			s3.count=s1.length()+s2.length();
			s3.total=s1.sum()+s2.sum();

			if(s1.minimum()>s2.minimum()) s3.tinyest=s2.minimum();
			else s3.tinyest=s1.minimum();

			if(s1.maximum()>s2.maximum()) s3.largest=s1.maximum();
			else s3.largest=s2.maximum();
			return s3;

		}


				}
		 statistician operator *(double scale, const statistician& s){
			 if(s.length()<=0) return s;
			 
			  statistician s1;
			 s1.count=s.length();
			 s1.total=s.sum()*scale;
			 
			 if(scale>=0){
			 s1.tinyest=s.minimum()*scale;
			 s1.largest=s.maximum()*scale;
		 }
			 else{
			 s1.tinyest=s.maximum()*scale;
			 s1.largest=s.minimum()*scale;
		}
			 return s1;
				

			}


	}
