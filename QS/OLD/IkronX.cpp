
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double **X = new double*[2];
for (size_t v = 0; v < 2; ++v) {
X[v] = new double[2];

for (size_t w = 0; w < 2; ++w) {
int flag1 = 0 <= v && 2 > v && 0 <= w && 2 > w;
if (flag1) {
X[v][w] = (double) (rand() % 1000000) / 1e6;
} else {
X[v][w] = 0.0;
}
}
}
double **I = new double*[N];
for (size_t i = 0; i < N; ++i) {
I[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
I[i][j] = 0.0;
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
for (int i = 0; i < N; ++i) {

int j = i;
I[i][j] += 1;
}
}
{


for (int v = 0; v < 2; ++v) {

for (int w = 0; w < 2; ++w) {

Out[i][j] += (1 * X[v][w]);
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
cerr << I[0][0] << endl;
cerr << 1 << endl;
cerr << Out[0][0] << endl;
cerr << X[0][0] << endl;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] I[i0];
}delete[] I;
for (size_t i0 = 0; i0 < (N * 2); ++i0) {delete[] Out[i0];
}delete[] Out;
for (size_t i0 = 0; i0 < 2; ++i0) {delete[] X[i0];
}delete[] X;
return 0;
}