#include <iostream>
#include "View.h"

//-----Constructor
View::View() {
	size = 11;
	scale = 2;
	origin.x = 0;
	origin.y = 0;
}

//--------Member Functions
bool View::GetSubscripts(int &out_x, int &out_y, Point2D location) {
	out_x = trunc((location.x - origin.x) / scale); //trunc() to remove decimal places
	out_y = trunc((location.y - origin.y) / scale);
	
	if ((out_x <= size && out_x >= origin.x) && (out_y <= size && out_y >= origin.y)) { //check if outside display
		return true;
	}
	
	cout << "An object is outside the display" << endl;
	return false;
}	
		
void View::Clear() {
	
	for (int j = size-1; j >= -1; j--) {
		for (int i = -1; i <= size-1; i++) {
			if (i >= 0 && j >= 0) {
				grid[i][j][0] = '.';
				grid[i][j][1] = ' ';
			}
		}
	}
}

void View::Plot(GameObject* ptr) {
	int x, y;
	if (GetSubscripts(x, y, ptr->GetLocation())) {
		if (grid[x][y][0] != '.' || grid[x][y][1] != ' ') {
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';
		} else {
			ptr->DrawSelf(grid[x][y]);
		}
	}
}

void View::Draw() { //given
	for (int j = size-1; j >= -1; j--) {
		for (int i = -1; i <= size-1; i++) {
			if (i == -1 && j%2 == 0) {
				cout << j*2;
				if (j/5 == 0) {
					cout << " ";
				}
			} else if (i == -1 && j%2 != 0) {
				cout << "  ";
			} else if (j == -1 && i%2 == 0) {
				cout << i*2;
				if (i/5 == 0) {
					cout << " ";
				}
				cout << "  ";
			}
			if (i >= 0 && j >= 0) {
				cout << grid[i][j][0] << grid[i][j][1];
			}
		}
		cout << endl;
	}
}
