#pragma once

void writegraphicsmenu()
{
	cout << "GRAPHICS MODE" << endl;

	cout << "-------------" << endl;

	cout << "0=EXIT" << endl;

	cout << "1=640 x 480 (Full)" << endl;
	cout << "2=800 x 600 (Full)" << endl;
	cout << "3=800 x 600" << endl;
	cout << "4=1200 x 600" << endl;
	cout << "5=1300 x 600" << endl;
	cout << "6=Full screen (recommended)" << endl;

	cout << "Choose option (0...6) and press RETURN: ";
		
}


void waiting(int n)
{
	cout << flush;

	cout << "\nWaiting for Running ..." << endl;
	
	do
	{
		n = n - 1;

		cout << " " << n << " " << "\r";

	} while (n > 0);

	cout << flush;
}

int option()
{
	int retval = -1;

	int _opt = -1;

	writegraphicsmenu();

	cin >> _opt;

	while (true)
	{
		switch (_opt)
		{
			case 0:
				exit(0);

			case 1:
				retval = 1;
				break;

			case 2:
				retval = 2;
				break;
			
			case 3:
				retval = 3;
				break;

			case 4:
				retval = 4;
				break;

			case 5:
				retval = 5;
				break;

			case 6:
				retval = 6;
				break;
		}

		if (_opt > 0) break;
	}
	
	waiting(3864);

	gmode = retval;

	return retval;
}



