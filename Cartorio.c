#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final do criação de variáveis/string
	
	printf("\t||| Cartório da EBAC ||| \n\n"); //Título
	printf("    Registrar nomes \n\n"); //Subtítulo
	
	printf("\t Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file;  //Acessar os arquivos
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: "); //Ajuste estético
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, "\nNome: "); //Ajuste estético
	fclose(file); //Fecha o arquivo
	
	printf("\t Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file,nome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, " "); //Ajuste estético
	fclose(file); //Fecha o arquivo
	
	printf("\t Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file,sobrenome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, "\nCargo: "); //Ajuste estético
	fclose(file); //Fecha o arquivo
	
	printf("\t Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file,cargo); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("\n\n"); //Ajuste estético
	system("pause"); //Pausar o sistema
}

int consulta() //Função responsavel por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//Final do criação de variáveis/string
	
	printf("\t||| Cartório da EBAC ||| \n\n"); //Título
	printf("    Consutar nomes \n\n"); //Subtítulo

	printf("\t Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;  //Acessar os arquivos
	file = fopen(cpf,"r"); //Ler o arquivo
	
	if(file == NULL) //Caso não haja arquivo com as informações solicitadas, faça
	{
		printf("\t Não foi possivel abrir o arquivo, não localizado!.");
	}

	else //Se houver um arquivo com as informações solicitadas, faça
		printf("\t Essas são as informações do usuário: ");
		printf("\n");
		
		while(fgets(conteudo, 200, file) != NULL) //Operador de repetição
		{
			printf("\t %s", conteudo);
		}	

	fclose(file); //Fecha o arquivo		
	printf("\n\n");
	system("pause"); //Pausar o sistema
}

int deletar() //Função responsavel por deletar os usuários no sistema
{
	printf("\t||| Cartório da EBAC ||| \n\n"); //Título
	printf("    Deletar nomes \n\n"); //Subtítulo
	
	//Inicio da criação de variáveis/string
	char cpf[40];
	//Final do criação de variáveis/string

	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informação do usuário
	scanf("%s",cpf);
	
	remove(cpf); //Deletar o arquivo
	
	FILE *file; //Acessar os arquivos
	file = fopen(cpf,"r"); //Ler o arquivo
	
	if(file == NULL) //Caso não haja arquivo com as informações solicitadas, faça
	{
		printf("\n");
		printf("O usuário não se encontra mais no sistema!. \n\n");
		system("pause");
	}
	
	fclose(file); //Fecha o arquivo

}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //Limpando os textos
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("\t||| Cartório da EBAC ||| \n\n"); //Inicio do menu
		printf("    Escolha a opção desejada do menu: \n\n");
		printf("\t 1 - Registrar nomes \n");
		printf("\t 2 - Consutar nomes \n");
		printf("\t 3 - Deletar nomes \n");
		printf("\t 4 - Sair do sistema \n\n");
		printf("    Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Amarzenando a escolha do usuário
	
		system("cls"); //Limpando os textos
		
		switch(opcao) //Inicio da seleção
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta(); //Chamada de funções
			break;
			
			case 3:
			deletar(); //Chamada de funções
			break;
			
			case 4:
			printf("\t||| Cartório da EBAC ||| \n\n");
			printf("    Obrigado por utilizar o sistema! \n");
			return 0; //Sair do sistema
			break;
			
			default:
			printf("\t||| Cartório da EBAC ||| \n\n");
			printf("    Essa opção não está disponivel! \n\n");
			system("pause");
			break;
					
		} //Fim da seleção
		
	}
}
