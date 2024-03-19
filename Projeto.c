#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EQUIPAMENTOS 100
#define MAX_PROFESSORES 100
#define MAX_RESERVAS 100

// Definição das estruturas de dados

// Estrutura para representar um equipamento audiovisual
typedef struct {
    int id;
    char nome[50];
    char tipo[50];
    bool disponivel;
} Equipamento;

// Estrutura para representar um professor ou coordenador
typedef struct {
    int id;
    char nome[50];
    char cargo[50];
} Professor;

// Estrutura para representar uma reserva de equipamento
typedef struct {
    int id;
    int idEquipamento;
    int idUsuario;
    char data[20];
    char horario[20];
} Reserva;

// Variáveis globais
Equipamento equipamentos[MAX_EQUIPAMENTOS];
Professor professores[MAX_PROFESSORES];
Reserva reservas[MAX_RESERVAS];
int numEquipamentos = 0;
int numProfessores = 0;
int numReservas = 0;

// Protótipos das funções
void cadastrarEquipamento();
void listarEquipamentos();
void cadastrarUsuario();
void listarUsuarios();
void fazerReserva();
void listarReservas();

// Função principal
int main() {
    int opcao;

    // Loop do menu principal
    while (1) {
        printf("\nSistema de Reserva de Equipamentos Audiovisuais\n");
        printf("1. Cadastrar Equipamento\n");
        printf("2. Listar Equipamentos\n");
        printf("3. Cadastrar Professor/Coordenador\n");
        printf("4. Listar Professores/Coordenadores\n");
        printf("5. Fazer Reserva\n");
        printf("6. Listar Reservas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarEquipamento();
                break;
            case 2:
                listarEquipamentos();
                break;
            case 3:
                cadastrarUsuario();
                break;
            case 4:
                listarUsuarios();
                break;
            case 5:
                fazerReserva();
                break;
            case 6:
                listarReservas();
                break;
            case 0:
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}

// Implementação das funções

void cadastrarEquipamento() {
    if (numEquipamentos >= MAX_EQUIPAMENTOS) {
        printf("Limite de equipamentos atingido!\n");
        return;
    }

    Equipamento novoEquipamento;
    novoEquipamento.id = numEquipamentos + 1;

    printf("Nome do equipamento: ");
    scanf("%s", novoEquipamento.nome);
    printf("Tipo do equipamento: ");
    scanf("%s", novoEquipamento.tipo);
    novoEquipamento.disponivel = true;

    equipamentos[numEquipamentos++] = novoEquipamento;
    printf("Equipamento cadastrado com sucesso!\n");
}

void listarEquipamentos() {
    printf("\nEquipamentos cadastrados:\n");
    for (int i = 0; i < numEquipamentos; i++) {
        printf("ID: %d\n", equipamentos[i].id);
        printf("Nome: %s\n", equipamentos[i].nome);
        printf("Tipo: %s\n", equipamentos[i].tipo);
        printf("Disponível: %s\n", equipamentos[i].disponivel ? "Sim" : "Não");
        printf("\n");
    }
}

void cadastrarUsuario() {
    if (numProfessores >= MAX_PROFESSORES) {
        printf("Limite de professores atingido!\n");
        return;
    }

    Professor novoProfessor;
    novoProfessor.id = numProfessores + 1;

    printf("Nome do professor: ");
    scanf("%s", novoProfessor.nome);
    printf("Cargo do professor: ");
    scanf("%s", novoProfessor.cargo);

    professores[numProfessores++] = novoProfessor;
    printf("Professor cadastrado com sucesso!\n");
}

void listarUsuarios() {
    printf("\nProfessores cadastrados:\n");
    for (int i = 0; i < numProfessores; i++) {
        printf("ID: %d\n", professores[i].id);
        printf("Nome: %s\n", professores[i].nome);
        printf("Cargo: %s\n", professores[i].cargo);
        printf("\n");
    }
}

void fazerReserva() {
    if (numReservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido!\n");
        return;
    }

    int idEquipamento, idUsuario;
    char data[20], horario[20];

    printf("ID do equipamento a ser reservado: ");
    scanf("%d", &idEquipamento);
    if (idEquipamento < 1 || idEquipamento > numEquipamentos) {
        printf("Equipamento nao encontrado!\n");
        return;
    }

    printf("ID do professor/coordenador que deseja reservar: ");
    scanf("%d", &idUsuario);
    if (idUsuario < 1 || idUsuario > numProfessores) {
        printf("Usuario nao encontrado!\n");
        return;
    }

    printf("Data da reserva (dd/mm/aaaa): ");
    scanf("%s", data);
    printf("Horario da reserva: ");
    scanf("%s", horario);

    Reserva novaReserva;
    novaReserva.id = numReservas + 1;
    novaReserva.idEquipamento = idEquipamento;
    novaReserva.idUsuario = idUsuario;
    strcpy(novaReserva.data, data);
    strcpy(novaReserva.horario, horario);

    reservas[numReservas++] = novaReserva;
    printf("Reserva realizada com sucesso!\n");
}

void listarReservas() {
    printf("\nReservas realizadas:\n");
    for (int i = 0; i < numReservas; i++) {
        printf("ID: %d\n", reservas[i].id);
        printf("Equipamento: %s\n", equipamentos[reservas[i].idEquipamento - 1].nome);
        printf("Usuario: %s\n", professores[reservas[i].idUsuario - 1].nome);
        printf("Data: %s\n", reservas[i].data);
        printf("Horario: %s\n", reservas[i].horario);
        printf("\n");
    }
}
