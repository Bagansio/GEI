#include <iostream>
#include <queue>
using namespace std;

//PRE: A PRIORITY QUEUE <int> and a char of a command
//POST: ANALIZE THE COMMAND AND DOES THE CORRECT THING
void analize(priority_queue<int>& q, char command)
{
    int x;
        if (command == 'S') // STORE
        {
            cin >> x;
            q.push(x);
        }

        else if (q.empty()) // THIS IS FOR EXCEPTIONS
        {
            if (command == 'I' or command == 'D') cin >> x;
            cout << "error!" << endl;
        }
        else if (command == 'A') // ASKS THE GREATER
        {
            cout << q.top() << endl;
        }
        else if (command == 'R') // REMOVE THE GREATER
        {
            q.pop();
        }
        else                     // INCREMENT OR DECREASE A x VALUE OF THE GREATER
        {
            cin >> x;
            if (command == 'D') x = -x;
            x += q.top();
            q.pop();
            q.push(x);
        }
}

int main()
{
    char command;
    priority_queue<int> q;

    while (cin >> command)
    {
        analize(q,command);
    }
}