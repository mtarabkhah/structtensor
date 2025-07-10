
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);
double *V = new double[N];
for (size_t j = 0; j < N; ++j) {
int flag1 = 0 <= j && N > j;
if (flag1) {
V[j] = (double) (rand() % 1000000) / 1e6;
} else {
V[j] = 0.0;
}
}
double *Out = new double[N];
for (size_t i = 0; i < N; ++i) {
Out[i] = 0.0;
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < N; ++i) {

Out[i] += (1 * V[i]);
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
cerr << Out[0] << endl;
delete[] Out;
delete[] V;
return 0;
}