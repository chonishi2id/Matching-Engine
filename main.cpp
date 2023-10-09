#include <iostream>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "buyorder.h"
#include "buyorder.cpp"
//#include "sellorder.h"
//#include "engine.h"

using namespace std;

int main() {
	ifstream file;
	file.open("buyorders.csv");
	string line;
	vector<BuyOrder*> buyOrders;
	getline(file, line);
	while(getline(file, line)) {
		string username;
		float prestige;
		int quantity;
		int price;
		string temp;

		// extract username
		stringstream inputString(line);
		getline(inputString, username, ',');

		//extract prestige
		getline(inputString, temp, ',');
		prestige = atof(temp.c_str());

		// extract quantity
		getline(inputString, temp, ',');
		quantity = atoi(temp.c_str());

		//extract price;
		getline(inputString, temp, ',');
		price = atoi(temp.c_str());

		BuyOrder* curOrder = new BuyOrder(username, prestige, quantity, price);
		curOrder->printOrder();

		buyOrders.push_back(curOrder);
	}
	file.close();
	return 0;
}