
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** Out, double ** B, double ** C, int Nr, int Nc, int Mr, int Mc, int Pr, int Pc) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int v = 0; v < Mr; ++v) {

for (int w = 0; w < Mc; ++w) {

for (int k = 0; k < Pr; ++k) {

for (int l = 0; l < Pc; ++l) {

for (int c = 0; c < Nc; ++c) {

for (int r = 0; r < Nr; ++r) {

int j = ((((c * Mc) + w) * Pc) + l);
int i = ((((r * Mr) + v) * Pr) + k);
Out[i][j] += (1 * B[v][w] * C[k][l]);
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