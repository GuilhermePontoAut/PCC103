// PCC103 - METODOLOGIA
// Nome do exercício: Dispersão


# include <iostream>
# include <vector>
# include <ctime>
# include <math.h>

using namespace std;

void VetorAleatorio (vector <double> &x, int tam);
void MostraVetor (vector <double> vetor);
double mean(const std::vector<double> &data);
void interval(const std::vector<double>& data);
double variance(const std::vector<double>& data);
double std_dev(const std::vector<double>& data);

int main () {
    setlocale(LC_ALL, "Portuguese");                                                // Recurso utilizado para conseguir imprimir acentuação e caracteres especiais
    srand(time(NULL));                                                              // Utiliza o relógio interno do computador para escolher uma semente para gerar os números aleatórios.

    vector <double> vetor;
    int n =25;                                                                      // Tamanho do vector
    int p;

    VetorAleatorio(vetor, n);                                                       // Chama função para gera vetor aleatório


    cout << "Vetor com números escolhidos aleatoriamente: ";
    MostraVetor(vetor);
    cout << endl;

    cout << "----------------------------------------------------";
    cout << "\nO intervalo dos valores é: ";                                        // Calcula o INTERVALO dos valores do vetor
    interval(vetor);

    cout << "\nA variância dos valores é: " << variance(vetor) << endl;             // Calcula a VARIÂNCIA dos valores do vetor

    cout << "\nO desvio padrão dos valores é: " << std_dev(vetor) << endl;          // Calcula o DESVIO PADRÃO dos valores do vetor

    cout << "----------------------------------------------------";

    cout << endl;
    cout << endl;

}

double mean(const std::vector<double> &data){
    double media;
    for (int i =0; i<data.size(); i++){
        media = media + data[i];
    }
    return media/data.size();
}

void interval(const std::vector<double>& data){
    double min = data[0];
    double max = data[0];

    for (int i =0; i<data.size(); i++){
        if (data[i] < min){
            min = data[i];
        }
        else if (data[i] > max){
            max = data[i];
        }
    }
    cout << "{ " << min << ", " << max << " }" << endl;
}

double variance(const std::vector<double>& data){
    return (pow(std_dev(data),2));
}


double std_dev(const std::vector<double>& data){
    double mu = mean(data);
    double desvio = 0;

    for (int i=0; i<data.size(); i++){
    desvio = desvio + pow((data[i] - mu),2);
    }
    return (desvio/data.size());
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
