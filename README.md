# CUPOM Mercadinho 

Sistema desenvolvido em linguagem C para processamento de cupons fiscais, cálculo de vendas e geração de ranking dos produtos mais vendidos.

## Descrição

O programa lê um catálogo de produtos e uma sequência de cupons fiscais. Para cada cupom, calcula os subtotais dos itens, exibe o valor total da compra e, ao final, gera um ranking com os três produtos mais vendidos.

Os valores monetários são armazenados em centavos para evitar problemas de precisão com números de ponto flutuante.

---

## Funcionalidades

- Cadastro de produtos
- Leitura de cupons fiscais
- Busca de produtos pelo código
- Cálculo automático de subtotais
- Cálculo do total de cada compra
- Formatação de preços no padrão brasileiro
- Conversão automática de "_" para espaço nos nomes dos produtos
- Ranking dos produtos mais vendidos
- Ordenação por quantidade vendida

---

## Estruturas Utilizadas

### Produto

Armazena as informações dos produtos cadastrados.

```c
typedef struct {
    int codigo;
    long long preco;
    char nome[MAX_NOME];
    long long total_vendido;
} Produto;

typedef struct {
    int n_itens;
    ItemCupom itens[MAX_ITENS_CUPOM];
} CupomFiscal;



///EXEMPLOS DE ENTRADA
3
101 450 Cafe_Premium_Torrado_Moido
102 800 Acucar_Refinado
103 650 Leite_Integral

2

2
101 2
102 1

3
101 1
103 2
102 1


//EXEMPLOS DE SAIDA
=== CUPOM 0001 ===
Cafe Premium Torrad 2x R$ 4,50 R$ 9,00
Acucar Refinado 1x R$ 8,00 R$ 8,00
TOTAL R$ 17,00

=== CUPOM 0002 ===
Cafe Premium Torrad 1x R$ 4,50 R$ 4,50
Leite Integral 2x R$ 6,50 R$ 13,00
Acucar Refinado 1x R$ 8,00 R$ 8,00
TOTAL R$ 25,50

=== MAIS VENDIDOS ===
1o Cafe Premium Torrad 3 un
2o Acucar Refinado 2 un
3o Leite Integral 2 un

//Limitações
Máximo de 1000 produtos.
Máximo de 1000 cupons fiscais.
Máximo de 100 itens por cupom.
Nomes limitados a 30 caracteres.
Exibição limitada a 20 caracteres por produto.
