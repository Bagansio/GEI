#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cout.setf(ios::fixed);
	cout.precision(4);
    priority_queue<int, vector<int>, greater<int> > q;
    string o;
    int average = 0;
    int max;
    while (cin >> o)
    {
        if (o == "number")
        {
            int n; 
            cin >> n;

            if (q.empty() or n > max) max = n;
            q.push(n);
            average += n;

        }
        else if (o == "delete" and !q.empty())
        {
            average -= q.top();
            q.pop();
        }

        if (q.empty()) cout << "no elements";
        else
        {
            cout << "minimum: " << q.top() << ", maximum: " << max << ", average: " << double(average)/q.size();
        }
        cout << endl;
    }
}