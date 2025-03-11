#include <iostream>

struct Rect
{
	int x1, y1; // координаты верхнего левого угла области
	int x2, y2; // координаты нижнего правого угла области
};

double IoU(const Rect& region1, const Rect& region2)
{
	double square1, square2, smallX, smallY, smallSquare, bigSquare, result;
	square1 = (region1.x2 - region1.x1) * (region1.y2 - region1.y1);
	square2 = (region2.x2 - region2.x1) * (region2.y2 - region2.y1);
	if (region1.x2 > region2.x2 && region1.y2 > region2.y2 && region2.x1 > region1.x1 && region1.y2 > region2.y2)	// если предсказанная область внутри искомой
	{
		smallX = region2.x2 - (region2.x1 - region1.x1);	// расчет пересечения по оси X
		smallY = region2.y2 - (region2.y1 - region1.y1);	// расчет пересечения по оси Y
	}
	else if (region1.x1 < region2.x1 && region1.y1 < region2.y1)	// начало предсказанной области 
	{
		smallX = region2.x2 - (region2.x1 - region1.x1) - (region2.x2 - region1.x2);
		smallY = region2.y2 - (region2.y1 - region1.y1) - (region2.y2 - region1.y2);
	}
	else if (region1.x1 > region2.x1 && region1.y1 > region2.y1)
	{
		smallX = region1.x2 - (region1.x1 - region2.x1) - (region1.x2 - region2.x2);
		smallY = region1.y2 - (region1.y1 - region2.y1) - (region1.y2 - region2.y2);
	}
	else 

	smallSquare = smallX * smallY;
	bigSquare = square1 + square2 - smallSquare;
	return result = smallSquare / bigSquare;
}

int main()
{
	Rect r1{ 0,0,30,40 }, r2{ 15,15,120,25 };
	//double result1 = IoU(r1, r2);
	//double result1 = IoU(Rect{ 0,0,5,5 }, Rect{ 2,2,3,3, });
	//double result1 = IoU(Rect{ 0,0,4,4 }, Rect{ 2,2,6,6 });
	double result1 = IoU(Rect{ 2,2,6,6 }, Rect{ 0,0,4,4 });
	std::cout << result1 << std::endl;
}