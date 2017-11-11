#include <iostream>
using namespace std;
struct circle 
{
	int xpos;
	int ypos;
	int r;
};

int check(int startXpos, int startYpos, int finXpos, int finYpos, circle* cir, int size)
{
	int cnt = 0;
	bool inStart = false;
	bool inFinish = false;

	for (int i = 0; i < size; i++)
	{

		if (((startXpos - cir[i].xpos) * (startXpos - cir[i].xpos)) + ((startYpos - cir[i].ypos) * (startYpos - cir[i].ypos)) < (cir[i].r * cir[i].r))
			inStart = true;

		if (((finXpos - cir[i].xpos) * (finXpos - cir[i].xpos)) + ((finYpos - cir[i].ypos) * (finYpos - cir[i].ypos)) < (cir[i].r * cir[i].r))
			inFinish = true;

		if (inStart == true && inFinish == false)
			cnt++;
		else if (inStart == false && inFinish == true)
			cnt++;
	}

	return cnt;
}

int main() 
{
	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) 
	{
		int startXpos;
		int startYpos;
		int finXpos;
		int finYpos;
		cin >> startXpos >> startYpos >> finXpos >> finYpos;

		int num;
		circle* cir;

		cin >> num;
		cir = new circle[num]();

		for (int t = 0; t < num; t++)
			cin >> cir[t].xpos >> cir[t].ypos >> cir[t].r;

		cout << check(startXpos, startYpos, finXpos, finYpos, cir, num) << endl;
	}
}
