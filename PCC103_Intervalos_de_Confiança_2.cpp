// PCC103 - METODOLOGIA
// Nome do exercício: Intervalos de Confiança - exercício 2


# include <iostream>
# include <math.h>
//# include <gsl_inline.h>


using namespace std;

double hipergeometrica( double a, double b, double c, double x );
double t_distribution_pdf(double x, int v);
double t_distribution_cdf(double x, int v);
double t_distribution_cdf(double x1, double x2, int v);


int main () {
    setlocale(LC_ALL, "Portuguese");

    double x1, x2, v;

    cout << "\nDigite o valor do primeiro ponto: ";
    cin >> x1;
    cout << "\nDigite o valor do segundo ponto: ";
    cin >> x2;
    cout << "\nDigite o valor dos graus de liberdade: ";
    cin >> v;

    cout << "\n------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "A probabilidade do ponto " << x1 <<" ser p em uma distribuição-t com "<< v <<" graus de liberdade é de: " << t_distribution_pdf(x1, v) << "%" << endl;
    cout << "A probabilidade do ponto " << x2 <<" ser p em uma distribuição-t com "<< v <<" graus de liberdade é de: " << t_distribution_pdf(x2, v) << "%" << endl;
    cout << "A probabilidade de um ponto estar entre dois pontos "<< x1 <<" e "<< x2 << " em uma distribuição-t com " << v << " graus de liberdade é de: "<< t_distribution_cdf(x1, x2, v);
    cout << "\n------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
}

double t_distribution_pdf(double x, int v){

    double aux1, aux2, aux3, aux4, aux5, aux6;

    aux1 = -(v+1)/2;
    aux2 = 1 + (pow(x,2)/v);
    aux3 = pow(aux2, aux1);
    aux4 = tgamma((v+1)/2);
    aux5 = (sqrt(v*M_PI))*(tgamma(v/2));
    aux6 = (aux4/aux5)*aux3;

    return aux6*100;
}

double t_distribution_cdf(double x, int v){
    double aux1, aux2, aux3, aux4, aux5, aux6;

    aux1 = hipergeometrica(1/2, (v+1)/2, 3/2, -(pow(x,2)/v));
    aux2 = (sqrt(v*M_PI))*(tgamma(v/2));
    aux3 = aux1/aux2;
    aux4 = x*tgamma((v+1)/2);
    aux5 = aux3*aux4;
    aux6 = 1/2 + aux5;

    return aux6;
}

double t_distribution_cdf(double x1, double x2, int v){
    double aux1, aux2;

    aux1 = t_distribution_cdf(x1, v);
    aux2 = t_distribution_cdf(x2, v);

    return(abs(aux1 - aux2));
}

double hipergeometrica( double a, double b, double c, double x ){
   const double TOLERANCE = 1.0e-10;
   double term = a * b * x / c;
   double value = 1.0 + term;
   int n = 1;

   while ( abs( term ) > TOLERANCE ){
      a++, b++, c++, n++;
      term *= a * b * x / c / n;
      value += term;
   }
   return value;
}
