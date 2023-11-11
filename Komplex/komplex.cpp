#include "komplex.h"
#include <cmath>
#include <iostream>
#include "assert.h"
using namespace std;

komplex::komplex()
{
    m_im=0;
    m_re=0;
}

komplex::komplex(float re, float im)
{
    m_re=re;
    m_im=im;

}

komplex komplex::fromAbsArg(float a, float grader)
{

   float x= a*cos(grader*M_PI/180);
   float y= a*sin(grader*M_PI/180);

    komplex abs(x,y);
    return abs;

}

float komplex::re() const
{
    return m_re;
}

float komplex::im() const
{
    return m_im;
}

float komplex::abs() const
{
  return sqrt( m_im*m_im + m_re* m_re);
}

float komplex::argRadians() const
{
    return atan2(m_im, m_re);

}

float komplex::argDegrees() const
{   return argRadians()* 180/M_PI;
    //komplex::argRadians()*M_PI/180; //fråga om du skrev rätt?
}

komplex komplex::konjugat() const
{
    return komplex(m_re, -m_im);
}

komplex::operator std::string() const
{
  std::string re= std::to_string(m_re);
  std::string im= std::to_string(m_im);
  std::string komplex = (re + im);
  return komplex;
}

const komplex &komplex::operator+=(const komplex &h)
{

    *this= *this+h;
    return *this;

}

const komplex &komplex::operator-=(const komplex &h)
{
  *this= *this-h;
    return *this;
}

const komplex &komplex::operator*=(const komplex &h)
{
  *this = *this*h;
    return *this;
}

const komplex &komplex::operator/=(const komplex &h)
{
    *this = *this/h;
      return *this;
}




komplex operator "" _i(long double d)
{
    return komplex(0,d);
}

komplex operator "" _i(unsigned long long i)
{
  return komplex(0,i);// osäker
}



komplex operator +(const komplex &v, const komplex &h)
{
//    *this = *this+h;   // varför funkar inte här den här metoden ???
//      return *this;
    return komplex (v.re()+h.re(),v.im()+h.im());
}

komplex operator -(const komplex &v, const komplex &h)
{
   return komplex (v.re()-h.re(), v.im()-h.im());
}

komplex operator-(const komplex& c)
{
  return komplex(-c.re(),-c.im());
  ///return komplex(-c.re(),0.0); // här tänker jag om finns bara en imparameter då är det
  /// bara en reel tal...
}

komplex operator*(const komplex &v, const komplex &h)
{
  return komplex(  v.re()*h.re()-v.im()*h.im()  ,  v.re()*h.im()+v.im()*h.re() );
}

komplex operator/(const komplex &v, const komplex &h)
{

    komplex taljare = v * h.konjugat();
    komplex namnare = h * h.konjugat();
    assert( abs(namnare.im()) < 0.001);
    return komplex ( taljare.re()/namnare.re(), taljare.im()/namnare.re());

}

std::ostream &operator<<(std::ostream &out, komplex c)
{
  out << std::string( c );
  return out;
}

void assertApprox(komplex c1, komplex c2){
    komplex diff = c1-c2;
    assert( diff.abs() <0.001);
}

void testKod(){
    komplex c1= 1+3.0_i;
    komplex c2= 5-5_i;

    assertApprox(c1+c2,komplex(6,-2));
    assertApprox(c1,(c1*c2)/c2);

    assertApprox(2*c1,komplex(2,6));
    assertApprox(c1*2,komplex(2,6));

    komplex k=1;
    komplex rotate30 = komplex ::fromAbsArg(1,30);
    for (int i=0; i <12 ; i++){
        k *= rotate30;
        cout << i << '\t' << k << endl;
    }
}

int main()
{
    testKod();
    cout << "Hello World!" << endl;
    return 0;
}

