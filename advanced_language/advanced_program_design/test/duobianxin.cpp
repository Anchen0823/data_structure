#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
    int x, y;
};

int crossProduct(const Point& o, const Point& A, const Point& B) {
    return abs((A.x - o.x) * (B.y - o.y) - (A.y - o.y) * (B.x - o.x));
}

double Area(const vector<Point>& points) {
    int n = points.size();
    double area = 0.0;
    for (int i=0;i<n;i+=1) {
        area += 0.5 * crossProduct(points[0], points[(i+1)%n], points[(i+2)%n]);
    }
    return abs(area);
}
int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i=0;i<N;i++) {
        cin >> points[i].x >> points[i].y;
    }
    double area = Area(points);
    cout << fixed << setprecision(2) << area << endl;

    return 0;
}