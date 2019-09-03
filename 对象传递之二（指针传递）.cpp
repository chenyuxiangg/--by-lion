#include"iostream"
using namespace std;
class Squre
{
public:
	Squre(float len);
	void output();
	void add(Squre* s);
private:
	float length;
};

Squre::Squre(float len) :length(len)
{}

void Squre::output()
{
	cout << "s = " << length * length << endl;
}

void Squre::add(Squre* s)
{
	s->length += 1.0;
}

int main(int argc, char* argv[])
{
	Squre s(2.5);
	cout << "add before: " << endl;
	s.output();
	s.add(&s);
	cout << "add after: " << endl;
	s.output();

	return 0;
}