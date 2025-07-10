
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double * Out, double ** M, double * V, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{

for (int j = 0; j < N; ++j) {

Out[i] += (M_C[i][j] * V[j]);
}
}
{

for (int j = 0; j < N; ++j) {



Out[i] += (M_RM[i][j][i4][i5] * M_C[i4][i5] * V[j]);
}
}
{
for (int i = 0; i < N; ++i) {

M[i][i] += 1;
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

}