#include "livro.h"
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::localtime;

Livro::Livro():
    titulo(""),
    autor(""),
    ano_de_edicao(0),
    numero_de_paginas(0),
    preco(0)
{
}

Livro::~Livro(){
}

void Livro::setTitulo(string dadoTitulo){
    titulo = dadoTitulo;
}

void Livro::setAutor(string dadoAutor){
    autor = dadoAutor;
}

void Livro::setAnoDeEdicao(int dadoAnoDeEdicao){
    time_t t = time(nullptr);
    tm *const pTInfo = localtime(&t);
    //1900 + pTInfo->tm_year; //verifica qual o ano atual
    if(dadoAnoDeEdicao < 0 || dadoAnoDeEdicao > (1900+pTInfo->tm_year) )
    { throw string("O ano nao pode ser Menor ou igual a 0 ou Maior do que o ano atual"); }
    else
        ano_de_edicao = dadoAnoDeEdicao;
}

void Livro::setNumeroDePaginas(int dadoNumeroDePaginas){
   if(dadoNumeroDePaginas > 0) { numero_de_paginas = dadoNumeroDePaginas; }
   else
       throw string("O numero de paginas nao pode ser Menor ou igual a 0");
}
void Livro::setPreco(double dadoPreco){
    if(dadoPreco > 0) { preco = dadoPreco; }
    else
        throw string("O preco nao pode ser Menor ou igual a 0");
}


