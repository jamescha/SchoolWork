#ifndef DATA_H
#define DATA_H

class DATA
{
public:
	DATA();
	~DATA();
	void setValue(int);
	int getValue();

private:
	int value;
};

DATA::DATA()
{
	value = 0;
}

void DATA::setValue(int x)
{
	value = x;
}

int DATA::getValue()
{
	return value;
}

DATA::~DATA()
{
}

#endif
