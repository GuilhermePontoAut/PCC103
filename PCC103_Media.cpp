// PCC103 - METODOLOGIA
// Nome do exerc�cio: O Significado de "M�dia"


# include <iostream>
# include <vector>
# include <ctime>


using namespace std;

void VetorAleatorio (vector <double> &x, int tam);
void MostraVetor (vector <double> vetor);
double mean(const std::vector<double> &data);
double mode(const std::vector<double> &data);
double percentile(const std::vector<double> &data, int p);
double median(const std::vector<double> &data);
double QuickSort(vector<double> &data, int ini, int fim);
double Particao(vector<double> &data, int ini, int fim);

int main () {
    setlocale(LC_ALL, "Portuguese");                           // Recurso utilizado para conseguir imprimir acentua��o e caracteres especiais
    srand(time(NULL));                                         // Utiliza o rel�gio interno do computador para escolher uma semente para gerar os n�meros aleat�rios.

    vector <double> vetor;
    int n =10;                                                  // Tamanho do vector
    int p;

    VetorAleatorio(vetor, n);                                                       // Chama fun��o para gera vetor aleat�rio


    cout << "Vetor com n�meros escolhidos aleatoriamente: "<< endl;
    MostraVetor(vetor);
    cout << endl;

    cout << "Vetor ordenado utilizando QuickSort: "<< endl;
    QuickSort(vetor, 0, vetor.size()-1);
    MostraVetor(vetor);
    cout << endl;

    cout << "\nQual o percentil que voc� deseja saber? "<< endl;
    cin >> p;
    cout << endl;
    cout << endl;

    cout << "----------------------------------------------------";
    cout << "\nA m�dia dos valores �: ";                                            // Calcula a M�DIA dos valores do vetor
    cout << mean(vetor);
    cout << endl;

    mode(vetor);                                                                    // Calcula a MODA dos valores do vetor

    cout << "\nO percentil "<< p <<" do vetor �: " << percentile(vetor, p);;        // Calcula o PERCENTIL desejado
    cout << endl;

    cout << "\nA mediana dos valores �: " << median(vetor) << endl;                 // Calcula a MEDIANA dos valores do vetor
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

double mode(const std::vector<double> &data){
    int quantidade;
    int quantidade_anterior = 0;
    double num;
    vector <double> moda;

    for(int i=0; i<data.size(); i++){
        quantidade = 0;
        for(int j=i+1; j<data.size(); j++){
            if(data[i]==data[j]){
                quantidade++;
                num = data[i];
            }
        }
        if(quantidade == quantidade_anterior){
            quantidade_anterior=quantidade;
            moda.push_back(num);
        }
        else if(quantidade > quantidade_anterior){
            quantidade_anterior=quantidade;
            moda.clear();
            moda.push_back(num);
        }
    }
    if (quantidade_anterior == 0){
        cout<<"\nA moda desse vetor �: ";
        MostraVetor(data);
    }
    else{
        cout<<"\nA moda desse vetor �: ";
        MostraVetor(moda);
    }
}

double percentile(const std::vector<double> &data, int p){

    int aux;
    double position;
    double retorno;

    position = float(((p)*(data.size()-1))/100.0);
    aux = position;

    if (aux == position){
        retorno = data[position];
    }

    else {
        retorno = (data[aux] + data[aux + 1])/2;
    }
    return retorno;
}

double median(const std::vector<double>& data) {
    return percentile(data, 50);
}

void VetorAleatorio (vector <double> &x, int tam) {
    for (int i=0; i<tam; i++){
        x.push_back(rand() %50);
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

    int pivot = data[fim];    // pivot
    int i = ini-1;  // Index of smaller element

    for (int j = ini; j <= fim - 1; j++){
        if (data[j] <= pivot){              // If current element is smaller than or equal to pivot
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
