// PCC103 - METODOLOGIA
// Nome do exercício: Teste T de Student


# include <iostream>
# include <vector>
# include <ctime>
# include <math.h>


using namespace std;

void MontarVetor(vector <double> &vetor, int tam);
void MostraVetor(vector <double> vetor);
double mean(const std::vector<double> &data);
double std_dev(const std::vector<double>& data);
double EstatisticaT (vector <double> vetorA, vector <double> vetorB, double n);

int main (){

    setlocale (LC_ALL, "Portuguese");
    srand(time(NULL));

    vector <double> vetorA = {1,2,3,4,5,6,7,8,9,10};
    vector <double> vetorB = {11,12,13,14,15,16,17,18,19,20};

    int tam = 10;


    //MontarVetor(vetorA, tam);
    //MontarVetor(vetorB, tam);
    MostraVetor(vetorA);
    MostraVetor(vetorB);

    cout<< "\nA média do vetor A é igual a: " << mean(vetorA) << endl;
    cout<< "A média do vetor B é igual a: " << mean(vetorB) << endl;

    cout<< "\nO desvio padrão do vetor A é igual a: " << std_dev(vetorA) << endl;
    cout<< "O desvio padrão do vetor B é igual a: " << std_dev(vetorB) << endl;

    double n = (vetorA.size() + vetorB.size() - 2);
    cout<< "\nO grau de liberdade é igual a: " << n << endl;

    cout<< "\nA estatística T é igual a: " << EstatisticaT(vetorA, vetorB, n) << endl;


}

double EstatisticaT (vector <double> vetorA, vector <double> vetorB, double n){
    double aux1, aux2, aux3;
    double mediaA, mediaB, VarA, VarB;

    mediaA = mean(vetorA);
    mediaB = mean(vetorB);
    VarA = pow(std_dev(vetorA),2);
    VarB = pow(std_dev(vetorB),2);

    aux1 = abs(mediaA - mediaB);
    aux2 = sqrt((VarA + VarB)/n);
    aux3 = aux1/aux2;

    return aux3;
}



double mean(const std::vector<double> &data){
    double media;
    for (int i =0; i<data.size(); i++){
        media = media + data[i];
    }
    return media/data.size();
}

double std_dev(const vector<double> &data){
    double mu = mean(data);
    double desvio = 0;


    for (int i=0; i<data.size(); i++){
    desvio = desvio + pow((data[i] - mu),2);
    }
    desvio = desvio/data.size()-1;

    return sqrt(desvio);
}

void MontarVetor(vector <double> &vetor, int tam){
    for(int i=0; i<tam; i++){
        vetor.push_back(rand() %50);
    }
}

void MostraVetor(vector <double> vetor){
    cout <<"{ ";
    for (int i=0; i<vetor.size(); i++){
        cout<< vetor[i];
        if (i<vetor.size()-1){
            cout<< ",";
        }
    }
    cout<< " }" << endl;
}
