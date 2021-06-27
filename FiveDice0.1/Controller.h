#pragma once
class Controller
{
	private:

		bool space;
		bool escape;

	public:

		Controller();

		void keyDown(unsigned char key);

		void keyUp();



};

