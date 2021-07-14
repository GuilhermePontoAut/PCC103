// PCC103 - METODOLOGIA
// Nome do exercício: Intervalos de Confiança - exercício 3


# include <iostream>
# include <vector>
# include <ctime>
# include <math.h>

using namespace std;

void VetorAleatorio (vector <double> &x, int tam);
void MostraVetor (vector <double> vetor);
double Particao (vector<double> &data, int ini, int fim);
double QuickSort(vector<double> &data, int ini, int fim);
double mean(const std::vector<double> &data);
double Busca (vector <double> vetor, int k);
double hipergeometrica( double a, double b, double c, double x);
double t_distribution_cdf(double x, int v);
double t_distribution_confidence_interval(const std::vector<double>& data, double alpha);

int main () {
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    srand(time(NULL));                                         // Utiliza o relógio interno do computador para escolher uma semente para gerar os números aleatórios.

    vector <double> vetor;
    int n =25;                                                 // Tamanho do vector
    int p;
    double Intervalo;
    double Media;

    VetorAleatorio(vetor, n);                                  // Chama função para gera vetor aleatório

    cout << "Digite o valor da probabilidade(%): ";
    cin >> p;
    cout << endl;

    cout << "Vetor com números escolhidos aleatoriamente: "<< endl;
    MostraVetor(vetor);
    cout << endl;

    cout << "Vetor ordenado utilizando QuickSort: "<< endl;
    QuickSort(vetor, 0, vetor.size()-1);
    MostraVetor(vetor);
    cout << endl;

    Media = mean(vetor);

    Intervalo = t_distribution_confidence_interval(vetor, p);

    if (Intervalo == -1) {
        cout << "Não existe intervalo de confiança em torno da média "<< Media << " para a probabilidade " << p << "%." << endl;
    }
    else {
        cout << "O intervalo de confiança em torno da média " << Media << " para a probabilidade " << p << "% é: " << "(" << (Media - Intervalo) << ", " << (Media + Intervalo) << ")" << endl;
    }

}

double t_distribution_confidence_interval(const std::vector<double>& data, double alpha){

    double Media = mean(data);
    int n = data.size();
    vector<double> VetorAux(n, 0);
    int Pos = Busca(VetorAux, alpha);

    for (int i = 0; i < n; i++) {
        VetorAux[i] = round(100 * t_distribution_cdf(data[i], n - 1));
    }

    if (Pos == -1) {
        return -1;
    }
    else {
        return data[Pos];
    }
}

void VetorAleatorio (vector <double> &x, int tam) {
    for (int i=0; i<tam; i++){
        x.push_back(rand() %30);
    }
}

void MostraVetor (vector <double> vetor) {
    cout << "{ ";
    for (int i=0; i<vetor.size(); i++){
        cout << vetor[i];
        if (i < vetor.size()-1){
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

double Particao (vector<double> &data, int ini, int fim){

    int pivot = data[fim];                                     // Define pivot como sendo o último elemento do vetor
    int i = ini-1;

    for (int j = ini; j <= fim - 1; j++){
        if (data[j] <= pivot){                                 // Compara cada elemento do vetor com o pivot
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[fim]);
    return (i + 1);
}

double QuickSort(vector<double> &data, int ini, int fim){
    if (ini < fim){
        int posicao = Particao(data, ini, fim);
        QuickSort(data, ini, posicao - 1);
        QuickSort(data, posicao + 1, fim);
    }
}

double mean(const std::vector<double> &data){
    double media = 0;
    for (int i =0; i<data.size(); i++){
        media = media + data[i];
    }
    return media/data.size();
}

double Busca (vector <double> vetor, int k){
    int x;
    int l = 0;                                                 // Left: Início da busca do vetor
    int r = vetor.size()-1;                                    // Right: Fim da busca do vetor

    while (r > l) {

        x = (l+r)/2;

        if (k==vetor[x]){
            return x;
        }
        else if (k>vetor[x]){
            l = x+1;
        }
        else if (k<vetor[x]) {
            r=x-1;
        }
        if (r<=l && l!= 25){
            return -1;
        }
    }
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
