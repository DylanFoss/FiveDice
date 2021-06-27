#include "Controller.h"

Controller::Controller()
{
	space = false;
	escape = false;
}

void Controller::keyUp()
{

}

void Controller::keyDown(unsigned char key)
{
	switch (key)
	{
		case 27:
			escape = true;
			break;
		case 32:
			space = true;
			break;
	}
}
