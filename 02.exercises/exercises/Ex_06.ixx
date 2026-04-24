export module Ex_06;

export void Ex_06();

import std;
using namespace std;

//排序输入的3个整数
void Ex_06()
{
	cout << "Please enter three integer values." << endl;
	int v1, v2, v3;
	cin >> v1 >> v2 >> v3;

	if (v1 > v2) swap(v1, v2);
	if (v1 > v3) swap(v1, v3);
	if (v2 > v3) swap(v2, v3);

	cout << v1 << ", " << v2 << ", " << v3 << endl;

	//if (v1 < v2)
	//{
	//	if (v1 < v3)	
	//	{
	//		if (v2 < v3)	//v1 < v2 < v3
	//			;
	//		else            //v1 < v3 < v2
	//			std::swap(v2, v3);
	//	}
	//	else                //v3 < v1 < v2
	//	{
	//		std::swap(v1, v3);
	//		std::swap(v2, v3);
	//	}
	//}
	//else
	//{
	//	if (v2 < v3)        
	//	{
	//		if (v1 < v3)	//v2 < v1 < v3
	//			std::swap(v1, v2);
	//		else            //v2 < v3 < v1
	//		{
	//			std::swap(v1, v2);
	//			std::swap(v2, v3);
	//		}
	//	}
	//	else               //v3 < v2 < v1
	//	{
	//		std::swap(v1, v3);
	//	}
	//}
}