#include<iostream>
using namespace std;

class Polynomial
{
  private:
  	int degree;
  	int cof[10];
  public:
    Polynomial()
    {
        degree=0;
    }

    Polynomial(int deg)
    {
    	degree=deg;
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
    }
  
    //  Overload copy constructor, +, - and = operators
  	
  	Polynomial operator+(Polynomial const &p)
  	{
  		int min=this->degree<p.degree?this->degree:p.degree;
  		for(int i=min;i>=0;i--)
  		{
  			
			this->cof[i]=this->cof[i]+p.cof[i];
		}
		return *this;
	}
	Polynomial operator-(Polynomial const &p)
  	{
  	
  		int min=this->degree<p.degree?this->degree:p.degree;
  		for(int i=min;i>=0;i--)
  		{
  			
			this->cof[i]=this->cof[i]-p.cof[i];
		}
		return *this;
	}
    void storePolynomial()
    {
      	cout<<"\nEnter polynomial:";
      	for(int i=degree;i>=0;i--)
      	{
      		cout<<"\nEnter coeffecient of x^"<<i<<" term:";
			cin>>cof[i];	
		}
    
    }
    void display()
    {
    	cout<<"\nPolynomial is:";
		for(int i=degree;i>=0;i--)
		{
			cout<<cof[i];
				
			if(i!=0 && cof[i]>0)
			{
				cout<<"x^"<<i<<" + ";
			}
			else if(i!=0 && cof[i]<0)
			{
				cout<<"x^"<<i<<"  ";
			}
		}
      //  Code to print the polynomial in readable format
    }
  
};

int main()
{
  int degFirst, degSecond;
  // Ask user to input the values of degFirst and degSecond
  cout<<"\nEnter degree of first polynomial:";
  cin>>degFirst; 
  cout<<"\nEnter degree of second polynomial:";
  cin>>degSecond;
  Polynomial firstPolynomial(degFirst) ;
  Polynomial secondPolynomial(degSecond);
  cout<<"\nEnter first Polynomial:";
  firstPolynomial.storePolynomial();
  cout<<"\nEnter Second Polynomial:";
  secondPolynomial.storePolynomial();
  Polynomial thirdPolynomial;
  Polynomial fourthPolynomial;
  if(degFirst>degSecond)
  {
  	thirdPolynomial=firstPolynomial;
  	fourthPolynomial=firstPolynomial;
  	thirdPolynomial=thirdPolynomial+secondPolynomial;
	fourthPolynomial=fourthPolynomial-secondPolynomial;
  }
  if(degSecond>degFirst)
  {
  	thirdPolynomial=secondPolynomial;
  	fourthPolynomial=secondPolynomial;
  	thirdPolynomial=thirdPolynomial+firstPolynomial;
	fourthPolynomial=fourthPolynomial-firstPolynomial;
  }
  
  firstPolynomial.display();
  secondPolynomial.display();
  cout<<"\nRESULT:";
  thirdPolynomial.display();
  cout<<"\nRESULT:";
  fourthPolynomial.display();
  return 0;
}
