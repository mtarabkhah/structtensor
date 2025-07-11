
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);


const int N = atoi(argv[1]);

double **eye = new double*[N];
for (size_t i = 0; i < N; ++i) {
eye[i] = new double[N];

for (size_t j = 0; j < N; ++j) {
eye[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < N; ++i) {

int j = i;
eye[i][j] += 1;
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
cerr << eye[0][0] << endl;
cerr << 1 << endl;

for (size_t i0 = 0; i0 < N; ++i0) {
for (size_t j0 = 0; j0 < N; ++j0) {
cerr << eye[i0][j0] << " ";
}
cerr << endl;
}
for (size_t i0 = 0; i0 < N; ++i0) {delete[] eye[i0];
}delete[] eye;
return 0;
}