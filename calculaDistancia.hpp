#include <math.h>

double calculaDistancia(double lat1, double lon1, double lat2, double lon2){
    double raio = 6372.795477598;
    double distancia = 0;
    double a = sin(lat1) * sin(lat2);
    double b = cos(lat1) * cos(lat2);
    double g = cos(lon1 - lon2);
    distancia = raio * acos(a + b * g);
    //cout << " A distancia eh: " << distancia << " KM" << endl;
    return distancia;
}
