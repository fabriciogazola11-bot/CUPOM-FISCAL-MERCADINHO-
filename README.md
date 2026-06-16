# Mercadinho 6

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
