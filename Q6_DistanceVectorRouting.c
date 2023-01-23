#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int dm[20][20], no;

    cout << "Enter no of nodes." << endl;
    cin >> no;
    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < no; i++) {
        for (int j = 0; j < no; j++) {
            cin >> dm[i][j];
            /*  Set distance from i to i as 0 */
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do {
        flag = 0;
        for (int i = 0; i < no; i++) {
            for (int j = 0; j < no; j++) {
                for (int k = 0; k < no; k++) {
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j])) {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++) {
        cout << "Router info for router: " << i + 1 << endl;
        cout << "Dest\tNext Hop\tDist" << endl;
        for (int j = 0; j < no; j++)
            printf("%d\t%d\t\t%d\n", j+1, route[i].from[j]+1, route[i].dist[j]);
    }
    return 0;
}
/*Output :

Enter no of nodes.
3
Enter the distance matrix:
0 2 7
2 0 1
7 1 0
Router info for router: 1
Dest	Next Hop	Dist
1	1		0
2	2		2
3	2		3
Router info for router: 2
Dest	Next Hop	Dist
1	1		2
2	2		0
3	3		1
Router info for router: 3
Dest	Next Hop	Dist
1	2		3
2	2		1
3	3		0 */
