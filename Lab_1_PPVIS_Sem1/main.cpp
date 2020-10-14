#include "Rectangle.h"
#include "Exception.h"
#include "UserInterface.h"
#include <iostream>
using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	UserInterface user = UserInterface();
	user.Menu();

	return 0;
}

