
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double **A = new double*[N];
for (size_t r = 0; r < N; ++r) {
A[r] = new double[N];

for (size_t c = 0; c < N; ++c) {
int flag1 = 0 <= r && N > r && 0 <= c && N > c && 0 <= r && r < N && r == c;
if (flag1) {
A[r][c] = (double) (rand() % 1000000) / 1e6;
} else {
A[r][c] = 0.0;
}
}
}
double **B = new double*[2];
for (size_t v = 0; v < 2; ++v) {
B[v] = new double[2];

for (size_t w = 0; w < 2; ++w) {
int flag2 = 0 <= v && 2 > v && 0 <= w && 2 > w && 0 == v && 1 == w || 0 <= v && 2 > v && 0 <= w && 2 > w && 1 == v && 0 == w;
if (flag2) {
B[v][w] = (double) (rand() % 1000000) / 1e6;
} else {
B[v][w] = 0.0;
}
}
}
double **Out = new double*[(N * 2)];
for (size_t i = 0; i < (N * 2); ++i) {
Out[i] = new double[(N * 2)];

for (size_t j = 0; j < (N * 2); ++j) {
Out[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int r = 0; r < N; ++r) {

int v = 0;
if (v >= 0 && v < 2) {
int w = 1;
if (w >= 0 && w < 2) {
int i = ((r * 2) + v);
int j = ((r * 2) + w);
Out[i][j] += (A[r][r] * B[v][w]);
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
Out[i][j] += (A[r][r] * B[v][w]);
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << Out[0][0] << endl;
for (size_t i0 = 0; i0 < (N * 2); ++i0) {delete[] Out[i0];
}delete[] Out;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < 2; ++i0) {delete[] B[i0];
}delete[] B;
return 0;
}