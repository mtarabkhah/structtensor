
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** AB, double ** A, double ** B, double ** Out, double ** C, int Nr, int Nc, int Mr, int Mc, int Pr, int Pc) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int r = 0; r < Nr; ++r) {

for (int c = 0; c < Nc; ++c) {

for (int v = 0; v < Mr; ++v) {

for (int w = 0; w < Mc; ++w) {

int i = ((r * Mr) + v);
int j = ((c * Mc) + w);
AB[i][j] += (A[r][c] * B[v][w]);
}
}
}
}
}
{


for (int i71 = 0; i71 < Nr; ++i71) {

for (int i72 = 0; i72 < Nc; ++i72) {

for (int i73 = 0; i73 < Mr; ++i73) {

for (int i74 = 0; i74 < Mc; ++i74) {

for (int v = 0; v < Pr; ++v) {

for (int w = 0; w < Pc; ++w) {

Out[i][j] += (A[i71][i72] * B[i73][i74] * C[v][w]);
}
}
}
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}