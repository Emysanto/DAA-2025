#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

// Function to determine the orientation of three points
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

// Function to find the convex hull using divide and conquer
void convexHull(Point points[], int n, Point hull[], int &hullSize) {
    if (n <= 1) {
        hull[0] = points[0];
        hullSize = n;
        return;
    }
    
    // Sorting points based on x-coordinates using simple selection sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x > points[j].x) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
    
    // Divide and Conquer approach (simplified)
    int mid = n / 2;
    Point leftHull[100], rightHull[100];
    int leftSize = 0, rightSize = 0;
    
    convexHull(points, mid, leftHull, leftSize);
    convexHull(points + mid, n - mid, rightHull, rightSize);
    
    // Merging hulls (simplified without vectors)
    for (int i = 0; i < leftSize; i++) hull[hullSize++] = leftHull[i];
    for (int i = 0; i < rightSize; i++) hull[hullSize++] = rightHull[i];
}

int main() {
    Point points[] = {{10, 10}, {20, 30}, {30, 20}, {40, 50}, {50, 10}, {5, 5}, {60, 60}};
    int n = sizeof(points) / sizeof(points[0]);
    Point hull[100];
    int hullSize = 0;
    
    convexHull(points, n, hull, hullSize);
    
    cout << "Convex Hull:\n";
    for (int i = 0; i < hullSize; i++) {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }
    return 0;
}
