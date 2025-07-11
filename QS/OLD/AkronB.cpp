
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** Out, double ** A, double ** B, int N, int M) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int r = 0; r < N; ++r) {

for (int c = 0; c < N; ++c) {

for (int v = 0; v < M; ++v) {

for (int w = 0; w < M; ++w) {

int i = ((r * M) + v);
int j = ((c * M) + w);
Out[i][j] += (A[r][c] * B[v][w]);
}
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}