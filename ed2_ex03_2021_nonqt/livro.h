#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
using std::string;

class Livro
{
private:
    string titulo;
    string autor;
    int ano_de_edicao;
    int numero_de_paginas;
    double preco;
public:
    Livro();
    ~Livro();
    //sets
    void setTitulo(string dadoTitulo);
    void setAutor(string dadoAutor);
    void setAnoDeEdicao(int dadoAnoDeEdicao);
    void setNumeroDePaginas(int dadoNumeroDePaginas);
    void setPreco(double dadoPreco);
    //gets
    string getTitulo()const {return titulo;}
    string getAutor()const {return autor;}
    int getAnoDeEdicao()const {return ano_de_edicao;}
    int getNumeroDePaginas()const {return numero_de_paginas;}
    double getPreco()const {return preco;}
};

#endif // LIVRO_H
