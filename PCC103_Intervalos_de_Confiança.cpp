// PCC103 - METODOLOGIA
// Nome do exercício: Intervalos de Confiança


# include <iostream>
# include <math.h>



using namespace std;

double normal_distribution_cdf(double x, double mu, double std_dev);
double normal_distribution_cdf(double x);
double normal_distribution_cdf(double x1, double x2, double mu, double std_dev);
double normal_distribution_cdf(double x1, double x2);


int main (){

    setlocale(LC_ALL, "Portuguese");

    double x1, x2, mu, std_dev;

    cout << "Digite o valor da média: ";
    cin >> mu;
    cout << "\nDigite o valor do desvio padrão: ";
    cin >> std_dev;
    cout << "\nDigite o valor do primeiro ponto: ";
    cin >> x1;
    cout << "\nDigite o valor do segundo ponto: ";
    cin >> x2;

    cout << "\n------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "A probabilidade do ponto P estar entre dois pontos, " << x1 << " e " << x2 <<", em uma distribuição normal é de: " << normal_distribution_cdf(x1, x2, mu, std_dev) << "%.";
    cout << "\nA probabilidade do ponto P estar entre dois pontos, " << x1 << " e " << x2 <<", em uma distribuição normal, com média = 0 e desvio padrão = 1, é de: " << normal_distribution_cdf(x1, x2) << "%.";
    cout << "\n------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
}

double normal_distribution_cdf(double x, double mu, double std_dev){

    double aux1, aux2, aux3, aux4;

    aux1 = (x - mu);
    aux2 = std_dev*sqrt(2);
    aux3 = 1 + erf(aux1/aux2);
    aux4 = aux3/2;

    return aux4;
}

double normal_distribution_cdf(double x){
    return (normal_distribution_cdf(x, 0, 1));
}

double normal_distribution_cdf(double x1, double x2, double mu, double std_dev){
    double y1, y2;

    y1 = normal_distribution_cdf(x1, mu, std_dev);
    y2 = normal_distribution_cdf(x2, mu, std_dev);
    return abs((y2 - y1)*100);
}

double normal_distribution_cdf(double x1, double x2){
     double y1, y2;

    y1 = normal_distribution_cdf(x1);
    y2 = normal_distribution_cdf(x2);
    return abs((y2 - y1)*100);
}
