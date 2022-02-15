#include "benchmark.h"

#include <time.h>

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define BENCHMARK_NAME                                                         \
  "BOBOBENCH" // Geben Sie hier Ihrem Benchmark einen Namen.
#define ITERATIONS                                                             \
  100000000 // Anzahl an Iterationen durch den Benchmark (höherer Wert führt zu
            // besserer Genauigkeit aber auch längerer Wartezeit)



// *** Programmieren Sie Ihren eigenen Benchmark ***
double executeBenchmark(long interations) {

  double result = 1.0;

  for (long i; i < interations; i++) {

    // TODO: 
    // Fügen Sie hier irgendwelche Berechnungen ein, die den Wert der
    // Variablen "result" ändern (ein oder mehrere - je nachdem wie aufwändig
    // Sie Ihren Benchmark gestalten wollen...)
    // Testen Sie, wie sich unterschiedliche Berechnungsarten auf den Benchmark
    // auswirken.


    result = result / 1.01; // <-- ergänzen / ersetzen
  }

  return result;
}

// *** ENDE der von Ihnen zu bearbeitenden Methode ***



int main() {
  cout << endl << "*** Running benchmark: " << BENCHMARK_NAME << " ***" << endl << endl;

  double startTime = clock();

  double result = executeBenchmark(ITERATIONS);

  double stopTime = clock();
  double duration = (stopTime - startTime) / CLOCKS_PER_SEC;

  // format the output to 3 digits precision
  std::stringstream output;
  output.setf(ios::fixed);
  output.precision(4);
  output << duration;

  cout << "Benchmark took " << output.str()
       << " seconds. Returned result: " << result << endl;

  output.str(string());
  output << ITERATIONS / duration;
  cout << "Measured: " << output.str() << " " << BENCHMARK_NAME
       << " iterations per second." << endl;

  return 0;
}