#include <iostream>
using namespace std;

class Vec4{
	public:
		Vec4(float a = 0.0f,float b = 0.0f,float c = 0.0f,float d = 0.0f);
		~Vec4(){}
		float getx() const;
		float gety() const;
		float getz() const;
		float getw() const;
		float& operator [](int n);
		Vec4& operator +=(Vec4 v);
		Vec4& operator -=(Vec4 v);
		Vec4& operator *=(Vec4 v);
		Vec4& operator /=(Vec4 v);
		
		private:
			float x,y,z,w;
};

ostream& operator <<(ostream& out,const Vec4 v){
	out << "(" << v.getx() << "," << v.gety() << ",";
	out << v.getz() << "," << v.getw() << ")" << endl;
	
	return out;
}

float Vec4 :: getx() const{
	return x;
}

float Vec4 :: gety() const{
	return y;
}

float Vec4 :: getz() const{
	return z;
}

float Vec4 :: getw() const{
	return w;
}

Vec4 :: Vec4(float a,float b,float c,float d): x(a),y(b),z(c),w(d){
} 

float& Vec4 :: operator [](int n){
	if(n > 3)
	{
		n = 3;
	}
	else if(n < 0)
	{
		n = 0;
	}
	switch(n)
	{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		case 3:
			return w;
			break;
		default:
			break;
	}
}

Vec4& Vec4 :: operator +=(Vec4 v){
	x += v.getx();
	y += v.gety();
	z += v.getz();
	w += v.getw();
	return *this;
}

Vec4& Vec4 :: operator -=(Vec4 v){
	x -= v.getx();
	y -= v.gety();
	z -= v.getz();
	w -= v.getw();
	return *this;
}

Vec4& Vec4 :: operator *=(Vec4 v){
	x *= v.getx();
	y *= v.gety();
	z *= v.getz();
	w *= v.getw();
	return *this;
}

Vec4& Vec4 :: operator /=(Vec4 v){
	if(v.x != 0.0f && v.y != 0.0f && v.z != 0.0f && v.w != 0.0f)
	{
		x /= v.getx();
		y /= v.gety();
		z /= v.getz();
		w /= v.getw();
		return *this;
	}
	else
	{
		cout << "除数不能为0！" << endl;
		return *this;
	}
}

Vec4 operator +(const Vec4 v1,const Vec4 v2)
{
	Vec4 t = v1;
	t += v2;
	return t;
}

Vec4 operator -(const Vec4 v1,const Vec4 v2)
{
	Vec4 t = v1;
	t -= v2;
	return t;
}

Vec4 operator *(const Vec4 v1,const Vec4 v2)
{
	Vec4 t = v1;
	t *= v2;
	return t;
}

Vec4 operator /(const Vec4 v1,const Vec4 v2)
{
	Vec4 t = v1;
	t /= v2;
	return t;
}

int main(int argc,char* argv[])
{
	Vec4 v1(1.2,2.2,3.2,4.2);
	Vec4 v2(1.1);
	cout << v2 / v1;
	cout << v1[1]; 
	return 0;
}
