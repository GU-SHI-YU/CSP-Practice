#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

bool onEdge[2005];
int points[2005][105];
double dist[2005][2005];
int bh[105];
int r;
int n, m;

double euDist(int (&a)[105], int (&b)[105])
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(ans);
}

double getDist(int i, int j)
{
    if (i == j)
        return 0;
    double AB, AO, BO;
    AB = euDist(points[i], points[j]);
    AO = euDist(points[i], bh);
    BO = euDist(points[j], bh);
    double cosA = (AO * AO + AB * AB - BO * BO) / (2 * AO * AB);
    double cosB = (BO * BO + AB * AB - AO * AO) / (2 * BO * AB);
    double h = sqrt(1 - cosA * cosA) * AO;
    if (cosA < 0 || cosB < 0 || fabs(cosA - 0) < 1e-7 || fabs(cosB - 0) < 1e-7 || h > r || fabs(h - r) < 1e-7)
        return AB;
    else
    {
        double AC = sqrt(AO * AO - r * r);
        double BD = sqrt(BO * BO - r * r);
        double alpha = acos((AO * AO + BO * BO - AB * AB) / (2 * AO * BO));
        double beta = alpha - asin(AC / AO) - asin(BD / BO);
        return AC + BD + beta * r;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> bh[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> points[i][j];
        }
        if (fabs(euDist(points[i], bh) - r) < 1e-7)
            onEdge[i] = true;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            dist[i][j] = dist[j][i] = getDist(i, j);
        }
    }
    for (int i = 0; i < m; i++)
    {
        double ans = 0;
        for (int j = 0; j < m; j++)
        {
            ans += dist[i][j];
        }
        printf("%.12lf\n", ans);
    }
    return 0;
}