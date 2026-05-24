import <climits>;
import PPP;
using namespace std;
const string fname = "00.txt";

int main()
{
	double x = -1;
	char ch;
	cin.get(ch);
	if (cin)
	{
		cin.putback(ch);
		cin >> x;
		cout << x << '\n';
	}
	cout << x;
}
