#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final do cria��o de vari�veis/string
	
	printf("\t||| Cart�rio da EBAC ||| \n\n"); //T�tulo
	printf("    Registrar nomes \n\n"); //Subt�tulo
	
	printf("\t Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file;  //Acessar os arquivos
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file, "CPF: "); //Ajuste est�tico
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, "\nNome: "); //Ajuste est�tico
	fclose(file); //Fecha o arquivo
	
	printf("\t Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file,nome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, " "); //Ajuste est�tico
	fclose(file); //Fecha o arquivo
	
	printf("\t Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file,sobrenome); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file, "\nCargo: "); //Ajuste est�tico
	fclose(file); //Fecha o arquivo
	
	printf("\t Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo
	fprintf(file,cargo); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
	printf("\n\n"); //Ajuste est�tico
	system("pause"); //Pausar o sistema
}

int consulta() //Fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//Final do cria��o de vari�veis/string
	
	printf("\t||| Cart�rio da EBAC ||| \n\n"); //T�tulo
	printf("    Consutar nomes \n\n"); //Subt�tulo

	printf("\t Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;  //Acessar os arquivos
	file = fopen(cpf,"r"); //Ler o arquivo
	
	if(file == NULL) //Caso n�o haja arquivo com as informa��es solicitadas, fa�a
	{
		printf("\t N�o foi possivel abrir o arquivo, n�o localizado!.");
	}

	else //Se houver um arquivo com as informa��es solicitadas, fa�a
		printf("\t Essas s�o as informa��es do usu�rio: ");
		printf("\n");
		
		while(fgets(conteudo, 200, file) != NULL) //Operador de repeti��o
		{
			printf("\t %s", conteudo);
		}	

	fclose(file); //Fecha o arquivo		
	printf("\n\n");
	system("pause"); //Pausar o sistema
}

int deletar() //Fun��o responsavel por deletar os usu�rios no sistema
{
	printf("\t||| Cart�rio da EBAC ||| \n\n"); //T�tulo
	printf("    Deletar nomes \n\n"); //Subt�tulo
	
	//Inicio da cria��o de vari�veis/string
	char cpf[40];
	//Final do cria��o de vari�veis/string

	printf("\t Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	FILE *file;  //Acessar os arquivos
	file = fopen(cpf,"r"); //Ler o arquivo
	fclose(file); //Fecha o arquivo
	
	if(file != NULL) //Se houver um arquivo com as informa��es solicitadas, fa�a
	{
		FILE *file; //Acessar os arquivos
		remove(cpf); //Deletar o arquivo
		file = fopen(cpf,"r"); //Ler o arquivo
	
		if(file == NULL) //Se houver um arquivo com as informa��es solicitadas, fa�a
		{
			printf("\n\t O usu�rio n�o se encontra mais no sistema!. \n\n");
			fclose(file); //Fecha o arquivo
		}	
				
	}

	else //Caso n�o haja arquivo com as informa��es solicitadas, fa�a
		printf("\n\t N�o h� nenhum usu�rio com este CPF!. \n\n");
		system("pause");
		fclose(file); //Fecha o arquivo
	
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("\t||| Cart�rio da EBAC ||| \n\n");
	printf("    Login de adminstrador! \n\n\t Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls"); //Limpando os textos
		for(laco=1;laco=1;)
		{
		
			system("cls"); //Limpando os textos
		
			printf("\t||| Cart�rio da EBAC ||| \n\n"); //Inicio do menu
			printf("    Escolha a op��o desejada do menu: \n\n");
			printf("\t 1 - Registrar nomes \n");
			printf("\t 2 - Consutar nomes \n");
			printf("\t 3 - Deletar nomes \n");
			printf("\t 4 - Sair do sistema \n\n");
			printf("    Op��o: "); //Fim do menu
	
			scanf("%d", &opcao); //Amarzenando a escolha do usu�rio
	
			system("cls"); //Limpando os textos
			
			switch(opcao) //Inicio da sele��o
			{
				case 1:
				registro(); //Chamada de fun��es
				break;
	
				case 2:
				consulta(); //Chamada de fun��es
				break;
			
				case 3:
				deletar(); //Chamada de fun��es
				break;
		
				case 4:
				printf("\t||| Cart�rio da EBAC ||| \n\n");
				printf("    Obrigado por utilizar o sistema! \n");
				return 0; //Sair do sistema
				break;
				
				default:
				printf("\t||| Cart�rio da EBAC ||| \n\n");
				printf("    Essa op��o n�o est� disponivel! \n\n");
				system("pause");
				break;						
			} //Fim da sele��o	
		}
	}
	
	else
		system("cls"); //Limpando os textos
		printf("\t||| Cart�rio da EBAC ||| \n\n");
		printf("    Senha incorreta! \n");
	
}
