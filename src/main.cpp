#include <iostream>
#include "lin1d.h"
#include "nonlin1d.h"
#include "diffusion1d.h"
#include "burgers.h"
#include "arrayops.h"
#include "lin2d.h"
#include "nonlin2d.h"


using namespace std;

int main()
{
    int selection;

    for (;;) {
        cout << "Please select a program (int between 1-7 inclusive): ";
        if ((cin >> selection) && ((selection > 0) && (selection < 8))) {
            switch (selection) {
                case 1:
                    lin1d();
                break;

                case 2:
                    nonlin1d();
                break;

                case 3:
                    diffusion1d();
                break;
		
		case 4:
		    burgers();
		break;
		
		case 5:
		    arrayops();
		break;
		
		case 6:
		    lin2d();
		break;
		
		case 7:
		    nonlin2d();
		break;

                default:
                    cout << "Something went horribly wrong.";
            }

            break;
        } else {
            cout << "Please enter a valid integer betwen 1 and 7 inclusive:"  << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

}
