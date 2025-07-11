
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double ** eye, double ** M, double * Out, double * V, int N) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < N; ++i) {

int j = i;
eye[i][j] += 1;
}
}
{
for (int i = 0; i < N; ++i) {

int j = i;
M[i][j] += 1;
}
}
{
for (int i = 0; i < N; ++i) {

Out[i] += (1 * V[i]);
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;

}