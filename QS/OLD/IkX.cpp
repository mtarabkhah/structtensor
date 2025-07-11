
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** B, double ** X, double ** A, double ** I, double ** Out, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
int i = 0;
if (i >= 0 && i < 2) {
int j = 1;
if (j >= 0 && j < 2) {
B[i][j] += X[i][j];
}
}
}
{
int i = 1;
if (i >= 0 && i < 2) {
int j = 0;
if (j >= 0 && j < 2) {
B[i][j] += X[i][j];
}
}
}
{
for (int i = 0; i < N; ++i) {

int j = i;
A[i][j] += I[i][i];
}
}
{
for (int r = 0; r < N; ++r) {

int v = 0;
if (v >= 0 && v < 2) {
int w = 1;
if (w >= 0 && w < 2) {
int i = ((r * 2) + v);
int j = ((r * 2) + w);
Out[i][j] += (I[r][r] * X[v][w]);
}
}
}
}
{
for (int r = 0; r < N; ++r) {

int v = 1;
if (v >= 0 && v < 2) {
int w = 0;
if (w >= 0 && w < 2) {
int i = ((r * 2) + v);
int j = ((r * 2) + w);
Out[i][j] += (I[r][r] * X[v][w]);
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}