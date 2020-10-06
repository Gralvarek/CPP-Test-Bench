#include <iostream>
#include <Net.hpp>


enum class CustomMsgTypes : uint32_t
{
	FireBullet,
	MovePlayer

};

int main()
{
	net::Message<CustomMsgTypes> msg;
	msg.header.id = CustomMsgTypes::FireBullet;

	int a = 1;
	bool b = true;
	float c = 3.14159f;

	struct
	{
		float x, y;
	} d[5];

	msg << a << b << c << d;

	a = 13;
	b = false;
	c = 99.0f;

	msg >> d >> c >> b >> a;

	return 0;
}
