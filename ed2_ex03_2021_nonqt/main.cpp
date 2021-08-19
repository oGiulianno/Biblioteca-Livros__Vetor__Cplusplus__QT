#include <iostream>
#include "livro.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

//************************************************************
//************************************************************
//************************************************************

//mostrar
void mostraDados(Livro *livros, int qtd){
    for (int i=0;i<qtd;i++) {
        cout<<endl<<"Dados do Livro "<<(i+1)<<"o. Livro: "<<endl;
        cout<<livros[i].getTitulo()<<
        ", "<<livros[i].getAutor()<<
        ", "<<livros[i].getAnoDeEdicao()<<
        ", "<<livros[i].getNumeroDePaginas()<<
        " e "<< livros[i].getPreco()<<endl;
    }
}

//************************************************************

//preço medio dos livros
double precoMedioDosLivros(Livro *livros, int qtd){
    double soma = 0;
    for (int i=0;i<qtd;i++) {
       soma += livros[i].getPreco();
    }
    return soma/qtd;
}

//************************************************************

//titulo do livro mais caro
string tituloDoLivroMaisCaro(Livro *livros, int qtd){
    int posMaior = 0;
    for (int i=1;i<qtd;i++) {
        if(livros[i].getPreco() > livros[posMaior].getPreco()){
            posMaior = i;
        }
    }
    return livros[posMaior].getTitulo();
}

//************************************************************

//titulo do livro com menor número de páginas
string tituloDoLivroComMenorPaginas(Livro *livros, int qtd){
    int posMenor = 0;
    for (int i=1;i<qtd;i++) {
        if(livros[i].getNumeroDePaginas() < livros[posMenor].getNumeroDePaginas()){
            posMenor = i;
        }
    }
    return livros[posMenor].getTitulo();
}

//************************************************************

//ano do livro com maior número de páginas
int anoDoLivroComMaiorPaginas(Livro *livros, int qtd){
    int posMaior = 0;
    for (int i=1;i<qtd;i++) {
        if(livros[i].getNumeroDePaginas() > livros[posMaior].getNumeroDePaginas()){
            posMaior = i;
        }
    }
    return livros[posMaior].getAnoDeEdicao();
}

//************************************************************

//nome do autor do livro mais antigo
string nomeDoAutorLivroMaisAntigo(Livro *livros, int qtd){
    int posMenor = 0;
    for (int i=1;i<qtd;i++) {
        if(livros[i].getAnoDeEdicao() < livros[posMenor].getAnoDeEdicao()){
            posMenor = i;
        }
    }
    return livros[posMenor].getAutor();
}

//************************************************************
//************************************************************
//************************************************************
//MAIN
int main()
{
    const int TAM=5;
    //
    Livro livros[TAM];
    //
    string titulo;
    string autor;
    int ano_de_edicao;
    int numero_de_paginas;
    double preco;

    for (int i=0;i<TAM;i++) {
        cout<<"Digite o Titulo do Livro: ";
        cin>>titulo;
        livros[i].setTitulo(titulo);

        cout<<"Digite o Autor do Livro: ";
        cin>>autor;
        livros[i].setAutor(autor);

        while(true){
            cout<<"Digite o Ano de Edicao do Livro: ";
            cin>>ano_de_edicao;
            try{
                livros[i].setAnoDeEdicao(ano_de_edicao);
                break;
            }catch(string erro){cout<<erro<<endl;}
        }

        while(true){
            cout<<"Digite o Numero da quantidade de Paginas do Livro: ";
            cin>>numero_de_paginas;
            try{
            livros[i].setNumeroDePaginas(numero_de_paginas);
                break;
            }catch(string erro){cout<<erro<<endl;}
        }

        while(true){
            cout<<"Digite o preco do Livro: R$ ";
            cin>>preco;
            try{
                livros[i].setPreco(preco);
                break;
            }catch(string erro){cout<<erro<<endl;}
        }

        cout<<endl;

    }
    mostraDados(livros,TAM);
    cout<<endl<<"Preco medio dos livros: R$ "<<precoMedioDosLivros(livros,TAM)<<endl;
    cout<<"Titulo do livro mais caro: "<<tituloDoLivroMaisCaro(livros,TAM)<<endl;
    cout<<"Titulo do livro com menor quantidade de paginas: "<<tituloDoLivroComMenorPaginas(livros,TAM)<<endl;
    cout<<"Ano de publicacao do livro com maior quantidade de paginas: "<<anoDoLivroComMaiorPaginas(livros,TAM)<<endl;
    cout<<"Nome do autor do livro mais antigo: "<< nomeDoAutorLivroMaisAntigo(livros,TAM)<<endl<<endl;
}

