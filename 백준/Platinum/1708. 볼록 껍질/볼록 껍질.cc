#include <iostream>

#include <vector>

#include <algorithm>

#include <stack>

#include <cmath>

using namespace std;

 

const double PI = 2.0 * acos(0.0);

 

struct vec

{

        double x, y;

        double p, q; //상대적 좌표

 

        vec(double a = 0.0, double b = 0.0) :x(a), y(b), p(0), q(0)

        {

        }

 

        //반시계 방향으로 정렬

        bool operator<(const vec &v)

        {

                 if (1LL * q * v.p != 1LL * p * v.q)

                         return 1LL * q * v.p < 1LL * p * v.q;

 

                 if (y != v.y)

                         return y < v.y;

                 return x < v.x;

        }

 

        //외적

        double cross(const vec &v) const

        {

                 return x * v.y - y * v.x;

        }

};

 

double ccw(vec a, vec b)

{

        return a.cross(b);

}

 

//점 p를 기준으로 벡터 b가 a의 반시계 방향이면 양수, 시계 방향이면 음수

//평행이면 0을 반환

double ccw(vec p, vec a, vec b)

{

        return ccw(vec(a.x - p.x, a.y - p.y), vec(b.x - p.x, b.y - p.y));

}

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        int N;

        cin >> N;

 

        vector<vec> p(N);

        for (int i = 0; i < N; i++)

                 cin >> p[i].x >> p[i].y;

 

        sort(p.begin(), p.end());

        vec pivot = p[0]; //기준

        for (int i = 1; i < N; i++)

        {

                 p[i].p = p[i].x - pivot.x;

                 p[i].q = p[i].y - pivot.y;

        }

        sort(p.begin() + 1, p.end());

 

        vector<vec> hull;

        hull.push_back(pivot);

        hull.push_back(p[1]);

 

        int next = 2;

        while (next < p.size())

        {

                 while (hull.size() >= 2)

                 {

                         vec first, second;

                         second = hull.back();

                         hull.pop_back();

                         first = hull.back();

                         //반시계 방향일 경우에만

                         if (ccw(first, second, p[next]) > 0)

                         {

                                 hull.push_back(second);

                                 break;

                         }

                 }

                 hull.push_back(p[next++]);

        }

       

        cout << hull.size() << "\n";

        return 0;

}

