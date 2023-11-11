#ifndef KOMPLEX_H
#define KOMPLEX_H


#include <string>
class komplex
{
public:
    komplex();
    komplex(float re,float im=0.0);
    static komplex fromAbsArg(float a,float grader);
    float re() const;
    float im() const;
    float abs() const;
    float argRadians() const;
    float argDegrees() const;


    komplex konjugat() const;

    operator std::string() const;


    const komplex& operator+=(const komplex& h);
    const komplex &operator-=(const komplex& h);
    const komplex& operator*=(const komplex& h);
    const komplex& operator/=(const komplex& h);
private:
    float m_re;
    float m_im;
};


komplex operator "" _i(long double d);
komplex operator "" _i(unsigned long long i);

komplex operator +(const komplex& v, const komplex& h);
komplex operator -(const komplex& v,const komplex& h);
komplex operator-(const komplex& c);
komplex operator*(const komplex& v,const komplex& h);
komplex operator/(const komplex& v,const komplex& h);


std::ostream& operator<<( std::ostream& out, komplex c);

#endif // KOMPLEX_H
