//
//CSE455 Software Engineering assignment
//Program that calculates the correlation between two sets of data
//
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

class Correlation
{
public:
     double calculation(list<double> x, list<double> y)
     {
          list<double>::iterator it = x.begin();
          list<double>::iterator it2;
     
          double product, new_product, sum_X, sum_Y, new_x, new_y;
          while (it != x.end()){
               for (it2 = y.begin(); it2 != y.end(); it2++){
                    product += ((*it) * (*it2));
                    sum_X += *it;
                    sum_Y += *it2;
                    new_x += pow (*it, 2);
                    new_y += pow(*it2, 2);
                    it++;
               }
          }

          double numerator = ((product*7) - (sum_X * sum_Y));
          double new_sum_X = pow(sum_X, 2);
          double new_sum_Y = pow(sum_Y, 2);
          double difference_X = ((7*new_x) - new_sum_X);
          double difference_Y = ((7*new_y) - new_sum_Y);
          
          double denominator = sqrt(difference_X * difference_Y);
          
          double r  = (numerator/denominator);
          return r;
     }
     double significance(list<double> x, list<double> y)
     {
	Correlation corr;
	double a = corr.calculation(x,y);
	double numerator = (abs(a)*(sqrt(5)));
	double denominator = sqrt(1-pow(a,2));
	double t = numerator/denominator;
	return t;
     }
     double find_p(list<double> x, list<double> y)
     {
	Correlation corr;
	double t = corr.significance(x,y);

 	Correlation chart;
     	list<double> p;
     	list<double> n;
     
     	p.push_back(0.6);
     	p.push_back(0.7);
    	     p.push_back(0.85);
     	p.push_back(0.90);
     	p.push_back(0.95);
     	p.push_back(0.975);
     	p.push_back(0.99);
     	p.push_back(0.995);

     	n.push_back(0.267);
     	n.push_back(0.559);
     	n.push_back(1.156);
     	n.push_back(1.476);
     	n.push_back(2.015);
     	n.push_back(2.571);
     	n.push_back(3.365);
     	n.push_back(4.032);
	
	double Nhigh;
	double Phigh;
	double Nlow;
	double Plow;
	list<double>::iterator it = n.begin();
        list<double>::iterator it2;
	while(it!=n.end())
	{
		for(it2 = p.begin(); it2!=p.end(); it2++)
		{
			if(*it > t)
			{
				Nhigh = *it;
				Phigh = *it2;
				Nlow = *it--;
				Plow = *it2--;
			}
			else
			{
				it++;
			}	
		}
		return Nhigh, Phigh, Nlow, Plow;
		
	} 
	double a = Nhigh - Nlow;
	double b = t - Nlow;
	double z = Phigh - Plow;
	double p_value = (b*z)/a;
	return p_value;
     }

};

int main()
{
     Correlation c;
     list<double> x;
     list<double> y;
     
     x.push_back(400);
     x.push_back(450);
     x.push_back(1700);
     x.push_back(1600);
     x.push_back(1958);
     x.push_back(2030);
     x.push_back(125);

     y.push_back(26.6);
     y.push_back(30.2);
     y.push_back(36.6);
     y.push_back(48.8);
     y.push_back(58.5);
     y.push_back(55.6);
     y.push_back(32.3);

     double r = c.calculation(x,y);
     cout<<"R: "<<r<<endl;
     cout<<endl;
     
     double r_squared;
     r_squared = pow(r,2);
     cout<<"R^2(correlation): "<<r_squared<<endl;
     cout<<endl;

     double t_value;
     t_value = c.significance(x,y);
     cout<<"T: "<<t_value<<endl;
     cout<<endl;

     Correlation chart;
     double p_value;
     p_value = chart.find_p(x,y);
     cout<<"P: "<<p_value<<endl;
     cout<<endl;
  
     double o_value;
     o_value = (2*(1-p_value));
     cout<<"2*(1-p): "<<o_value<<endl;
     cout<<endl;
}






