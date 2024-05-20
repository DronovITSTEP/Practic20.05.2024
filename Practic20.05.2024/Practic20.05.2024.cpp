#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <stack>
#include <queue>

using namespace std;

int main()
{
    srand(time(0));
    /*Stack st;
    char c;
    while (!st.IsFull()) {
        c = rand() % 4 + 2;
        st.Push(c);
    }
    while (c = st.Pop())
        cout << c << " ";*/

    Queue q(25);
    for (int i = 0; i < 5; i++) {
        q.Add(rand() % 50);
    }
    q.Show();
    q.Extract();
    q.Show();

}
