#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h>//biblioteca para aloca��o de espa�o de mem�ria 
#include <locale.h>//biblioteca de alica��es de texto por regi�o 
#include <string.h>//bliblioteca respos�vel por cuidar das strings

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	//In�cio cria��o de vari�veis/ strings
	char arquivo[40];
	char cpf[40]; 
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	//Final da cria��o de vari�veis/ strings	
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio 
	scanf("%s", cpf); //%s � usado para leitura de strings 
	
	strcpy(arquivo, cpf); // Respos�vel por copiar os valores das strings
	
	FILE *file; //Cria arquivo
	file = fopen(arquivo, "w");	//Abrir e ler o arquivo (w vem de "write") 
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
			
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletador: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
		
}

int main()
{
	int opcao=0;//Definir variavel
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	printf("\n");
	
	comparacao = strcmp(senhadigitada, "admin");//Usamos esta fun��o regida pela biblioteca para comparar na mem�ria a senha gravada e digitada
	
	if(comparacao == 0)
	{
		
		for(laco=1;laco=1;)
		{
		
			system("cls"); //Usamos este comando para apagar da tela tudo que veio anteriormente
	
			setlocale(LC_ALL, "Portuguese");//Definir a linguagem 
	
			printf("### Cart�rio da EBAC ### \n\n");//inicio do menu
		
			printf("Escolha a op��o desejada do menu: \n\n");
		
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema\n\n\n");
			printf("Op��o: ");//fim do menu
		
			scanf("%d", &opcao);//%d usamos para armazenar uma vari�vel do tipo inteiro atrav�s do usu�rio
		
			system("cls"); //usamos este comando para apagar da tela tudo que venio anteriormente
		
			switch(opcao)//inicio da sele��o do menu
			{
				case 1:
				registro();//Chamada de fun��es 
				break;
				
				case 2:	
				consulta();	
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
								
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			}//fim da selecao		
		}
	}
	
	else
		printf("Senha incorreta!");
}

