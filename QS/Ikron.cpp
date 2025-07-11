
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** I, double ** I2, double ** A, double ** Out, double ** B, int Nr, int Nc, int Mr, int Mc) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < min({Nc, Nr}); ++i) {

int j = i;
I[i][j] += (1 * I2[i][i]);
}
}
{
for (int i = 0; i < min({Nc, Nr}); ++i) {

int j = i;
A[i][j] += (1 * I2[i][i]);
}
}
{
for (int r = 0; r < min({Nr, Nc}); ++r) {

for (int v = 0; v < Mr; ++v) {

for (int w = 0; w < Mc; ++w) {

int i = ((r * Mr) + v);
int j = ((r * Mc) + w);
Out[i][j] += (1 * I2[r][r] * B[v][w]);
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}