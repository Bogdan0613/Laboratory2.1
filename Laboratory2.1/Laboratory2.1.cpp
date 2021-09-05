#include<iostream>
using namespace std;
static void cin_check(int* x, int i) {
	if (!cin) {
		cout << "Bad value!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter again:";
		cin >> x[i];
	}
}
static void extracted(int amount, int* coordinate1, int* coordinate2) {
	for (int i = 0; i < amount; i++) {
		cout << "Enter the x coordinate of the " << i + 1 << " top:";
		cin >> coordinate1[i];
		cin_check(coordinate1, i);
		cout << "Enter the y coordinate of the " << i + 1 << " top:";
		cin >> coordinate2[i];
		cin_check(coordinate2, i);
	}
}

int main() {
	int amount, choose;
	int straight = 0, x, y;
	bool is_polygon = 0;
	while (true) {
		cout << "Enter the amount of the sides:";
		cin >> amount;
		int* coordinate1 = new int[amount];
		int* coordinate2 = new int[amount];
		extracted(amount, coordinate1, coordinate2);
		for (int i = 2; i < amount; i++) {
			x = coordinate1[i];
			y = coordinate2[i];
			straight = (x - coordinate1[0]) / (coordinate1[1] - coordinate1[0]) - (y - coordinate2[0]) / (coordinate2[1] - coordinate2[0]);
			if (straight != 0) {
				cout << "The polygon with such tops exists" << endl;
				is_polygon = 1;
				break;
			}
			else is_polygon = 0;
		}
		if (is_polygon == 0) {
			cout << "The polygon with such tops does not exist! All the tops lay on one straight" << endl;
		}
		cout << "Enter 1 to continue" << endl << "Enter 2 to exit";
		cin >> choose;

		if (choose != 1 && choose != 2) {
			cout << "Bad value, enter again" << endl;
			cin >> choose;
		}
		if (choose == 2) break;
		else if (choose == 1)continue;
	}
}
