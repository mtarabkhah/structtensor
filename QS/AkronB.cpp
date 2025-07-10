
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
const int M = atoi(argv[2]);
double **A = new double*[N];
for (size_t r = 0; r < N; ++r) {
A[r] = new double[N];

for (size_t c = 0; c < N; ++c) {
int flag1 = 0 <= r && N > r && 0 <= c && N > c;
if (flag1) {
A[r][c] = (double) (rand() % 1000000) / 1e6;
} else {
A[r][c] = 0.0;
}
}
}
double **B = new double*[M];
for (size_t v = 0; v < M; ++v) {
B[v] = new double[M];

for (size_t w = 0; w < M; ++w) {
int flag2 = 0 <= v && M > v && 0 <= w && M > w;
if (flag2) {
B[v][w] = (double) (rand() % 1000000) / 1e6;
} else {
B[v][w] = 0.0;
}
}
}
double **Out = new double*[(N * M)];
for (size_t i = 0; i < (N * M); ++i) {
Out[i] = new double[(N * M)];

for (size_t j = 0; j < (N * M); ++j) {
Out[i][j] = 0.0;
}
}

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
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << Out[0][0] << endl;
cerr << A[0][0] << endl;
cerr << B[0][0] << endl;

cerr << "A matrix:" << endl;
for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t j0 = 0; j0 < N; ++j0) {
cerr << A[i0][j0] << " ";
}
cerr << endl;
}
cerr << "B matrix:" << endl;
for (size_t i0 = 0; i0 < M; ++i0) {
for (size_t j0 = 0; j0 < M; ++j0) {
cerr << B[i0][j0] << " ";
}
cerr << endl;
}
cerr << "Out matrix:" << endl;
for (size_t i0 = 0; i0 < (N * M); ++i0) {
for (size_t j0 = 0; j0 < (N * M); ++j0) {
cerr << Out[i0][j0] << " ";
}
cerr << endl;
}
for (size_t i0 = 0; i0 < (N * M); ++i0) {delete[] Out[i0];
}delete[] Out;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < M; ++i0) {delete[] B[i0];
}delete[] B;
return 0;
}