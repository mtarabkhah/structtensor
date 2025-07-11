
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** B, double ** X, double ** Out, double ** A, int Nr, int Nc, int Mr, int Mc) {


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

Mr += 2;

}
{
for (int r = 0; r < Nr; ++r) {

for (int c = 0; c < Nc; ++c) {

int v = 0;
if (v >= 0 && v < min({Mr, 2})) {
int w = 1;
if (w >= 0 && w < min({Mc, 2})) {
int i = ((r * Mr) + v);
int j = ((c * Mc) + w);
Out[i][j] += (A[r][c] * X[v][w]);
}
}
}
}
}
{
for (int r = 0; r < Nr; ++r) {

for (int c = 0; c < Nc; ++c) {

int v = 1;
if (v >= 0 && v < min({Mr, 2})) {
int w = 0;
if (w >= 0 && w < min({Mc, 2})) {
int i = ((r * Mr) + v);
int j = ((c * Mc) + w);
Out[i][j] += (A[r][c] * X[v][w]);
}
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}