#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 1000
#define MAX_NOME 31
#define MAX_CUPONS 1000
#define MAX_ITENS_CUPOM 100

typedef struct {
    int codigo;
    long long preco; // centavos
    char nome[MAX_NOME];
    long long total_vendido;
} Produto;

typedef struct {
    int codigo;
    long long qtd;
} ItemCupom;

typedef struct {
    int n_itens;
    ItemCupom itens[MAX_ITENS_CUPOM];
} CupomFiscal;

Produto catalogo[MAX_PRODUTOS];
int n_produtos;

CupomFiscal cupons[MAX_CUPONS];
int n_cupons;

int busca(int codigo) {
    for (int i = 0; i < n_produtos; i++)
        if (catalogo[i].codigo == codigo)
            return i;
    return -1;
}

void nome_exibicao(char *dst, const char *src) {
    int i = 0, j = 0;

    while (src[i] && j < 20) {
        if (src[i] == '_')
            dst[j++] = ' ';
        else
            dst[j++] = src[i];
        i++;
    }

    dst[j] = '\0';
}

void formatar_preco(long long centavos, char *out) {
    long long reais = centavos / 100;
    long long cent = centavos % 100;
    if (cent < 0) cent = -cent;
    sprintf(out, "%lld,%02lld", reais, cent);
}

int cmp(const void *a, const void *b) {
    const Produto *pa = (const Produto *)a;
    const Produto *pb = (const Produto *)b;

    if (pa->total_vendido != pb->total_vendido)
        return (pb->total_vendido > pa->total_vendido) -
               (pb->total_vendido < pa->total_vendido);

    return pa->codigo - pb->codigo;
}

int main() {

    scanf("%d", &n_produtos);

    for (int i = 0; i < n_produtos; i++) {
        scanf("%d %lld %30s",
              &catalogo[i].codigo,
              &catalogo[i].preco,
              catalogo[i].nome);

        catalogo[i].total_vendido = 0;
    }

    scanf("%d", &n_cupons);

    for (int c = 0; c < n_cupons; c++) {
        scanf("%d", &cupons[c].n_itens);

        for (int i = 0; i < cupons[c].n_itens; i++) {
            scanf("%d %lld",
                  &cupons[c].itens[i].codigo,
                  &cupons[c].itens[i].qtd);
        }
    }

    // ================= CUPONS =================
    for (int c = 0; c < n_cupons; c++) {

        printf("=== CUPOM %04d ===\n", c + 1);

        long long total = 0;

        for (int i = 0; i < cupons[c].n_itens; i++) {

            int idx = busca(cupons[c].itens[i].codigo);
            if (idx == -1) continue;

            long long qtd = cupons[c].itens[i].qtd;
            long long subtotal = catalogo[idx].preco * qtd;

            catalogo[idx].total_vendido += qtd;
            total += subtotal;

            char nome[31], p1[40], p2[40];

            nome_exibicao(nome, catalogo[idx].nome);
            formatar_preco(catalogo[idx].preco, p1);
            formatar_preco(subtotal, p2);

            printf("%s %lldx R$ %s R$ %s\n",
                   nome, qtd, p1, p2);
        }

        char total_str[40];
        formatar_preco(total, total_str);

        printf("TOTAL R$ %s\n", total_str);
    }

    // ================= RANKING =================
    Produto v[MAX_PRODUTOS];
    int n = 0;

    for (int i = 0; i < n_produtos; i++)
        if (catalogo[i].total_vendido > 0)
            v[n++] = catalogo[i];

    qsort(v, n, sizeof(Produto), cmp);

    printf("=== MAIS VENDIDOS ===\n");

    int lim = (n < 3 ? n : 3);

    for (int i = 0; i < lim; i++) {

        char nome[31];
        nome_exibicao(nome, v[i].nome);

        printf("%do %s %lld un\n",
               i + 1, nome, v[i].total_vendido);
    }

    return 0;
}