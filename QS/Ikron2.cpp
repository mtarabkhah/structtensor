
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** Out, double ** B, int Nr, int Nc, int Mr, int Mc) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int v = 0; v < Mr; ++v) {

for (int w = 0; w < Mc; ++w) {


for (int r = 0; r < min({Nc, Nr}); ++r) {
int c = r;
int j = ((r * Mc) + w);
int i = ((r * Mr) + v);
Out[i][j] += (1 * B[v][w]);
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}