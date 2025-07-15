
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** X, double ** B, double ** Out, double ** A, int Nr, int Nc, int Mr, int Mc) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
int i = 0;
int j = 1;
X[i][j] += 1;

}
{
int i = 1;
int j = 0;
X[i][j] += 1;

}
{
int i = 0;
int j = 1;
B[i][j] += 1;

}
{
int i = 1;
int j = 0;
B[i][j] += 1;

}
{

Mr += 2;

}
{
for (int r = 0; r < Nr; ++r) {

for (int c = 0; c < Nc; ++c) {

int w = 1;
if (w >= 0 && w < Mc) {
int j = ((c * Mc) + w);
int v = 0;
if (v >= 0 && v < Mr) {
int i = ((r * Mr) + v);
Out[i][j] += (A[r][c] * 1);
}
}
}
}
}
{
for (int r = 0; r < Nr; ++r) {

for (int c = 0; c < Nc; ++c) {

int w = 0;
if (w >= 0 && w < Mc) {
int j = ((c * Mc) + w);
int v = 1;
if (v >= 0 && v < Mr) {
int i = ((r * Mr) + v);
Out[i][j] += (A[r][c] * 1);
}
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}