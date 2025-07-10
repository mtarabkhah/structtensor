
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv){
    srand(0);




double **X = new double*[2];
for (size_t i = 0; i < 2; ++i) {
X[i] = new double[2];

for (size_t j = 0; j < 2; ++j) {
X[i][j] = 0.0;
}
}

long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
int i = 0;
int j = 1;
X[i][j] += 1;

}
{
int i = 1;
int j = 0;
X[i][j] += 1;

}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;
cerr << X[0][0] << endl;
cerr << 1 << endl;
for (size_t i0 = 0; i0 < 2; ++i0) {delete[] X[i0];
}delete[] X;
return 0;
}