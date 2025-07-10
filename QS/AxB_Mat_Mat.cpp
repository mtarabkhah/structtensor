
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
for (size_t i = 0; i < N; ++i) {
A[i] = new double[N];

for (size_t k = 0; k < N; ++k) {
int flag1 = 0 <= i && N > i && 0 <= k && N > k;
if (flag1) {
A[i][k] = (double) (rand() % 1000000) / 1e6;
} else {
A[i][k] = 0.0;
}
}
}
double **B = new double*[N];
for (size_t k = 0; k < N; ++k) {
B[k] = new double[N];

for (size_t j = 0; j < N; ++j) {
int flag2 = 0 <= k && N > k && 0 <= j && N > j;
if (flag2) {
B[k][j] = (double) (rand() % 1000000) / 1e6;
} else {
B[k][j] = 0.0;
}
}
}
double **Out = new double*[N];
for (size_t i = 0; i < N; ++i) {
Out[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
Out[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < N; ++i) {

for (int j = 0; j < N; ++j) {

for (int k = 0; k < N; ++k) {

Out[i][j] += (A[i][k] * B[k][j]);
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
for (size_t i0 = 0; i0 < N; ++i0) {delete[] Out[i0];
}delete[] Out;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] A[i0];
}delete[] A;
for (size_t i0 = 0; i0 < N; ++i0) {delete[] B[i0];
}delete[] B;
return 0;
}