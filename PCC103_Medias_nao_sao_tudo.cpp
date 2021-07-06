// PCC103 - METODOLOGIA
// Nome do exerc�cio: M�dias n�o s�o tudo


# include <iostream>
# include <vector>
# include <math.h>


using namespace std;


double normal_distribution_pdf(double x, double mu, double std_dev);
double normal_distribution_pdf(double x);



int main () {
    setlocale(LC_ALL, "Portuguese");

    double mu, std_dev, x;

    cout << "Digite o valor da m�dia: ";
    cin >> mu;
    cout << "\nDigite o valor do desvio padr�o: ";
    cin >> std_dev;
    cout << "\nDigite o valor do ponto para calcularmos a probabilidade dele ocorrer em uma distribui��o normal: ";
    cin >> x;

    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout<< "\n1) A probabilidade deste ponto ocorrer em uma distribui��o normal, com m�dia = "<< mu <<" e desvio padr�o = "<< std_dev << ", �: " << normal_distribution_pdf(x, mu, std_dev) << " %" << endl;
    cout<< "2) J� a probabilidade deste ponto ocorrer em uma distribui��o normal, com m�dia = 0 e desvio padr�o = 1, �: " << normal_distribution_pdf(x) << " %"<< endl;
    cout << "\n------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
}

double normal_distribution_pdf(double x, double mu, double std_dev){

    double aux1, aux2, aux3, aux4, aux5;

    aux1 = pow((x - mu),2);
    aux2 = pow(std_dev,2);
    aux3 = aux1/(2*aux2);
    aux4 = exp(-aux3);
    aux5 = 1/(sqrt(2*M_PI*pow(std_dev,2)));

    return (aux4*aux5*100);
}

double normal_distribution_pdf(double x){
    return (normal_distribution_pdf(x, 0, 1));
}
